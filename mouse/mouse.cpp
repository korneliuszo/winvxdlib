/*
 * mouse.cpp
 *
 *  Created on: Jul 16, 2023
 *      Author: Korneliusz Osmenda
 */

#include "mouse.hpp"
#include <vmm.hpp>
#include <gcc.h>
#include <stdbool.h>
#include <dev_vxd_dev_vmm.h>
#include <vxdcall.hpp>
#include <stdio.h>
#include <cwrap.hpp>

bool Mouse::Init(uint32_t sysVM, uint32_t crs)
{
	volatile Client_Reg_Struc *pCRS = (Client_Reg_Struc *)crs;

	Client_Reg_Struc save;
	Save_Client_State(&save);
	Begin_Nest_Exec();

	pCRS->Client_EAX = 0x1607;
	pCRS->Client_EBX = 0xC;
	pCRS->Client_ECX = 0x1;
	Exec_Int(0x2F);

	bool exists = (pCRS->Client_EAX == 0);

	I33_Win_API_Seg = pCRS->Client_DS&0xFFFF;
	I33_Win_API_Off = pCRS->Client_ESI & 0xFFFF;
	End_Nest_Exec();
	Restore_Client_State(&save);
	VMD_Owner = sysVM;

	return exists;
}

void Mouse::Focus(uint32_t VID, uint32_t flags, uint32_t VM)
{
	if((VID != 0) && (VID != (uint32_t)Device_ID::VMD_Device_ID))
		return;
	VMD_Owner = VM;
	sizex=0;
}

bool Mouse::do_setting(uint32_t crs)
{
	volatile Client_Reg_Struc *pCRS = (Client_Reg_Struc *)crs;

#ifndef NDEBUG
	//Out_Debug_String("do_setting ENTER\r\n");
#endif

	if(!sizex)
	{
		Client_Reg_Struc save;
		Save_Client_State(&save);
		Begin_Nest_Exec();

		pCRS->Client_EAX = 0x0026;
		pCRS->Client_ECX = 0;
		pCRS->Client_EDX = 0;
		pCRS->Client_EBX = -1;

		Exec_Int(0x33);

		sizex=(pCRS->Client_ECX&0xffff);
		sizey=(pCRS->Client_EDX&0xffff);

		End_Nest_Exec();
		Restore_Client_State(&save);
#ifndef NDEBUG
		char buff[30];
		snprintf(buff,30,"MOUSE reg: %d %d\r\n",sizex,sizey);
		Out_Debug_String(buff);
#endif
	}

#ifndef NDEBUG
	if(0)
	{
		char buff[30];
		snprintf(buff,30,"MOUSE c: %d\r\n",mouseclicked);
		Out_Debug_String(buff);
	}
#endif

	Client_Reg_Struc save;
	Save_Client_State(&save);

	Begin_Nest_V86_Exec();

	pCRS->Client_EAX = 1;
	pCRS->Client_EDX = mouseclicked ? 1 : 0;
	pCRS->Client_ESI = 0;
	pCRS->Client_EBX = (mouseposx*(sizex+1))>>16;
	pCRS->Client_ECX = (mouseposy*(sizey+1))>>16;

	Simulate_Far_Call(I33_Win_API_Seg, I33_Win_API_Off);
	Resume_Exec();
	End_Nest_Exec();
	Restore_Client_State(&save);
	if(callingvm != Get_Cur_VM_Handle())
		Resume_VM(callingvm);

#ifndef NDEBUG
	//Out_Debug_String("do_setting EXIT\r\n");
#endif
	return 1;
}


void Mouse::Set_Mouse_Position(uint32_t crs, uint16_t x, uint16_t y, bool clicked)
{
#ifndef NDEBUG
	//Out_Debug_String("set_pos ENTER\r\n");
#endif
	Begin_Critical_Section(0);
#ifndef NDEBUG
	//Out_Debug_String("set_pos LOCK\r\n");
#endif
	mouseposx = x;
	mouseposy = y;
	mouseclicked = clicked;
	callingvm = Get_Cur_VM_Handle();
#ifndef NDEBUG
	//Out_Debug_String("set_pos PREWAIT\r\n");
#endif
	if (VMD_Owner != Get_Cur_VM_Handle())
	{
		Call_Priority_VM_Event(
				High_Pri_Device_Boost,
				VMD_Owner,
				PEF_Wait_Not_Crit | PEF_Wait_For_STI,
				this,
				(const void *)single_vxd_control_hanlder<
					Cwrap<Mouse,&Mouse::do_setting,bool,uint32_t>,
					'd','B'>,
				0);
		End_Crit_And_Suspend();
	}
	else
	{
		do_setting(crs);
		End_Critical_Section();
	}

#ifndef NDEBUG
	//Out_Debug_String("set_pos EXIT\r\n");
#endif
}
