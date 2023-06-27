/*
 * hello.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#include <vmm.hpp>

extern "C"
[[gnu::section(".ddb"), gnu::used, gnu::visibility ("default")]]
const DDB DDB = Init_DDB(Device_ID::Undefined_Device_ID,
		1, 0, "HELLO", Init_Order::Undefined_Init_Order);
