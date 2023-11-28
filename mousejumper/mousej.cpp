/*
 * hello.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#include <vmm.hpp>
#include <gcc.h>
#include <stdbool.h>
#include <dev_vxd_dev_vmm.h>
#include <vxdcall.hpp>
#include <stdio.h>

#include <mouse.hpp>

extern "C"
[[gnu::section(".ddb"), gnu::used, gnu::visibility ("default")]]
const DDB DDB = Init_DDB(Device_ID::Undefined_Device_ID,
		1, 0, "MOUSEJ", Init_Order::Undefined_Init_Order);

Mouse mouse;


bool timeout(uint32_t crs)
{
	struct {
		uint16_t x;
		uint16_t y;
	} const positions[]={
			{0x1000,0x1000},
			{0xf000,0x1000},
			{0xf000,0xf000},
			{0x1000,0xf000}
	};
	static int seq = 0;
	if(++seq == (sizeof(positions)/sizeof(*positions)))
		seq = 0;
	mouse.Set_Mouse_Position(crs, positions[seq].x, positions[seq].y);

	Set_Global_Time_Out(2000, 0,
			(const void *)single_vxd_control_hanlder<
			timeout,'B'>);
	return 1;
}


bool Device_Init(uint32_t cmdtail, uint32_t sysVM, uint32_t crs)
{
	bool exists = mouse.Init(sysVM, crs);
	if(exists)
		Set_Global_Time_Out(2000, 0,
				(const void *)single_vxd_control_hanlder<
				timeout,'B'>);
	return exists;
}

bool Focus(uint32_t VID, uint32_t flags, uint32_t VM, uint32_t crs)
{
	mouse.Focus(VID, flags, VM);
	return 1;
}

void Crit_Init(){
	Out_Debug_String("Hello from gcc\r\n");
}
[[gnu::section(".vxd_control"), gnu::used]]
static const Control_callback ahndlr =
		Init_Control_callback
		<System_Control::Device_Init,Device_Init,'S','b','B'>();


[[gnu::section(".vxd_control"), gnu::used]]
static const Control_callback bhndlr =
		Init_Control_callback
		<System_Control::Set_Device_Focus,Focus,'d','S','b','B'>();
