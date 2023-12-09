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

template<class C, auto F,typename rettype, typename ...Args>
static rettype Cwrapp(void* cobj, Args...args)
{
    C* obj = (C*)cobj;
    return (obj->*F)(args...);
}

template<typename rettype, typename ...Args>
class Ccallback
{
public:
	rettype (*callback)(void* obj, Args...);
	void* obj;
	rettype call(Args... args)
	{
		if (callback)
			return callback(obj,args...);
		return rettype{};
	}
};

#endif /* _CWRAP_HPP_ */
