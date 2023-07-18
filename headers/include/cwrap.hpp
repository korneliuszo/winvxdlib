/*
 * cwrap.hpp
 *
 *  Created on: 4 sty 2023
 *      Author: nyuu
 */

#ifndef _CWRAP_HPP_
#define _CWRAP_HPP_

#include <stdint.h>

template<class C, auto F,typename rettype, typename ...Args>
static rettype Cwrap(uintptr_t cobj, Args...args)
{
    C* obj = (C*)cobj;
    return (obj->*F)(args...);
}

#endif /* _CWRAP_HPP_ */
