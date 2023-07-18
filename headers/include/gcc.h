/*
 * gcc.h
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#ifndef HEADERS_GCC_H_
#define HEADERS_GCC_H_

#define DLL_PUBLIC __attribute__ ((visibility ("default")))

#define VXD_STRINGIFY2(x)   #x
#define VXD_STRINGIFY(x)    VXD_STRINGIFY2(x)

#define VXD_AsmCall(dev,srv) \
        "int    $0x20\n"                                                        \
        ".word  " VXD_STRINGIFY(srv) "\n"                                       \
        ".word  " VXD_STRINGIFY(dev) "\n"

#if (__GNUC__ >= 6 && __GNUC_MINOR__ >= 1) || (__GNUC__ >= 7)
# define GCC_INLINE_ASM_SUPPORTS_cc_OUTPUT
#endif

#define __asm__ asm volatile

typedef uint32_t vxd_vm_handle_t;

typedef uint32_t vxd_semaphore_handle_t;

typedef uint32_t vxd_global_event_handle_t;
typedef uint32_t vxd_vm_event_handle_t;
typedef uint32_t vxd_priority_vm_event_handle_t;

typedef uint32_t vxd_timeout_handle_t;

#endif /* HEADERS_GCC_H_ */
