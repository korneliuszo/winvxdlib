/*
 * vmm.hpp
 *
 *  Created on: Jun 24, 2023
 *      Author: kosa
 */

#ifndef HEADERS_VMM_HPP_
#define HEADERS_VMM_HPP_

#include <stdint.h>
#include <type_traits>
#include <tuple>
#include <string>

enum class Device_ID : uint32_t
{
	Undefined_Device_ID     =   0x00000,
	VMM_Device_ID           =   0x00001,
	Debug_Device_ID         =   0x00002,
	VPICD_Device_ID 		=   0x00003,
	VDMAD_Device_ID 		=	0x00004,
	VTD_Device_ID			=	0x00005,
	V86MMGR_Device_ID		=	0x00006,
	PageSwap_Device_ID		=	0x00007,
	Parity_Device_ID		=	0x00008,
	Reboot_Device_ID		=	0x00009,
	VDD_Device_ID			=	0x0000A,
	VSD_Device_ID			=	0x0000B,
	VMD_Device_ID			=	0x0000C,
	VKD_Device_ID			=	0x0000D,
	VCD_Device_ID			=	0x0000E,
	VPD_Device_ID			=	0x0000F,
	BlockDev_Device_ID		=	0x00010,
	VMCPD_Device_ID 		=	0x00011,
	EBIOS_Device_ID 		=	0x00012,
	BIOSXlat_Device_ID		=	0x00013,
	VNETBIOS_Device_ID		=	0x00014,
	DOSMGR_Device_ID		=	0x00015,
	WINLOAD_Device_ID		=	0x00016,
	SHELL_Device_ID 		=	0x00017,
	VMPoll_Device_ID		=	0x00018,
	VPROD_Device_ID 		=	0x00019,
	DOSNET_Device_ID		=	0x0001A,
	VFD_Device_ID			=	0x0001B,
	VDD2_Device_ID			=	0x0001C,	// Secondary display adapter
	WINDEBUG_Device_ID		=	0x0001D,
	TSRLoad_Device_ID		=	0x0001E,	// TSR instance utility ID
	BiosHook_Device_ID		=	0x0001F,	// Bios interrupt hooker VxD
	Int13_Device_ID 		=	0x00020,
	PageFile_Device_ID		=	0x00021,	// Paging File device
	SCSI_Device_ID			=   0x00022,  // SCSI device
	MCA_POS_Device_ID		=   0x00023,  // MCA_POS device
	SCSIFD_Device_ID		=	0x00024,	// SCSI FastDisk device
	VPEND_Device_ID 		=	0x00025,	// Pen device
	APM_Device_ID			=	0x00026,	// Power Management device
};

enum class Init_Order : uint32_t {
	VMM_Init_Order			= 0x000000000,
	APM_Init_Order			= 0x001000000,
	Debug_Init_Order		= 0x004000000,
	BiosHook_Init_Order		= 0x006000000,
	VPROD_Init_Order		= 0x008000000,
	VPICD_Init_Order		= 0x00C000000,
	VTD_Init_Order			= 0x014000000,
	PageFile_Init_Order		= 0x018000000,
	PageSwap_Init_Order		= 0x01C000000,
	Parity_Init_Order		= 0x020000000,
	Reboot_Init_Order		= 0x024000000,
	EBIOS_Init_Order		= 0x026000000,
	VDD_Init_Order			= 0x028000000,
	VSD_Init_Order			= 0x02C000000,
	VCD_Init_Order			= 0x030000000,
	VMD_Init_Order			= 0x034000000,
	VKD_Init_Order			= 0x038000000,
	VPD_Init_Order			= 0x03C000000,
	BlockDev_Init_Order		= 0x040000000,
	MCA_POS_Init_Order		= 0x041000000,
	SCSIFD_Init_Order		= 0x041400000,
	SCSIMaster_Init_Order	= 0x041800000,
	Int13_Init_Order		= 0x042000000,
	VFD_Init_Order			= 0x044000000,
	VMCPD_Init_Order		= 0x048000000,
	BIOSXlat_Init_Order		= 0x050000000,
	VNETBIOS_Init_Order		= 0x054000000,
	DOSMGR_Init_Order		= 0x058000000,
	DOSNET_Init_Order		= 0x05C000000,
	WINLOAD_Init_Order		= 0x060000000,
	VMPoll_Init_Order		= 0x064000000,

	Undefined_Init_Order	= 0x080000000,

	WINDEBUG_Init_Order		= 0x081000000,
	VDMAD_Init_Order		= 0x090000000,
	V86MMGR_Init_Order		= 0x0A0000000,
	SHELL_Init_Order		= 0x0B0000000,
};

struct [[gnu::packed]] DDB
{
	uint32_t DDB_Next;
	uint16_t DDB_SDK_Version;
	uint16_t DDB_Req_Device_Number;
	uint8_t DDB_Dev_Major_Version;
	uint8_t DDB_Dev_Minor_Version;
	uint16_t DDB_Flags;
	char DDB_Name[8];
	uint32_t DDB_Init_Order;
	uint32_t DDB_Control_Proc;
	uint32_t DDB_V86_API_Proc;
	uint32_t DDB_PM_API_Proc;
	uint32_t DDB_V86_API_CSIP;
	uint32_t DDB_PM_API_CSIP;
	uint32_t DDB_Reference_Data;
	uint32_t DDB_Service_Table_Ptr;
	uint32_t DDB_Service_Table_Size;
};

