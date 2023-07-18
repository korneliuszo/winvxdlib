/*
 * vmm.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#include <vmm.hpp>
#include <vxdcall.hpp>


/* These magic symbols are provided by the linker.  */
extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
//extern void (*__fini_array_start []) (void) __attribute__((weak));
//extern void (*__fini_array_end []) (void) __attribute__((weak));

[[gnu::weak]] void Crit_Init(void){};

static bool Sys_Critical_Init(uint32_t sys_VM,uint32_t ref, uint32_t CmdTail, uint32_t pCRS)
{
	long i, count;

	count = __init_array_end - __init_array_start;
	for (i = 0; i < count; i++)
		__init_array_start[i] ();

	Crit_Init();

	return true;
}

[[gnu::section(".vxd_control_end"), gnu::used]]
static Control_callback footer_hndlr = { 0xFFFFFFFF, nullptr};

[[gnu::section(".vxd_control"), gnu::used]]
static const Control_callback ahndlr =
		Init_Control_callback
		<System_Control::Sys_Critical_Init,Sys_Critical_Init,'b','d','S','B'>();
