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

class Mouse {

	uint16_t I33_Win_API_Seg;
	uint16_t I33_Win_API_Off;
	uint32_t VMD_Owner;
	uint16_t sizex;
	uint16_t sizey;
	volatile uint16_t mouseposx;
	volatile uint16_t mouseposy;
	volatile bool mouseclicked;
	vxd_semaphore_handle_t shandle;
	vxd_semaphore_handle_t rhandle;
	bool do_setting(uint32_t crs);
public:
	bool Init(uint32_t sysVM, uint32_t crs);
	void Focus(uint32_t VID, uint32_t flags, uint32_t VM);
	void Set_Mouse_Position(uint16_t x, uint16_t y, bool clicked = false);
};







#endif /* MOUSE_MOUSE_HPP_ */
