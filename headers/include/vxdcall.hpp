/*
 * vxdcall.hpp
 *
 *  Created on: Jun 26, 2023
 *      Author: kosa
 */

#ifndef HEADERS_INCLUDE_VXDCALL_HPP_
#define HEADERS_INCLUDE_VXDCALL_HPP_


static inline void Out_Debug_String(const char * str)
{
	asm volatile (
			"pushf\n\t"
			"pusha\n\t"
			"int $0x20\n\t"
			".word 0x00c2\n\t"
			".word 0x0001\n\t"
			"popa\n\t"
			"popf\n\t"
			: : "S"(str)
	);

}






#endif /* HEADERS_INCLUDE_VXDCALL_HPP_ */
