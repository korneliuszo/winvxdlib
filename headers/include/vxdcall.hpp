/*
 * vxdcall.hpp
 *
 *  Created on: Jun 26, 2023
 *      Author: kosa
 */

#ifndef HEADERS_INCLUDE_VXDCALL_HPP_
#define HEADERS_INCLUDE_VXDCALL_HPP_

#include <stdint.h>

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


static inline uint64_t VTD_Get_Real_Time()
{
	uint32_t hi,lo;
	asm volatile (
			"pushf\n\t"
			"int $0x20\n\t"
			".word 0x0007\n\t"
			".word 0x0005\n\t"
			"popf\n\t"
			: "=edx"(hi),"=eax"(lo)
	);
	return (((uint64_t)hi)<<32) | lo;
}



#endif /* HEADERS_INCLUDE_VXDCALL_HPP_ */