enum class System_Control : uint32_t {
	Sys_Critical_Init = 0x0000,
	Device_Init = 0x001,
	Init_Complete = 0x0002,
	Sys_VM_Init = 0x0003,
	Sys_VM_Terminate = 0x0004,
	System_Exit = 0x0005,
	Sys_Critical_Exit = 0x0006,
	Create_VM = 0x0007,
	VM_Critical_Init = 0x0008,
	VM_Init = 0x0009,
	VM_Terminate = 0x000A,
	VM_Not_Executeable = 0x000B,
	Destroy_VM = 0x000C,
	VM_Suspend = 0x000D,
	VM_Resume = 0x000E,
	Set_Device_Focus = 0x000F,
	Begin_Message_Mode = 0x0010,
	End_Message_Mode = 0x0011,
	Reboot_Processor = 0x0012,
	Query_Destroy = 0x0013,
	Debug_Query = 0x0014,
	Begin_PM_App = 0x0015,
	End_PM_App = 0x0016,
	Device_Reboot_Notify = 0x0017,
	Crit_Reboot_Notify = 0x0018,
	Close_VM_Notify = 0x0019,
	Power_Event = 0x001A,
};

extern "C"
void vxd_control_proc();

consteval DDB Init_DDB(Device_ID devid,
		uint8_t major, uint8_t minor, std::string name,
		Init_Order order)
{
	DDB ret = {
		.DDB_Next = 0,
		.DDB_SDK_Version = 0x30A, // win 3.10
		.DDB_Req_Device_Number = (uint16_t)devid,
		.DDB_Dev_Major_Version = major,
		.DDB_Dev_Minor_Version = minor,
		.DDB_Flags = 0,
		.DDB_Name = {},
		.DDB_Init_Order = (uint32_t)order,
		.DDB_Control_Proc = (uint32_t)vxd_control_proc,
		.DDB_V86_API_Proc = 0,
		.DDB_PM_API_Proc = 0,
		.DDB_V86_API_CSIP = 0,
		.DDB_PM_API_CSIP = 0,
		.DDB_Reference_Data = 0,
		.DDB_Service_Table_Ptr = 0,
		.DDB_Service_Table_Size = 0,
	};
	name.copy(ret.DDB_Name,8);
	return ret;
}

template<typename T>
struct function_traits;

template< typename Return, typename...Args>
struct function_traits<Return(*)(Args...)>{
     using return_type = Return;
     using args_tuple = std::tuple<Args...>;
};

template <typename T, typename Tuple>
struct has_type;

template <typename T, typename... Us>
struct has_type<T, std::tuple<Us...>> : std::conjunction<std::is_same<T, Us>...> {};

namespace REG
{
	template<char REG>
	[[gnu::always_inline]] inline void push();
	template<>
	[[gnu::always_inline]]
	inline void push<'a'>()
	{
		asm volatile ("push %eax");
	}
	template<>
	[[gnu::always_inline]]
	inline void push<'b'>()
	{
		asm volatile ("push %ebx");
	}
	template<>
	[[gnu::always_inline]]
	inline void push<'d'>()
	{
		asm volatile ("push %edx");
	}
	template<>
	[[gnu::always_inline]]
	inline void push<'S'>()
	{
		asm volatile ("push %esi");
	}
	template<>
	[[gnu::always_inline]]
	inline void push<'B'>()
	{
		asm volatile ("push %ebp");
	}

	template <char... Args>
	struct Pusher;

	template <>
	struct Pusher<> {
		[[gnu::always_inline]]
		inline static void pusher() {}
	};

	template <char T, char... Args>
	struct Pusher<T, Args...> {
		[[gnu::always_inline]]
		inline static void pusher() {
	        Pusher<Args...>::pusher();
	        push<T>();
	    }
	};
}

template <auto fn, char... REGS>
[[gnu::naked]]
void vxd_control_hanlder()
{
	using args_tuple = typename function_traits<decltype(fn)>::args_tuple;
    static_assert(std::tuple_size_v<args_tuple> == sizeof...(REGS));
    static_assert(std::is_same<typename function_traits<decltype(fn)>::return_type,bool>::value);
	static_assert(has_type<uint32_t,args_tuple>::value);

	REG::Pusher<REGS...>::pusher();

	asm volatile("call %P0"::"i"(fn));
	asm volatile("add %0, %%esp"::"i"(sizeof...(REGS)*4));
	asm volatile("ret");
}

struct [[gnu::packed]] Control_callback{
	uint32_t sys_control;
	void (*handler)();
};

template <System_Control id, auto fn, char... REGS>
consteval Control_callback Init_Control_callback()
{
	Control_callback ret =
	{
			.sys_control = (uint32_t)id,
			.handler = vxd_control_hanlder<fn,REGS...>,
	};
	return ret;
}

void Crit_Init(void);

#endif /* HEADERS_VMM_HPP_ */
