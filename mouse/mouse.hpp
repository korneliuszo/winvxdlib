/*
 * mouse.hpp
 *
 *  Created on: Jul 16, 2023
 *      Author: Korneliusz Osmenda
 */

#ifndef MOUSE_MOUSE_HPP_
#define MOUSE_MOUSE_HPP_

#include <stdint.h>
#include <vmm.hpp>
#include <gcc.h>
#include <cwrap.hpp>

class Mouse {

	uint16_t I33_Win_API_Seg;
	uint32_t I33_Win_API_Off;
	uint32_t VMD_Owner;
	uint16_t sizex;
	uint16_t sizey;
	uint16_t mouseposx;
	uint16_t mouseposy;
	uint8_t mouseclicked;
	Ccallback<void> mousecallback;
	vxd_priority_vm_event_handle_t vm_event;
	bool do_setting(uint32_t crs);
public:
	bool Init(uint32_t sysVM, uint32_t crs);
	void Focus(uint32_t VID, uint32_t flags, uint32_t VM);
	void Set_Mouse_Position(const Ccallback<void> &callback, uint16_t x, uint16_t y, uint8_t clicked = 0x00);
};







#endif /* MOUSE_MOUSE_HPP_ */
