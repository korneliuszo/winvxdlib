/*
 * vmm.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#include <vmm.hpp>
#include <vxdcall.hpp>

static bool Sys_Critical_Init(uint32_t sys_VM,uint32_t ref, uint32_t CmdTail, uint32_t pCRS)
{
	Out_Debug_String("Hello from gcc\r\n");
	return true;
}

[[gnu::section(".vxd_control_end"), gnu::used]]
static Control_callback footer_hndlr = { 0xFFFFFFFF, nullptr};

[[gnu::section(".vxd_control"), gnu::used]]
static const Control_callback ahndlr =
		Init_Control_callback
		<System_Control::Sys_Critical_Init,Sys_Critical_Init,'b','d','S','B'>();
