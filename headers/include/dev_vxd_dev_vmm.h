/* auto-generated from dev_vxd_dev_vmm.vxddef, do not edit. */

/* Windows Virtual Machine Manager                                                 */
/*                                                                                 */
/* This is "built in" to the kernel and is a core device of the Windows system.    */
/*                                                                                 */
/* File location (Windows 3.0/3.1): C:\WINDOWS\SYSTEM\WIN386.EXE                   */
/* File location (Windows 95/98/ME): C:\WINDOWS\SYSTEM\VMM32.VXD                   */
/*                                                                                 */
/* Note that in both cases, the VMM does not exist as a standalone VxD device      */
/* but as code "built in" to the Windows kernel. VMM32.VXD and WIN386.EXE are      */
/* executables containing the kernel and a packed structure containing the         */
/* VxD device drivers in a "pre-digested" form. The VxD drivers contained within   */
/* do not contain the MS-DOS header, but start with the LE header. The LE header   */
/* is modified slightly to change one of the fields to instead indicate resident   */
/* length. This packed structure is known as 'W3' and 'W4', referring to the       */
/* extended header pointed to by the MS-DOS header. The 'W3' header is merely      */
/* a list of the VxDs and where they exist elsewhere in the same EXE               */
/* (Windows 3.0/3.1). The 'W4' header is the same format, but with compression     */
/* applied to any part of the EXE past the W4 header to compress both the list     */
/* and the VxDs contained elsewhere (Windows 95/98/ME). These built-in VxDs        */
/* provide both core devices as well as the "base drivers" that allow Windows      */
/* to function in the absence of external VxD drivers. Such drivers can be         */
/* referenced in SYSTEM.INI as "device=*vxdname" rather than "device=VXDFILE.VXD". */
/*                                                                                 */
/* For more information on the W3 and W4 formats, see DOSLIB tools:                */
/* - tool/w3list.pl (show contents of W3 header)                                   */
/* - tool/w3extract.pl (extract devices from W3 pack)                              */
/* - tool/w4tow3/w4tow3.c (decompress/convert W4 to W3 format)                     */
/*                                                                                 */
/* References:                                                                     */
/*                                                                                 */
/* * Windows 3.1 DDK (CD-ROM drive D) D:\386\INCLUDE\VMM.INC                       */
/* - "VMM.INC - Include file for Virtual Machine Manager"                          */
/* - "Version 1.00 - 05-May-1988 - By RAL"                                         */
/*                                                                                 */
/* * Windows 95 DDK (installed in C:\DDK95) C:\DDK95\INC32\VMM.INC                 */
/* - (C) 1993-1995 Microsoft                                                       */
/*                                                                                 */
/* * Windows Undocumented File Formats - Working Inside 16- and 32-bit Windows     */
/* - Pete Davis and Mike Wallace                                                   */
/* - R&D Books (C) 1997                                                            */
/*                                                                                 */
/* This DOSLIB header file (C) 2016-2017 Jonathan Campbell                         */

/* VXD device ID. Combine with service call ID when using VMMCall/VMMJmp */
#define VMM_Device_ID                                    0x0001

/* VXD services (total: 435, 0x01B2) */
#define VMM_snr_Get_VMM_Version                              0x0000    /* ver 3.0+ */
#define VMM_snr_Get_Cur_VM_Handle                            0x0001    /* ver 3.0+ */
#define VMM_snr_Test_Cur_VM_Handle                           0x0002    /* ver 3.0+ */
#define VMM_snr_Get_Sys_VM_Handle                            0x0003    /* ver 3.0+ */
#define VMM_snr_Test_Sys_VM_Handle                           0x0004    /* ver 3.0+ */
#define VMM_snr_Validate_VM_Handle                           0x0005    /* ver 3.0+ */
#define VMM_snr_Get_VMM_Reenter_Count                        0x0006    /* ver 3.0+ */
#define VMM_snr_Begin_Reentrant_Execution                    0x0007    /* ver 3.0+ */
#define VMM_snr_End_Reentrant_Execution                      0x0008    /* ver 3.0+ */
#define VMM_snr_Install_V86_Break_Point                      0x0009    /* ver 3.0+ */
#define VMM_snr_Remove_V86_Break_Point                       0x000A    /* ver 3.0+ */
#define VMM_snr_Allocate_V86_Call_Back                       0x000B    /* ver 3.0+ */
#define VMM_snr_Allocate_PM_Call_Back                        0x000C    /* ver 3.0+ */
#define VMM_snr_Call_When_VM_Returns                         0x000D    /* ver 3.0+ */
#define VMM_snr_Schedule_Global_Event                        0x000E    /* ver 3.0+ */
#define VMM_snr_Schedule_VM_Event                            0x000F    /* ver 3.0+ */
#define VMM_snr_Call_Global_Event                            0x0010    /* ver 3.0+ */
#define VMM_snr_Call_VM_Event                                0x0011    /* ver 3.0+ */
#define VMM_snr_Cancel_Global_Event                          0x0012    /* ver 3.0+ */
#define VMM_snr_Cancel_VM_Event                              0x0013    /* ver 3.0+ */
#define VMM_snr_Call_Priority_VM_Event                       0x0014    /* ver 3.0+ */
#define VMM_snr_Cancel_Priority_VM_Event                     0x0015    /* ver 3.0+ */
#define VMM_snr_Get_NMI_Handler_Addr                         0x0016    /* ver 3.0+ */
#define VMM_snr_Set_NMI_Handler_Addr                         0x0017    /* ver 3.0+ */
#define VMM_snr_Hook_NMI_Event                               0x0018    /* ver 3.0+ */
#define VMM_snr_Call_When_VM_Ints_Enabled                    0x0019    /* ver 3.0+ */
#define VMM_snr_Enable_VM_Ints                               0x001A    /* ver 3.0+ */
#define VMM_snr_Disable_VM_Ints                              0x001B    /* ver 3.0+ */
#define VMM_snr_Map_Flat                                     0x001C    /* ver 3.0+ */
#define VMM_snr_Map_Lin_To_VM_Addr                           0x001D    /* ver 3.0+ */
#define VMM_snr_Adjust_Exec_Priority                         0x001E    /* ver 3.0+ */
#define VMM_snr_Begin_Critical_Section                       0x001F    /* ver 3.0+ */
#define VMM_snr_End_Critical_Section                         0x0020    /* ver 3.0+ */
#define VMM_snr_End_Crit_And_Suspend                         0x0021    /* ver 3.0+ */
#define VMM_snr_Claim_Critical_Section                       0x0022    /* ver 3.0+ */
#define VMM_snr_Release_Critical_Section                     0x0023    /* ver 3.0+ */
#define VMM_snr_Call_When_Not_Critical                       0x0024    /* ver 3.0+ */
#define VMM_snr_Create_Semaphore                             0x0025    /* ver 3.0+ */
#define VMM_snr_Destroy_Semaphore                            0x0026    /* ver 3.0+ */
#define VMM_snr_Wait_Semaphore                               0x0027    /* ver 3.0+ */
#define VMM_snr_Signal_Semaphore                             0x0028    /* ver 3.0+ */
#define VMM_snr_Get_Crit_Section_Status                      0x0029    /* ver 3.0+ */
#define VMM_snr_Call_When_Task_Switched                      0x002A    /* ver 3.0+ */
#define VMM_snr_Suspend_VM                                   0x002B    /* ver 3.0+ */
#define VMM_snr_Resume_VM                                    0x002C    /* ver 3.0+ */
#define VMM_snr_No_Fail_Resume_VM                            0x002D    /* ver 3.0+ */
#define VMM_snr_Nuke_VM                                      0x002E    /* ver 3.0+ */
#define VMM_snr_Crash_Cur_VM                                 0x002F    /* ver 3.0+ */
#define VMM_snr_Get_Execution_Focus                          0x0030    /* ver 3.0+ */
#define VMM_snr_Set_Execution_Focus                          0x0031    /* ver 3.0+ */
#define VMM_snr_Get_Time_Slice_Priority                      0x0032    /* ver 3.0+ */
#define VMM_snr_Set_Time_Slice_Priority                      0x0033    /* ver 3.0+ */
#define VMM_snr_Get_Time_Slice_Granularity                   0x0034    /* ver 3.0+ */
#define VMM_snr_Set_Time_Slice_Granularity                   0x0035    /* ver 3.0+ */
#define VMM_snr_Get_Time_Slice_Info                          0x0036    /* ver 3.0+ */
#define VMM_snr_Adjust_Execution_Time                        0x0037    /* ver 3.0+ */
#define VMM_snr_Release_Time_Slice                           0x0038    /* ver 3.0+ */
#define VMM_snr_Wake_Up_VM                                   0x0039    /* ver 3.0+ */
#define VMM_snr_Call_When_Idle                               0x003A    /* ver 3.0+ */
#define VMM_snr_Get_Next_VM_Handle                           0x003B    /* ver 3.0+ */
#define VMM_snr_Set_Global_Time_Out                          0x003C    /* ver 3.0+ */
#define VMM_snr_Set_VM_Time_Out                              0x003D    /* ver 3.0+ */
#define VMM_snr_Cancel_Time_Out                              0x003E    /* ver 3.0+ */
#define VMM_snr_Get_System_Time                              0x003F    /* ver 3.0+ */
#define VMM_snr_Get_VM_Exec_Time                             0x0040    /* ver 3.0+ */
#define VMM_snr_Hook_V86_Int_Chain                           0x0041    /* ver 3.0+ */
#define VMM_snr_Get_V86_Int_Vector                           0x0042    /* ver 3.0+ */
#define VMM_snr_Set_V86_Int_Vector                           0x0043    /* ver 3.0+ */
#define VMM_snr_Get_PM_Int_Vector                            0x0044    /* ver 3.0+ */
#define VMM_snr_Set_PM_Int_Vector                            0x0045    /* ver 3.0+ */
#define VMM_snr_Simulate_Int                                 0x0046    /* ver 3.0+ */
#define VMM_snr_Simulate_Iret                                0x0047    /* ver 3.0+ */
#define VMM_snr_Simulate_Far_Call                            0x0048    /* ver 3.0+ */
#define VMM_snr_Simulate_Far_Jmp                             0x0049    /* ver 3.0+ */
#define VMM_snr_Simulate_Far_Ret                             0x004A    /* ver 3.0+ */
#define VMM_snr_Simulate_Far_Ret_N                           0x004B    /* ver 3.0+ */
#define VMM_snr_Build_Int_Stack_Frame                        0x004C    /* ver 3.0+ */
#define VMM_snr_Simulate_Push                                0x004D    /* ver 3.0+ */
#define VMM_snr_Simulate_Pop                                 0x004E    /* ver 3.0+ */
#define VMM_snr__HeapAllocate                                0x004F    /* ver 3.0+ */
#define VMM_snr__HeapReAllocate                              0x0050    /* ver 3.0+ */
#define VMM_snr__HeapFree                                    0x0051    /* ver 3.0+ */
#define VMM_snr__HeapGetSize                                 0x0052    /* ver 3.0+ */
#define VMM_snr__PageAllocate                                0x0053    /* ver 3.0+ */
#define VMM_snr__PageReAllocate                              0x0054    /* ver 3.0+ */
#define VMM_snr__PageFree                                    0x0055    /* ver 3.0+ */
#define VMM_snr__PageLock                                    0x0056    /* ver 3.0+ */
#define VMM_snr__PageUnLock                                  0x0057    /* ver 3.0+ */
#define VMM_snr__PageGetSizeAddr                             0x0058    /* ver 3.0+ */
#define VMM_snr__PageGetAllocInfo                            0x0059    /* ver 3.0+ */
#define VMM_snr__GetFreePageCount                            0x005A    /* ver 3.0+ */
#define VMM_snr__GetSysPageCount                             0x005B    /* ver 3.0+ */
#define VMM_snr__GetVMPgCount                                0x005C    /* ver 3.0+ */
#define VMM_snr__MapIntoV86                                  0x005D    /* ver 3.0+ */
#define VMM_snr__PhysIntoV86                                 0x005E    /* ver 3.0+ */
#define VMM_snr__TestGlobalV86Mem                            0x005F    /* ver 3.0+ */
#define VMM_snr__ModifyPageBits                              0x0060    /* ver 3.0+ */
#define VMM_snr__CopyPageTable                               0x0061    /* ver 3.0+ */
#define VMM_snr__LinMapIntoV86                               0x0062    /* ver 3.0+ */
#define VMM_snr__LinPageLock                                 0x0063    /* ver 3.0+ */
#define VMM_snr__LinPageUnLock                               0x0064    /* ver 3.0+ */
#define VMM_snr__SetResetV86Pageable                         0x0065    /* ver 3.0+ */
#define VMM_snr__GetV86PageableArray                         0x0066    /* ver 3.0+ */
#define VMM_snr__PageCheckLinRange                           0x0067    /* ver 3.0+ */
#define VMM_snr__PageOutDirtyPages                           0x0068    /* ver 3.0+ */
#define VMM_snr__PageDiscardPages                            0x0069    /* ver 3.0+ */
#define VMM_snr__GetNulPageHandle                            0x006A    /* ver 3.0+ */
#define VMM_snr__GetFirstV86Page                             0x006B    /* ver 3.0+ */
#define VMM_snr__MapPhysToLinear                             0x006C    /* ver 3.0+ */
#define VMM_snr__GetAppFlatDSAlias                           0x006D    /* ver 3.0+ */
#define VMM_snr__SelectorMapFlat                             0x006E    /* ver 3.0+ */
#define VMM_snr__GetDemandPageInfo                           0x006F    /* ver 3.0+ */
#define VMM_snr__GetSetPageOutCount                          0x0070    /* ver 3.0+ */
#define VMM_snr_Hook_V86_Page                                0x0071    /* ver 3.0+ */
#define VMM_snr__Assign_Device_V86_Pages                     0x0072    /* ver 3.0+ */
#define VMM_snr__DeAssign_Device_V86_Pages                   0x0073    /* ver 3.0+ */
#define VMM_snr__Get_Device_V86_Pages_Array                  0x0074    /* ver 3.0+ */
#define VMM_snr_MMGR_SetNULPageAddr                          0x0075    /* ver 3.0+ */
#define VMM_snr__Allocate_GDT_Selector                       0x0076    /* ver 3.0+ */
#define VMM_snr__Free_GDT_Selector                           0x0077    /* ver 3.0+ */
#define VMM_snr__Allocate_LDT_Selector                       0x0078    /* ver 3.0+ */
#define VMM_snr__Free_LDT_Selector                           0x0079    /* ver 3.0+ */
#define VMM_snr__BuildDescriptorDWORDs                       0x007A    /* ver 3.0+ */
#define VMM_snr__GetDescriptor                               0x007B    /* ver 3.0+ */
#define VMM_snr__SetDescriptor                               0x007C    /* ver 3.0+ */
#define VMM_snr__MMGR_Toggle_HMA                             0x007D    /* ver 3.0+ */
#define VMM_snr_Get_Fault_Hook_Addrs                         0x007E    /* ver 3.0+ */
#define VMM_snr_Hook_V86_Fault                               0x007F    /* ver 3.0+ */
#define VMM_snr_Hook_PM_Fault                                0x0080    /* ver 3.0+ */
#define VMM_snr_Hook_VMM_Fault                               0x0081    /* ver 3.0+ */
#define VMM_snr_Begin_Nest_V86_Exec                          0x0082    /* ver 3.0+ */
#define VMM_snr_Begin_Nest_Exec                              0x0083    /* ver 3.0+ */
#define VMM_snr_Exec_Int                                     0x0084    /* ver 3.0+ */
#define VMM_snr_Resume_Exec                                  0x0085    /* ver 3.0+ */
#define VMM_snr_End_Nest_Exec                                0x0086    /* ver 3.0+ */
#define VMM_snr_Allocate_PM_App_CB_Area                      0x0087    /* ver 3.0+ */
#define VMM_snr_Get_Cur_PM_App_CB                            0x0088    /* ver 3.0+ */
#define VMM_snr_Set_V86_Exec_Mode                            0x0089    /* ver 3.0+ */
#define VMM_snr_Set_PM_Exec_Mode                             0x008A    /* ver 3.0+ */
#define VMM_snr_Begin_Use_Locked_PM_Stack                    0x008B    /* ver 3.0+ */
#define VMM_snr_End_Use_Locked_PM_Stack                      0x008C    /* ver 3.0+ */
#define VMM_snr_Save_Client_State                            0x008D    /* ver 3.0+ */
#define VMM_snr_Restore_Client_State                         0x008E    /* ver 3.0+ */
#define VMM_snr_Exec_VxD_Int                                 0x008F    /* ver 3.0+ */
#define VMM_snr_Hook_Device_Service                          0x0090    /* ver 3.0+ */
#define VMM_snr_Hook_Device_V86_API                          0x0091    /* ver 3.0+ */
#define VMM_snr_Hook_Device_PM_API                           0x0092    /* ver 3.0+ */
#define VMM_snr_System_Control                               0x0093    /* ver 3.0+ */
#define VMM_snr_Simulate_IO                                  0x0094    /* ver 3.0+ */
#define VMM_snr_Install_Mult_IO_Handlers                     0x0095    /* ver 3.0+ */
#define VMM_snr_Install_IO_Handler                           0x0096    /* ver 3.0+ */
#define VMM_snr_Enable_Global_Trapping                       0x0097    /* ver 3.0+ */
#define VMM_snr_Enable_Local_Trapping                        0x0098    /* ver 3.0+ */
#define VMM_snr_Disable_Global_Trapping                      0x0099    /* ver 3.0+ */
#define VMM_snr_Disable_Local_Trapping                       0x009A    /* ver 3.0+ */
#define VMM_snr_List_Create                                  0x009B    /* ver 3.0+ */
#define VMM_snr_List_Destroy                                 0x009C    /* ver 3.0+ */
#define VMM_snr_List_Allocate                                0x009D    /* ver 3.0+ */
#define VMM_snr_List_Attach                                  0x009E    /* ver 3.0+ */
#define VMM_snr_List_Attach_Tail                             0x009F    /* ver 3.0+ */
#define VMM_snr_List_Insert                                  0x00A0    /* ver 3.0+ */
#define VMM_snr_List_Remove                                  0x00A1    /* ver 3.0+ */
#define VMM_snr_List_Deallocate                              0x00A2    /* ver 3.0+ */
#define VMM_snr_List_Get_First                               0x00A3    /* ver 3.0+ */
#define VMM_snr_List_Get_Next                                0x00A4    /* ver 3.0+ */
#define VMM_snr_List_Remove_First                            0x00A5    /* ver 3.0+ */
#define VMM_snr__AddInstanceItem                             0x00A6    /* ver 3.0+ */
#define VMM_snr__Allocate_Device_CB_Area                     0x00A7    /* ver 3.0+ */
#define VMM_snr__Allocate_Global_V86_Data_Area               0x00A8    /* ver 3.0+ */
#define VMM_snr__Allocate_Temp_V86_Data_Area                 0x00A9    /* ver 3.0+ */
#define VMM_snr__Free_Temp_V86_Data_Area                     0x00AA    /* ver 3.0+ */
#define VMM_snr_Get_Profile_Decimal_Int                      0x00AB    /* ver 3.0+ */
#define VMM_snr_Convert_Decimal_String                       0x00AC    /* ver 3.0+ */
#define VMM_snr_Get_Profile_Fixed_Point                      0x00AD    /* ver 3.0+ */
#define VMM_snr_Convert_Fixed_Point_String                   0x00AE    /* ver 3.0+ */
#define VMM_snr_Get_Profile_Hex_Int                          0x00AF    /* ver 3.0+ */
#define VMM_snr_Convert_Hex_String                           0x00B0    /* ver 3.0+ */
#define VMM_snr_Get_Profile_Boolean                          0x00B1    /* ver 3.0+ */
#define VMM_snr_Convert_Boolean_String                       0x00B2    /* ver 3.0+ */
#define VMM_snr_Get_Profile_String                           0x00B3    /* ver 3.0+ */
#define VMM_snr_Get_Next_Profile_String                      0x00B4    /* ver 3.0+ */
#define VMM_snr_Get_Environment_String                       0x00B5    /* ver 3.0+ */
#define VMM_snr_Get_Exec_Path                                0x00B6    /* ver 3.0+ */
#define VMM_snr_Get_Config_Directory                         0x00B7    /* ver 3.0+ */
#define VMM_snr_OpenFile                                     0x00B8    /* ver 3.0+ */
#define VMM_snr_Get_PSP_Segment                              0x00B9    /* ver 3.0+ */
#define VMM_snr_GetDOSVectors                                0x00BA    /* ver 3.0+ */
#define VMM_snr_Get_Machine_Info                             0x00BB    /* ver 3.0+ */
#define VMM_snr_GetSet_HMA_Info                              0x00BC    /* ver 3.0+ */
#define VMM_snr_Set_System_Exit_Code                         0x00BD    /* ver 3.0+ */
#define VMM_snr_Fatal_Error_Handler                          0x00BE    /* ver 3.0+ */
#define VMM_snr_Fatal_Memory_Error                           0x00BF    /* ver 3.0+ */
#define VMM_snr_Update_System_Clock                          0x00C0    /* ver 3.0+ */
#define VMM_snr_Test_Debug_Installed                         0x00C1    /* ver 3.0+ */
#define VMM_snr_Out_Debug_String                             0x00C2    /* ver 3.0+ */
#define VMM_snr_Out_Debug_Chr                                0x00C3    /* ver 3.0+ */
#define VMM_snr_In_Debug_Chr                                 0x00C4    /* ver 3.0+ */
#define VMM_snr_Debug_Convert_Hex_Binary                     0x00C5    /* ver 3.0+ */
#define VMM_snr_Debug_Convert_Hex_Decimal                    0x00C6    /* ver 3.0+ */
#define VMM_snr_Debug_Test_Valid_Handle                      0x00C7    /* ver 3.0+ */
#define VMM_snr_Validate_Client_Ptr                          0x00C8    /* ver 3.0+ */
#define VMM_snr_Test_Reenter                                 0x00C9    /* ver 3.0+ */
#define VMM_snr_Queue_Debug_String                           0x00CA    /* ver 3.0+ */
#define VMM_snr_Log_Proc_Call                                0x00CB    /* ver 3.0+ */
#define VMM_snr_Debug_Test_Cur_VM                            0x00CC    /* ver 3.0+ */
#define VMM_snr_Get_PM_Int_Type                              0x00CD    /* ver 3.0+ */
#define VMM_snr_Set_PM_Int_Type                              0x00CE    /* ver 3.0+ */
#define VMM_snr_Get_Last_Updated_System_Time                 0x00CF    /* ver 3.0+ */
#define VMM_snr_Get_Last_Updated_VM_Exec_Time                0x00D0    /* ver 3.0+ */
#define VMM_snr_Test_DBCS_Lead_Byte                          0x00D1    /* ver 3.1+ */
#define VMM_snr__AddFreePhysPage                             0x00D2    /* ver 3.1+ */
#define VMM_snr__PageResetHandlePAddr                        0x00D3    /* ver 3.1+ */
#define VMM_snr__SetLastV86Page                              0x00D4    /* ver 3.1+ */
#define VMM_snr__GetLastV86Page                              0x00D5    /* ver 3.1+ */
#define VMM_snr__MapFreePhysReg                              0x00D6    /* ver 3.1+ */
#define VMM_snr__UnmapFreePhysReg                            0x00D7    /* ver 3.1+ */
#define VMM_snr__XchgFreePhysReg                             0x00D8    /* ver 3.1+ */
#define VMM_snr__SetFreePhysRegCalBk                         0x00D9    /* ver 3.1+ */
#define VMM_snr_Get_Next_Arena                               0x00DA    /* ver 3.1+ */
#define VMM_snr_Get_Name_Of_Ugly_TSR                         0x00DB    /* ver 3.1+ */
#define VMM_snr_Get_Debug_Options                            0x00DC    /* ver 3.1+ */
#define VMM_snr_Set_Physical_HMA_Alias                       0x00DD    /* ver 3.1+ */
#define VMM_snr__GetGlblRng0V86IntBase                       0x00DE    /* ver 3.1+ */
#define VMM_snr__Add_Global_V86_Data_Area                    0x00DF    /* ver 3.1+ */
#define VMM_snr_GetSetDetailedVMError                        0x00E0    /* ver 3.1+ */
#define VMM_snr_Is_Debug_Chr                                 0x00E1    /* ver 3.1+ */
#define VMM_snr_Clear_Mono_Screen                            0x00E2    /* ver 3.1+ */
#define VMM_snr_Out_Mono_Chr                                 0x00E3    /* ver 3.1+ */
#define VMM_snr_Out_Mono_String                              0x00E4    /* ver 3.1+ */
#define VMM_snr_Set_Mono_Cur_Pos                             0x00E5    /* ver 3.1+ */
#define VMM_snr_Get_Mono_Cur_Pos                             0x00E6    /* ver 3.1+ */
#define VMM_snr_Get_Mono_Chr                                 0x00E7    /* ver 3.1+ */
#define VMM_snr_Locate_Byte_In_ROM                           0x00E8    /* ver 3.1+ */
#define VMM_snr_Hook_Invalid_Page_Fault                      0x00E9    /* ver 3.1+ */
#define VMM_snr_Unhook_Invalid_Page_Fault                    0x00EA    /* ver 3.1+ */
#define VMM_snr_Set_Delete_On_Exit_File                      0x00EB    /* ver 3.1+ */
#define VMM_snr_Close_VM                                     0x00EC    /* ver 3.1+ */
#define VMM_snr_Enable_Touch_1st_Meg                         0x00ED    /* ver 3.1+ */
#define VMM_snr_Disable_Touch_1st_Meg                        0x00EE    /* ver 3.1+ */
#define VMM_snr_Install_Exception_Handler                    0x00EF    /* ver 3.1+ */
#define VMM_snr_Remove_Exception_Handler                     0x00F0    /* ver 3.1+ */
#define VMM_snr_Get_Crit_Status_No_Block                     0x00F1    /* ver 3.1+ */
#define VMM_snr__GetLastUpdatedThreadExecTime                0x00F2    /* ver 4.0+ */
#define VMM_snr__Trace_Out_Service                           0x00F3    /* ver 4.0+ */
#define VMM_snr__Debug_Out_Service                           0x00F4    /* ver 4.0+ */
#define VMM_snr__Debug_Flags_Service                         0x00F5    /* ver 4.0+ */
#define VMM_snr_VMMAddImportModuleName                       0x00F6    /* ver 4.0+ */
#define VMM_snr_VMM_Add_DDB                                  0x00F7    /* ver 4.0+ */
#define VMM_snr_VMM_Remove_DDB                               0x00F8    /* ver 4.0+ */
#define VMM_snr_Test_VM_Ints_Enabled                         0x00F9    /* ver 4.0+ */
#define VMM_snr__BlockOnID                                   0x00FA    /* ver 4.0+ */
#define VMM_snr_Schedule_Thread_Event                        0x00FB    /* ver 4.0+ */
#define VMM_snr_Cancel_Thread_Event                          0x00FC    /* ver 4.0+ */
#define VMM_snr_Set_Thread_Time_Out                          0x00FD    /* ver 4.0+ */
#define VMM_snr_Set_Async_Time_Out                           0x00FE    /* ver 4.0+ */
#define VMM_snr__AllocateThreadDataSlot                      0x00FF    /* ver 4.0+ */
#define VMM_snr__FreeThreadDataSlot                          0x0100    /* ver 4.0+ */
#define VMM_snr__CreateMutex                                 0x0101    /* ver 4.0+ */
#define VMM_snr__DestroyMutex                                0x0102    /* ver 4.0+ */
#define VMM_snr__GetMutexOwner                               0x0103    /* ver 4.0+ */
#define VMM_snr_Call_When_Thread_Switched                    0x0104    /* ver 4.0+ */
#define VMM_snr_VMMCreateThread                              0x0105    /* ver 4.0+ */
#define VMM_snr__GetThreadExecTime                           0x0106    /* ver 4.0+ */
#define VMM_snr_VMMTerminateThread                           0x0107    /* ver 4.0+ */
#define VMM_snr_Get_Cur_Thread_Handle                        0x0108    /* ver 4.0+ */
#define VMM_snr_Test_Cur_Thread_Handle                       0x0109    /* ver 4.0+ */
#define VMM_snr_Get_Sys_Thread_Handle                        0x010A    /* ver 4.0+ */
#define VMM_snr_Test_Sys_Thread_Handle                       0x010B    /* ver 4.0+ */
#define VMM_snr_Validate_Thread_Handle                       0x010C    /* ver 4.0+ */
#define VMM_snr_Get_Initial_Thread_Handle                    0x010D    /* ver 4.0+ */
#define VMM_snr_Test_Initial_Thread_Handle                   0x010E    /* ver 4.0+ */
#define VMM_snr_Debug_Test_Valid_Thread_Handle               0x010F    /* ver 4.0+ */
#define VMM_snr_Debug_Test_Cur_Thread                        0x0110    /* ver 4.0+ */
#define VMM_snr_VMM_GetSystemInitState                       0x0111    /* ver 4.0+ */
#define VMM_snr_Cancel_Call_When_Thread_Switched             0x0112    /* ver 4.0+ */
#define VMM_snr_Get_Next_Thread_Handle                       0x0113    /* ver 4.0+ */
#define VMM_snr_Adjust_Thread_Exec_Priority                  0x0114    /* ver 4.0+ */
#define VMM_snr__Deallocate_Device_CB_Area                   0x0115    /* ver 4.0+ */
#define VMM_snr_Remove_IO_Handler                            0x0116    /* ver 4.0+ */
#define VMM_snr_Remove_Mult_IO_Handlers                      0x0117    /* ver 4.0+ */
#define VMM_snr_Unhook_V86_Int_Chain                         0x0118    /* ver 4.0+ */
#define VMM_snr_Unhook_V86_Fault                             0x0119    /* ver 4.0+ */
#define VMM_snr_Unhook_PM_Fault                              0x011A    /* ver 4.0+ */
#define VMM_snr_Unhook_VMM_Fault                             0x011B    /* ver 4.0+ */
#define VMM_snr_Unhook_Device_Service                        0x011C    /* ver 4.0+ */
#define VMM_snr__PageReserve                                 0x011D    /* ver 4.0+ */
#define VMM_snr__PageCommit                                  0x011E    /* ver 4.0+ */
#define VMM_snr__PageDecommit                                0x011F    /* ver 4.0+ */
#define VMM_snr__PagerRegister                               0x0120    /* ver 4.0+ */
#define VMM_snr__PagerQuery                                  0x0121    /* ver 4.0+ */
#define VMM_snr__PagerDeregister                             0x0122    /* ver 4.0+ */
#define VMM_snr__ContextCreate                               0x0123    /* ver 4.0+ */
#define VMM_snr__ContextDestroy                              0x0124    /* ver 4.0+ */
#define VMM_snr__PageAttach                                  0x0125    /* ver 4.0+ */
#define VMM_snr__PageFlush                                   0x0126    /* ver 4.0+ */
#define VMM_snr__SignalID                                    0x0127    /* ver 4.0+ */
#define VMM_snr__PageCommitPhys                              0x0128    /* ver 4.0+ */
#define VMM_snr__Register_Win32_Services                     0x0129    /* ver 4.0+ */
#define VMM_snr_Cancel_Call_When_Not_Critical                0x012A    /* ver 4.0+ */
#define VMM_snr_Cancel_Call_When_Idle                        0x012B    /* ver 4.0+ */
#define VMM_snr_Cancel_Call_When_Task_Switched               0x012C    /* ver 4.0+ */
#define VMM_snr__Debug_Printf_Service                        0x012D    /* ver 4.0+ */
#define VMM_snr__EnterMutex                                  0x012E    /* ver 4.0+ */
#define VMM_snr__LeaveMutex                                  0x012F    /* ver 4.0+ */
#define VMM_snr_Simulate_VM_IO                               0x0130    /* ver 4.0+ */
#define VMM_snr_Signal_Semaphore_No_Switch                   0x0131    /* ver 4.0+ */
#define VMM_snr__ContextSwitch                               0x0132    /* ver 4.0+ */
#define VMM_snr__PageModifyPermissions                       0x0133    /* ver 4.0+ */
#define VMM_snr__PageQuery                                   0x0134    /* ver 4.0+ */
#define VMM_snr__EnterMustComplete                           0x0135    /* ver 4.0+ */
#define VMM_snr__LeaveMustComplete                           0x0136    /* ver 4.0+ */
#define VMM_snr__ResumeExecMustComplete                      0x0137    /* ver 4.0+ */
#define VMM_snr__GetThreadTerminationStatus                  0x0138    /* ver 4.0+ */
#define VMM_snr__GetInstanceInfo                             0x0139    /* ver 4.0+ */
#define VMM_snr__ExecIntMustComplete                         0x013A    /* ver 4.0+ */
#define VMM_snr__ExecVxDIntMustComplete                      0x013B    /* ver 4.0+ */
#define VMM_snr_Begin_V86_Serialization                      0x013C    /* ver 4.0+ */
#define VMM_snr_Unhook_V86_Page                              0x013D    /* ver 4.0+ */
#define VMM_snr_VMM_GetVxDLocationList                       0x013E    /* ver 4.0+ */
#define VMM_snr_VMM_GetDDBList                               0x013F    /* ver 4.0+ */
#define VMM_snr_Unhook_NMI_Event                             0x0140    /* ver 4.0+ */
#define VMM_snr_Get_Instanced_V86_Int_Vector                 0x0141    /* ver 4.0+ */
#define VMM_snr_Get_Set_Real_DOS_PSP                         0x0142    /* ver 4.0+ */
#define VMM_snr_Call_Priority_Thread_Event                   0x0143    /* ver 4.0+ */
#define VMM_snr_Get_System_Time_Address                      0x0144    /* ver 4.0+ */
#define VMM_snr_Get_Crit_Status_Thread                       0x0145    /* ver 4.0+ */
#define VMM_snr_Get_DDB                                      0x0146    /* ver 4.0+ */
#define VMM_snr_Directed_Sys_Control                         0x0147    /* ver 4.0+ */
#define VMM_snr__RegOpenKey                                  0x0148    /* ver 4.0+ */
#define VMM_snr__RegCloseKey                                 0x0149    /* ver 4.0+ */
#define VMM_snr__RegCreateKey                                0x014A    /* ver 4.0+ */
#define VMM_snr__RegDeleteKey                                0x014B    /* ver 4.0+ */
#define VMM_snr__RegEnumKey                                  0x014C    /* ver 4.0+ */
#define VMM_snr__RegQueryValue                               0x014D    /* ver 4.0+ */
#define VMM_snr__RegSetValue                                 0x014E    /* ver 4.0+ */
#define VMM_snr__RegDeleteValue                              0x014F    /* ver 4.0+ */
#define VMM_snr__RegEnumValue                                0x0150    /* ver 4.0+ */
#define VMM_snr__RegQueryValueEx                             0x0151    /* ver 4.0+ */
#define VMM_snr__RegSetValueEx                               0x0152    /* ver 4.0+ */
#define VMM_snr__CallRing3                                   0x0153    /* ver 4.0+ */
#define VMM_snr_Exec_PM_Int                                  0x0154    /* ver 4.0+ */
#define VMM_snr__RegFlushKey                                 0x0155    /* ver 4.0+ */
#define VMM_snr__PageCommitContig                            0x0156    /* ver 4.0+ */
#define VMM_snr__GetCurrentContext                           0x0157    /* ver 4.0+ */
#define VMM_snr__LocalizeSprintf                             0x0158    /* ver 4.0+ */
#define VMM_snr__LocalizeStackSprintf                        0x0159    /* ver 4.0+ */
#define VMM_snr_Call_Restricted_Event                        0x015A    /* ver 4.0+ */
#define VMM_snr_Cancel_Restricted_Event                      0x015B    /* ver 4.0+ */
#define VMM_snr_Register_PEF_Provider                        0x015C    /* ver 4.0+ */
#define VMM_snr__GetPhysPageInfo                             0x015D    /* ver 4.0+ */
#define VMM_snr__RegQueryInfoKey                             0x015E    /* ver 4.0+ */
#define VMM_snr_MemArb_Reserve_Pages                         0x015F    /* ver 4.0+ */
#define VMM_snr_Time_Slice_Sys_VM_Idle                       0x0160    /* ver 4.0+ */
#define VMM_snr_Time_Slice_Sleep                             0x0161    /* ver 4.0+ */
#define VMM_snr_Boost_With_Decay                             0x0162    /* ver 4.0+ */
#define VMM_snr_Set_Inversion_Pri                            0x0163    /* ver 4.0+ */
#define VMM_snr_Reset_Inversion_Pri                          0x0164    /* ver 4.0+ */
#define VMM_snr_Release_Inversion_Pri                        0x0165    /* ver 4.0+ */
#define VMM_snr_Get_Thread_Win32_Pri                         0x0166    /* ver 4.0+ */
#define VMM_snr_Set_Thread_Win32_Pri                         0x0167    /* ver 4.0+ */
#define VMM_snr_Set_Thread_Static_Boost                      0x0168    /* ver 4.0+ */
#define VMM_snr_Set_VM_Static_Boost                          0x0169    /* ver 4.0+ */
#define VMM_snr_Release_Inversion_Pri_ID                     0x016A    /* ver 4.0+ */
#define VMM_snr_Attach_Thread_To_Group                       0x016B    /* ver 4.0+ */
#define VMM_snr_Detach_Thread_From_Group                     0x016C    /* ver 4.0+ */
#define VMM_snr_Set_Group_Static_Boost                       0x016D    /* ver 4.0+ */
#define VMM_snr__GetRegistryPath                             0x016E    /* ver 4.0+ */
#define VMM_snr__GetRegistryKey                              0x016F    /* ver 4.0+ */
#define VMM_snr_Cleanup_Thread_State                         0x0170    /* ver 4.0+ */
#define VMM_snr__RegRemapPreDefKey                           0x0171    /* ver 4.0+ */
#define VMM_snr_End_V86_Serialization                        0x0172    /* ver 4.0+ */
#define VMM_snr__Assert_Range                                0x0173    /* ver 4.0+ */
#define VMM_snr__Sprintf                                     0x0174    /* ver 4.0+ */
#define VMM_snr__PageChangePager                             0x0175    /* ver 4.0+ */
#define VMM_snr__RegCreateDynKey                             0x0176    /* ver 4.0+ */
#define VMM_snr__RegQueryMultipleValues                      0x0177    /* ver 4.0+ */
#define VMM_snr_Boost_Thread_With_VM                         0x0178    /* ver 4.0+ */
#define VMM_snr_Get_Boot_Flags                               0x0179    /* ver 4.0+ */
#define VMM_snr_Set_Boot_Flags                               0x017A    /* ver 4.0+ */
#define VMM_snr__lstrcpyn                                    0x017B    /* ver 4.0+ */
#define VMM_snr__lstrlen                                     0x017C    /* ver 4.0+ */
#define VMM_snr__lmemcpy                                     0x017D    /* ver 4.0+ */
#define VMM_snr__GetVxDName                                  0x017E    /* ver 4.0+ */
#define VMM_snr_Force_Mutexes_Free                           0x017F    /* ver 4.0+ */
#define VMM_snr_Restore_Forced_Mutexes                       0x0180    /* ver 4.0+ */
#define VMM_snr__AddReclaimableItem                          0x0181    /* ver 4.0+ */
#define VMM_snr__SetReclaimableItem                          0x0182    /* ver 4.0+ */
#define VMM_snr__EnumReclaimableItem                         0x0183    /* ver 4.0+ */
#define VMM_snr_Time_Slice_Wake_Sys_VM                       0x0184    /* ver 4.0+ */
#define VMM_snr_VMM_Replace_Global_Environment               0x0185    /* ver 4.0+ */
#define VMM_snr_Begin_Non_Serial_Nest_V86_Exec               0x0186    /* ver 4.0+ */
#define VMM_snr_Get_Nest_Exec_Status                         0x0187    /* ver 4.0+ */
#define VMM_snr_Open_Boot_Log                                0x0188    /* ver 4.0+ */
#define VMM_snr_Write_Boot_Log                               0x0189    /* ver 4.0+ */
#define VMM_snr_Close_Boot_Log                               0x018A    /* ver 4.0+ */
#define VMM_snr_EnableDisable_Boot_Log                       0x018B    /* ver 4.0+ */
#define VMM_snr__Call_On_My_Stack                            0x018C    /* ver 4.0+ */
#define VMM_snr_Get_Inst_V86_Int_Vec_Base                    0x018D    /* ver 4.0+ */
#define VMM_snr__lstrcmpi                                    0x018E    /* ver 4.0+ */
#define VMM_snr__strupr                                      0x018F    /* ver 4.0+ */
#define VMM_snr_Log_Fault_Call_Out                           0x0190    /* ver 4.0+ */
#define VMM_snr__AtEventTime                                 0x0191    /* ver 4.0+ */
#define VMM_snr__PageOutPages                                0x0192    /* ver 4.10+ */
#define VMM_snr__Call_On_My_Not_Flat_Stack                   0x0193    /* ver 4.10+ */
#define VMM_snr__LinRegionLock                               0x0194    /* ver 4.10+ */
#define VMM_snr__LinRegionUnLock                             0x0195    /* ver 4.10+ */
#define VMM_snr__AttemptingSomethingDangerous                0x0196    /* ver 4.10+ */
#define VMM_snr__Vsprintf                                    0x0197    /* ver 4.10+ */
#define VMM_snr__Vsprintfw                                   0x0198    /* ver 4.10+ */
#define VMM_snr_Load_FS_Service                              0x0199    /* ver 4.10+ */
#define VMM_snr_Assert_FS_Service                            0x019A    /* ver 4.10+ */
#define VMM_snr__Begin_Preemptable_Code                      0x019B    /* ver 4.10+ */
#define VMM_snr__End_Preemptable_Code                        0x019C    /* ver 4.10+ */
#define VMM_snr__Get_CPUID_Flags                             0x019D    /* ver 4.10+ */
#define VMM_snr__RegisterGARTHandler                         0x019E    /* ver 4.10+ */
#define VMM_snr__GARTReserve                                 0x019F    /* ver 4.10+ */
#define VMM_snr__GARTCommit                                  0x01A0    /* ver 4.10+ */
#define VMM_snr__GARTUnCommit                                0x01A1    /* ver 4.10+ */
#define VMM_snr__GARTFree                                    0x01A2    /* ver 4.10+ */
#define VMM_snr__GARTMemAttributes                           0x01A3    /* ver 4.10+ */
#define VMM_snr_VMMCreateThreadEx                            0x01A4    /* ver 4.10+ */
#define VMM_snr__FlushCaches                                 0x01A5    /* ver 4.10+ */
#define VMM_snr_Set_Thread_Win32_Pri_NoYield                 0x01A6    /* ver 4.10+ */
#define VMM_snr__FlushMappedCacheBlock                       0x01A7    /* ver 4.10+ */
#define VMM_snr__ReleaseMappedCacheBlock                     0x01A8    /* ver 4.10+ */
#define VMM_snr_Run_Preemptable_Events                       0x01A9    /* ver 4.10+ */
#define VMM_snr__MMPreSystemExit                             0x01AA    /* ver 4.10+ */
#define VMM_snr__MMPageFileShutDown                          0x01AB    /* ver 4.10+ */
#define VMM_snr__Set_Global_Time_Out_Ex                      0x01AC    /* ver 4.10+ */
#define VMM_snr_Query_Thread_Priority                        0x01AD    /* ver 4.10+ */
#define VMM_snr__UnmapPhysToLinear                           0x01AE    /* ver 4.90+ */
#define VMM_snr__VmmRtInfo                                   0x01AF    /* ver 4.90+ */
#define VMM_snr__MPGetProcessorCount                         0x01B0    /* ver 4.90+ */
#define VMM_snr__MPEnterSingleProcessor                      0x01B1    /* ver 4.90+ */
#define VMM_snr__MPLeaveSingleProcessor                      0x01B2    /* ver 4.90+ */

/* NOTE: Some VxD calls are defined static inline to return a struct. As long as you simply read the */
/*       structure members, GCC's optimizer will boil it down to direct register access of the values */
/*       returned by the call and direct testing of the CPU flags. */

/* NOTE: Some VxD calls may be listed as 'asynchronous', which is Microsoft's term to mean a VxD call */
/*       that can be safely called from a hardware (asynchronous) interrupt. Non-asynchronous calls are */
/*       not reentrant and can cause problems if called in a reentrant manner. */

#if defined(__GNUC__) /* GCC only, for now */
# if defined(GCC_INLINE_ASM_SUPPORTS_cc_OUTPUT) /* we require GCC 6.1 or higher with support for CPU flags as output */
/*-------------------------------------------------------------*/
/*

  "The following structures are pointed to by EBP when VxD routines are entered,
   both for VxD control calls and traps(I/O traps, software INT traps, etc.).
   The first structure as DWORD values, the second WORD values and the last
   has BYTE values." -- Windows 3.1 DDK VMM.INC

 */
#pragma pack(push,1)
/* struct Client_Reg_Struc */
typedef struct Client_Reg_Struc {
    uint32_t        Client_EDI;                     /* +0x0000 Client's EDI */
    uint32_t        Client_ESI;                     /* +0x0004 Client's ESI */
    uint32_t        Client_EBP;                     /* +0x0008 Client's EBP */
    uint32_t        __unnamed_12;                   /* +0x000C ESP at pushall */
    uint32_t        Client_EBX;                     /* +0x0010 Client's EBX */
    uint32_t        Client_EDX;                     /* +0x0014 Client's EDX */
    uint32_t        Client_ECX;                     /* +0x0018 Client's ECX */
    uint32_t        Client_EAX;                     /* +0x001C Client's EAX */
    uint32_t        Client_Error;                   /* +0x0020 Dword error code */
    uint32_t        Client_EIP;                     /* +0x0024 EIP */
    uint16_t        Client_CS;                      /* +0x0028 CS */
    uint16_t        __unnamed_42;                   /* +0x002A (padding) */
    uint32_t        Client_EFlags;                  /* +0x002C EFLAGS */
    uint32_t        Client_ESP;                     /* +0x0030 ESP */
    uint16_t        Client_SS;                      /* +0x0034 SS */
    uint16_t        __unnamed_54;                   /* +0x0036 (padding) */
    uint16_t        Client_ES;                      /* +0x0038 ES */
    uint16_t        __unnamed_58;                   /* +0x003A (padding) */
    uint16_t        Client_DS;                      /* +0x003C DS */
    uint16_t        __unnamed_62;                   /* +0x003E (padding) */
    uint16_t        Client_FS;                      /* +0x0040 FS */
    uint16_t        __unnamed_66;                   /* +0x0042 (padding) */
    uint16_t        Client_GS;                      /* +0x0044 GS */
    uint16_t        __unnamed_70;                   /* +0x0046 (padding) */
    uint32_t        Client_Alt_EIP;                 /* +0x0048  */
    uint16_t        Client_Alt_CS;                  /* +0x004C  */
    uint16_t        __unnamed_78;                   /* +0x004E  */
    uint32_t        Client_Alt_EFlags;              /* +0x0050  */
    uint32_t        Client_Alt_ESP;                 /* +0x0054  */
    uint16_t        Client_Alt_SS;                  /* +0x0058  */
    uint16_t        __unnamed_90;                   /* +0x005A  */
    uint16_t        Client_Alt_ES;                  /* +0x005C  */
    uint16_t        __unnamed_94;                   /* +0x005E  */
    uint16_t        Client_Alt_DS;                  /* +0x0060  */
    uint16_t        __unnamed_98;                   /* +0x0062  */
    uint16_t        Client_Alt_FS;                  /* +0x0064  */
    uint16_t        __unnamed_102;                  /* +0x0066  */
    uint16_t        Client_Alt_GS;                  /* +0x0068  */
    uint16_t        __unnamed_106;                  /* +0x006A  */
} Client_Reg_Struc;
/* end Client_Reg_Struc (total 0x006C bytes) */

/* struct Client_Word_Reg_Struc */
typedef struct Client_Word_Reg_Struc {
    uint16_t        Client_DI;                      /* +0x0000 Client's DI */
    uint16_t        __unnamed_2;                    /* +0x0002 (padding) */
    uint16_t        Client_SI;                      /* +0x0004 Client's SI */
    uint16_t        __unnamed_6;                    /* +0x0006 (padding) */
    uint16_t        Client_BP;                      /* +0x0008 Client's BP */
    uint16_t        __unnamed_10;                   /* +0x000A (padding) */
    uint32_t        __unnamed_12;                   /* +0x000C ESP at pushall */
    uint16_t        Client_BX;                      /* +0x0010 Client's BX */
    uint16_t        __unnamed_18;                   /* +0x0012 (padding) */
    uint16_t        Client_DX;                      /* +0x0014 Client's DX */
    uint16_t        __unnamed_22;                   /* +0x0016 (padding) */
    uint16_t        Client_CX;                      /* +0x0018 Client's CX */
    uint16_t        __unnamed_26;                   /* +0x001A (padding) */
    uint16_t        Client_AX;                      /* +0x001C Client's AX */
    uint16_t        __unnamed_30;                   /* +0x001E (padding) */
    uint32_t        __unnamed_32;                   /* +0x0020 Dword error code */
    uint16_t        Client_IP;                      /* +0x0024 Client's IP */
    uint16_t        __unnamed_38;                   /* +0x0026 (padding) */
    uint32_t        __unnamed_40;                   /* +0x0028 CS */
    uint16_t        Client_Flags;                   /* +0x002C Client's flags (low) */
    uint16_t        __unnamed_46;                   /* +0x002E (padding) */
    uint16_t        Client_SP;                      /* +0x0030 SP */
    uint16_t        __unnamed_50;                   /* +0x0032  */
    uint32_t        __unnamed_52[5];                /* +0x0034  */
    uint16_t        Client_Alt_IP;                  /* +0x0048  */
    uint16_t        __unnamed_74;                   /* +0x004A  */
    uint32_t        __unnamed_76;                   /* +0x004C  */
    uint16_t        Client_Alt_Flags;               /* +0x0050  */
    uint16_t        __unnamed_82;                   /* +0x0052  */
    uint16_t        Client_Alt_SP;                  /* +0x0054  */
} Client_Word_Reg_Struc;
/* end Client_Word_Reg_Struc (total 0x0056 bytes) */

/* struct Client_Byte_Reg_Struc */
typedef struct Client_Byte_Reg_Struc {
    uint32_t        __unnamed_0[4];                 /* +0x0000 EDI, ESI, EBP, ESP at pushall */
    uint8_t         Client_BL;                      /* +0x0010 Client's BL */
    uint8_t         Client_BH;                      /* +0x0011 Client's BH */
    uint16_t        __unnamed_18;                   /* +0x0012 (padding) */
    uint8_t         Client_DL;                      /* +0x0014 Client's DL */
    uint8_t         Client_DH;                      /* +0x0015 Client's DH */
    uint16_t        __unnamed_22;                   /* +0x0016 (padding) */
    uint8_t         Client_CL;                      /* +0x0018 Client's CL */
    uint8_t         Client_CH;                      /* +0x0019 Client's CH */
    uint16_t        __unnamed_26;                   /* +0x001A (padding) */
    uint8_t         Client_AL;                      /* +0x001C Client's AL */
    uint8_t         Client_AH;                      /* +0x001D Client's AH */
} Client_Byte_Reg_Struc;
/* end Client_Byte_Reg_Struc (total 0x001E bytes) */
#pragma pack(pop)
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/* description: */
/*   Scheduler boost values (*_Boost)                                                                 */
/*                                                                                                    */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 1524 SCHEDULER BOOST VALUES binary EQUates */
#define Reserved_Low_Boost     0x00000001U /* 1U << 0U bit[0] Reserved for use by the system */
#define Cur_Run_VM_Boost       0x00000004U /* 1U << 2U bit[2] Used by time-slice scheduler to force a VM to run for it's allotted time-slice */
#define Low_Pri_Device_Boost   0x00000010U /* 1U << 4U bit[4] For events that need timely processing, but are not time critical */
#define High_Pri_Device_Boost  0x00001000U /* 1U << 12U bit[12] For events that need timely processing, but should not circumvent operations that have a critical section boost */
#define Critical_Section_Boost 0x00100000U /* 1U << 20U bit[20] Used by the system for virtual machines specified in a call to Begin_Critical_Section */
#define Time_Critical_Boost    0x00400000U /* 1U << 22U bit[22] For events that MUST be processed even with another VM is in a critical section (example: VPICD when simulating hardware interrupts) */
#define Reserved_High_Boost    0x40000000U /* 1U << 30U bit[30] Reserved for use by the system */

/*-------------------------------------------------------------*/
/* VMM Get_VMM_Version (VMMCall dev=0x0001 serv=0x0000) WINVER=3.0+ */

/* description: */
/*   Return VMM version */

/* inputs: */
/*   None */

/* outputs: */
/*   ECX = Debug (debug development revision number) */
/*   AX = version (AH=Major AL=Minor (example: 0x030A = 3.10)) */

typedef struct Get_VMM_Version__response {
    uint16_t version; /* AX */
    uint32_t Debug; /* ECX */
} Get_VMM_Version__response;

static inline Get_VMM_Version__response Get_VMM_Version(void) {
    register Get_VMM_Version__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_VMM_Version)
        : /* outputs */ "=a" (r.version), "=c" (r.Debug)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Cur_VM_Handle (VMMCall dev=0x0001 serv=0x0001) WINVER=3.0+ */

/* description: */
/*   Return current VM handle */

/* inputs: */
/*   None */

/* outputs: */
/*   EBX = Handle of the current VM */

/* returns: */
/*   Current VM handle */

/* asynchronous: */
/*   yes */

static inline vxd_vm_handle_t Get_Cur_VM_Handle(void) {
    register vxd_vm_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Cur_VM_Handle)
        : /* outputs */ "=b" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Test_Cur_VM_Handle (VMMCall dev=0x0001 serv=0x0002) WINVER=3.0+ */

/* description: */
/*   Test whether VM handle is current VM */

/* inputs: */
/*   EBX = VM (VM handle to test) */

/* outputs: */
/*   ZF = ZF set if vm handle matches */

/* returns: */
/*   Boolean value. True if VM handle matches, false if not. */

/* asynchronous: */
/*   yes */

static inline _Bool Test_Cur_VM_Handle(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Test_Cur_VM_Handle)
        : /* outputs */ "=@ccz" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Sys_VM_Handle (VMMCall dev=0x0001 serv=0x0003) WINVER=3.0+ */

/* description: */
/*   Return system VM handle */

/* inputs: */
/*   None */

/* outputs: */
/*   EBX = Handle of the system VM */

/* returns: */
/*   System VM handle */

/* asynchronous: */
/*   yes */

static inline vxd_vm_handle_t Get_Sys_VM_Handle(void) {
    register vxd_vm_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Sys_VM_Handle)
        : /* outputs */ "=b" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Test_Sys_VM_Handle (VMMCall dev=0x0001 serv=0x0004) WINVER=3.0+ */

/* description: */
/*   Test whether VM handle is system VM */

/* inputs: */
/*   EBX = VM (VM handle to test) */

/* outputs: */
/*   ZF = ZF set if vm handle matches */

/* returns: */
/*   Boolean value. True if VM handle matches the one given, false if not. */

/* asynchronous: */
/*   yes */

static inline _Bool Test_Sys_VM_Handle(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Test_Sys_VM_Handle)
        : /* outputs */ "=@ccz" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Validate_VM_Handle (VMMCall dev=0x0001 serv=0x0005) WINVER=3.0+ */

/* description: */
/*   Verify that the VM handle is valid */

/* inputs: */
/*   EBX = VM (VM handle to test) */

/* outputs: */
/*   !CF = CF is set if NOT valid, clear if valid. Return value should invert sense. */

/* returns: */
/*   Boolean value. True if VM handle is valid, false if invalid. */

/* asynchronous: */
/*   yes */

static inline _Bool Validate_VM_Handle(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Validate_VM_Handle)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_VMM_Reenter_Count (VMMCall dev=0x0001 serv=0x0006) WINVER=3.0+ */

/* description: */
/*   Return the number of times the VMM has been reentered. If nonzero, use only asynchronous calls. */

/* inputs: */
/*   None */

/* outputs: */
/*   ECX = number of times VMM has been reentered */

static inline uint32_t Get_VMM_Reenter_Count(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_VMM_Reenter_Count)
        : /* outputs */ "=c" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Begin_Reentrant_Execution (VMMCall dev=0x0001 serv=0x0007) WINVER=3.0+ */

/* description: */
/*   Start reentrant execution. You can use this when hooking VMM faults (reentrant processor faults) */
/*   in order to call non-asynchronous VMM or virtual device services or execute a virtual machine.   */
/*   Do not use this service to avoid scheduling events on hardware interrupts.                       */

/* inputs: */
/*   None */

/* outputs: */
/*   ECX = old reentrancy count */

/* returns: */
/*   unsigned int containing old reentrancy count, which must be saved and given to End_Reentrancy_Execution later on. */

static inline uint32_t Begin_Reentrant_Execution(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Begin_Reentrant_Execution)
        : /* outputs */ "=c" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM End_Reentrant_Execution (VMMCall dev=0x0001 serv=0x0008) WINVER=3.0+ */

/* description: */
/*   Ends reentrant execution, after Begin_Reentrant_Execution. */

/* inputs: */
/*   ECX = Count (reentrancy count returned by Begin_Reentrant_Execution) */

/* outputs: */
/*   None */

static inline void End_Reentrant_Execution(uint32_t const Count/*ecx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_End_Reentrant_Execution)
        : /* outputs */
        : /* inputs */ "c" (Count)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Install_V86_Break_Point (VMMCall dev=0x0001 serv=0x0009) WINVER=3.0+ */

/* description: */
/*   Insert a break point in virtual 8086 memory of the current virtual machine, and         */
/*   insert a breakpoint callback procedure to receive control when the break point happens. */

/* inputs: */
/*   EAX = BreakAddr (V86 address to place the break point) */
/*   EDX = RefData (pointer to reference data to be passed to callback procedure) */
/*   ESI = Callback (pointer to callback procedure to install (32-bit offset)) */

/* outputs: */
/*   !CF = success (CF clear) or failure (CF set) */

/* returns: */
/*   Bool, true if success, false if failure (not installed) */

static inline _Bool Install_V86_Break_Point(const void* const BreakAddr/*eax*/,const void* const RefData/*edx*/,const void* const Callback/*esi*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Install_V86_Break_Point)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "a" (BreakAddr), "d" (RefData), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Remove_V86_Break_Point (VMMCall dev=0x0001 serv=0x000A) WINVER=3.0+ */

/* description: */
/*   Remove a virtual 8086 break point installed with Install_V86_Break_Point in the current VM */

/* inputs: */
/*   EAX = BreakAddr (V86 address to remove break point from) */

/* outputs: */
/*   None */

static inline void Remove_V86_Break_Point(const void* const BreakAddr/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Remove_V86_Break_Point)
        : /* outputs */
        : /* inputs */ "a" (BreakAddr)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Allocate_V86_Call_Back (VMMCall dev=0x0001 serv=0x000B) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure for virtual 8086 mode applications can call to execute code in */
/*   a virtual device.                                                                           */

/* inputs: */
/*   EDX = RefData (points to reference data to pass to callback procedure) */
/*   ESI = Callback (points to callback procedure to call) */

/* outputs: */
/*   CF = error (if success, CF=0 and EAX=realmode ptr. if failure, CF=1) */
/*   EAX = CallbackAddr (if CF=0, segment:offset of real-mode callback address) */

typedef struct Allocate_V86_Call_Back__response {
    _Bool error; /* CF */
    uint32_t CallbackAddr; /* EAX */
} Allocate_V86_Call_Back__response;

static inline Allocate_V86_Call_Back__response Allocate_V86_Call_Back(const void* const RefData/*edx*/,const void* const Callback/*esi*/) {
    register Allocate_V86_Call_Back__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Allocate_V86_Call_Back)
        : /* outputs */ "=a" (r.CallbackAddr), "=@ccc" (r.error)
        : /* inputs */ "d" (RefData), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Allocate_PM_Call_Back (VMMCall dev=0x0001 serv=0x000C) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure for protected mode applications to call to execute code in a virtual device. */

/* inputs: */
/*   EDX = RefData (points to reference data to pass to callback procedure) */
/*   ESI = Callback (points to callback procedure to call) */

/* outputs: */
/*   CF = error (if success, CF=0 and EAX=realmode ptr. if failure, CF=1) */
/*   EAX = CallbackAddr (if CF=0, address of callback procedure) */

typedef struct Allocate_PM_Call_Back__response {
    _Bool error; /* CF */
    uint32_t CallbackAddr; /* EAX */
} Allocate_PM_Call_Back__response;

static inline Allocate_PM_Call_Back__response Allocate_PM_Call_Back(const void* const RefData/*edx*/,const void* const Callback/*esi*/) {
    register Allocate_PM_Call_Back__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Allocate_PM_Call_Back)
        : /* outputs */ "=a" (r.CallbackAddr), "=@ccc" (r.error)
        : /* inputs */ "d" (RefData), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Call_When_VM_Returns (VMMCall dev=0x0001 serv=0x000D) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure to receive control when a virtual machine executes the IRET instruction for  */
/*   the current interrupt.                                                                                    */
/*                                                                                                             */
/*   if TimeOut is positive, callback is called if VM does not execute IRET within the timeout period.         */
/*   if TimeOut is negative, callabck is called when timeout occurs and again when IRET is executed by the VM. */
/*   if TimeOut is zero, timeout is ignored.                                                                   */

/* inputs: */
/*   EAX = TimeOut (number of milliseconds for timeout. see description for details.) */
/*   EDX = RefData (pointer to reference data to pass to callback) */
/*   ESI = Callback (callback procedure (32-bit flat)) */

/* outputs: */
/*   None */

static inline void Call_When_VM_Returns(int32_t const TimeOut/*eax*/,const void* const RefData/*edx*/,const void* const Callback/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_When_VM_Returns)
        : /* outputs */
        : /* inputs */ "a" (TimeOut), "d" (RefData), "S" (Callback)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Schedule_Global_Event (VMMCall dev=0x0001 serv=0x000E) WINVER=3.0+ */

/* description: */
/*   Schedule a global event, which does not require a specific virtual machine to process it. */
/*   The system does not switch tasks before calling the procedure.                            */
/*                                                                                             */
/*   The callback can carry out any actions and use any VMM services. It is called like this:  */
/*                                                                                             */
/*   mov ebx,VM ; current VM handle                                                            */
/*   mov edx,RefData ; reference data pointer                                                  */
/*   mov ebp,crs ; pointer to a Client_Reg_Struc                                               */
/*   call [EventCallback]                                                                      */
/*                                                                                             */
/*   You can cancel a scheduled event using Cancel_Global_Event                                */

/* inputs: */
/*   ESI = EventCallback (pointer to callback procedure (32-bit flat)) */
/*   EDX = RefData (pointer to reference data to pass to callback) */

/* outputs: */
/*   ESI = event handle */

/* asynchronous: */
/*   yes */

static inline vxd_global_event_handle_t Schedule_Global_Event(const void* const EventCallback/*esi*/,const void* const RefData/*edx*/) {
    register vxd_global_event_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Schedule_Global_Event)
        : /* outputs */ "=S" (r)
        : /* inputs */ "S" (EventCallback), "d" (RefData)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Schedule_VM_Event (VMMCall dev=0x0001 serv=0x000F) WINVER=3.0+ */

/* description: */
/*   Schedule an event for the specified virtual machine. The system will carry out a task switch */
/*   to the virtual machine before calling the event callback procedure.                          */
/*                                                                                                */
/*   You can cancel a scheduled event using Cancel_VM_Event                                       */

/* inputs: */
/*   EBX = VM (VM handle to schedule event) */
/*   ESI = EventCallback (pointer to callback procedure (32-bit flat)) */
/*   EDX = RefData (pointer to reference data to pass to callback) */

/* outputs: */
/*   ESI = event handle */

/* asynchronous: */
/*   yes */

static inline vxd_vm_event_handle_t Schedule_VM_Event(vxd_vm_handle_t const VM/*ebx*/,const void* const EventCallback/*esi*/,const void* const RefData/*edx*/) {
    register vxd_vm_event_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Schedule_VM_Event)
        : /* outputs */ "=S" (r)
        : /* inputs */ "b" (VM), "S" (EventCallback), "d" (RefData)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Call_Global_Event (VMMCall dev=0x0001 serv=0x0010) WINVER=3.0+ */

/* description: */
/*   Call the event callback procedure immediately, or schedule a global event if the virtual device */
/*   is processing a hardware interrupt that interrupted the VMM.                                    */
/*                                                                                                   */
/*   You can cancel the event (if scheduled) using Cancel_Global_Event.                              */

/* inputs: */
/*   ESI = EventCallback (pointer to callback procedure (32-bit flat)) */
/*   EDX = RefData (pointer to reference data to pass to callback) */

/* outputs: */
/*   ESI = event handle, or 0 if procedure was called immediately without scheduling. */

/* asynchronous: */
/*   yes */

static inline vxd_global_event_handle_t Call_Global_Event(const void* const EventCallback/*esi*/,const void* const RefData/*edx*/) {
    register vxd_global_event_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_Global_Event)
        : /* outputs */ "=S" (r)
        : /* inputs */ "S" (EventCallback), "d" (RefData)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Call_VM_Event (VMMCall dev=0x0001 serv=0x0011) WINVER=3.0+ */

/* description: */
/*   Call the event callback procedure immediately, or schedule a VM event if the virtual device */
/*   is processing a hardware interrupt that interrupted the VMM.                                */
/*                                                                                               */
/*   You can cancel the event (if scheduled) using Cancel_VM_Event.                              */

/* inputs: */
/*   EBX = VM (VM handle) */
/*   ESI = EventCallback (pointer to callback procedure (32-bit flat)) */
/*   EDX = RefData (pointer to reference data to pass to callback) */

/* outputs: */
/*   ESI = event handle, or 0 if procedure was called immediately without scheduling. */

/* asynchronous: */
/*   yes */

static inline vxd_vm_event_handle_t Call_VM_Event(vxd_vm_handle_t const VM/*ebx*/,const void* const EventCallback/*esi*/,const void* const RefData/*edx*/) {
    register vxd_vm_event_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_VM_Event)
        : /* outputs */ "=S" (r)
        : /* inputs */ "b" (VM), "S" (EventCallback), "d" (RefData)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Cancel_Global_Event (VMMCall dev=0x0001 serv=0x0012) WINVER=3.0+ */

/* description: */
/*   Cancel a global event previously scheduled by Schedule_Global_Event or Call_Global_Event                  */
/*   A virtual device must not attempt to cancel an event where the callback function has already been called. */

/* inputs: */
/*   ESI = Event (Event handle, or 0 if no event should be cancelled.) */

/* outputs: */
/*   None */

static inline void Cancel_Global_Event(vxd_global_event_handle_t const Event/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Cancel_Global_Event)
        : /* outputs */
        : /* inputs */ "S" (Event)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Cancel_VM_Event (VMMCall dev=0x0001 serv=0x0013) WINVER=3.0+ */

/* description: */
/*   Cancel a VM event previously scheduled by Schedule_VM_Event or Call_VM_Event                              */
/*   A virtual device must not attempt to cancel an event where the callback function has already been called. */

/* inputs: */
/*   EBX = VM (VM handle) */
/*   ESI = Event (Event handle, or 0 if no event should be cancelled.) */

/* outputs: */
/*   None */

static inline void Cancel_VM_Event(uint32_t const VM/*ebx*/,vxd_vm_event_handle_t const Event/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Cancel_VM_Event)
        : /* outputs */
        : /* inputs */ "b" (VM), "S" (Event)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* description: */
/*   Flags for Call_Priority_VM_Event (PEF_*)                                                            */
/*                                                                                                       */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 1537 FLAGS FOR CALL_PRIORITY_VM_EVENT EQUates */
#define PEF_Wait_For_STI      0x00000001U /* 1U << 0U bit[0] Callback procedure is not called until VM enables interrupts */
#define PEF_Wait_For_STI_Bit  0
#define PEF_Wait_Not_Crit     0x00000002U /* 1U << 1U bit[1] Callback procedure is not called until VM is not in a critical section or time-critical operation */
#define PEF_Wait_Not_Crit_Bit 1
#define PEF_Dont_Unboost      0x00000004U /* 1U << 2U bit[2] Priority of the VM is not reduced after return from callback */
#define PEF_Dont_Unboost_Bit  2
#define PEF_Always_Sched      0x00000008U /* 1U << 3U bit[3] Event is always scheduled, callback is never called immediately */
#define PEF_Always_Sched_Bit  3
#define PEF_Time_Out          0x00000010U /* 1U << 4U bit[4] Use timeout value in EDI (Windows 3.1 or higher) */
#define PEF_Time_Out_Bit      4

/*-------------------------------------------------------------*/
/* VMM Call_Priority_VM_Event (VMMCall dev=0x0001 serv=0x0014) WINVER=3.0+ */

/* description: */
/*   Calls the callback procedure immediately, or schedules a priority event for the specified virtual machine.   */
/*   Scheduling is done if the virtual device is processing a hardware interrupt that interrupted the VMM,        */
/*   or the current virtual machine is not the specified VM, or if the Flags parameter specifies the              */
/*   PEF_Always_Sched value.                                                                                      */
/*                                                                                                                */
/*   PriorityBoost must be a value limited such that when added to the VM's current execution priority the result */
/*   is within range of Reserved_Low_Boost to Reserved_High_Boost.                                                */

/* inputs: */
/*   EAX = PriorityBoost (positive, 0, or negative priority boost for the VM.) */
/*   EBX = VM (VM handle) */
/*   ECX = Flags (how to carry out the event. See PEF_* constants, ORed together.) */
/*   EDX = RefData (pointer to reference data for callback) */
/*   ESI = EventCallback (pointer to callback) */
/*   EDI = TimeOut (timeout in milliseconds IFF PEF_Time_Out is specified.) */

/* outputs: */
/*   ESI = event handle, or 0 if procedure was called immediately. */

static inline vxd_priority_vm_event_handle_t Call_Priority_VM_Event(int32_t const PriorityBoost/*eax*/,vxd_vm_handle_t const VM/*ebx*/,uint32_t const Flags/*ecx*/,const void* const RefData/*edx*/,const void* const EventCallback/*esi*/,uint32_t const TimeOut/*edi*/) {
    register vxd_priority_vm_event_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_Priority_VM_Event)
        : /* outputs */ "=S" (r)
        : /* inputs */ "a" (PriorityBoost), "b" (VM), "c" (Flags), "d" (RefData), "S" (EventCallback), "D" (TimeOut)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Cancel_Priority_VM_Event (VMMCall dev=0x0001 serv=0x0015) WINVER=3.0+ */

/* description: */
/*   Cancels an event previously schedule by Call_Priority_VM_Event.                                             */
/*   A virtual device must not attempt to cancel an event where the callback function has already been called.   */
/*   Any priority boost will be cancelled even if PEF_Dont_Unboost_Bit was specified when the event was created. */
/*   Do NOT use this call to cancel events scheduled using the Call_VM_Event or Schedule_VM_Event services, for  */
/*   those types of events you must use Cancel_VM_Event.                                                         */

/* inputs: */
/*   ESI = Event (event handle, or 0 if nothing to cancel) */

/* outputs: */
/*   None */

static inline void Cancel_Priority_VM_Event(vxd_priority_vm_event_handle_t const Event/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Cancel_Priority_VM_Event)
        : /* outputs */
        : /* inputs */ "S" (Event)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_NMI_Handler_Addr (VMMCall dev=0x0001 serv=0x0016) WINVER=3.0+ */

/* description: */
/*   Return the address of the current Non-Maskable Interrupt handler */

/* inputs: */
/*   None */

/* outputs: */
/*   ESI = pointer to current NMI handler */

static inline const void* Get_NMI_Handler_Addr(void) {
    register const void* r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_NMI_Handler_Addr)
        : /* outputs */ "=S" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_NMI_Handler_Addr (VMMCall dev=0x0001 serv=0x0017) WINVER=3.0+ */

/* description: */
/*   Set the Non-Maskable Interrupt vector to point to the specified handler.                    */
/*   The NMI handler is forbidden to call any virtual device or VMM services and                 */
/*   it must restrict itself to access only local data in the VxD_LOCKED_DATA_SEG segment.       */
/*   A virtual device that needs to use VMM services from NMI should instead use Hook_NMI_Event. */
/*                                                                                               */
/*   The handler must NOT execute the IRET instruction. It must jump to the previous NMI handler */
/*   that it retrieved from Get_NMI_Handler_Addr. x86 architecture design dictates that the CPU  */
/*   ignores additional NMIs until it executes the IRET instruction.                             */

/* inputs: */
/*   ESI = nmi (pointer to NMI handler) */

/* outputs: */
/*   None */

static inline void Set_NMI_Handler_Addr(const void* const nmi/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_NMI_Handler_Addr)
        : /* outputs */
        : /* inputs */ "S" (nmi)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Hook_NMI_Event (VMMCall dev=0x0001 serv=0x0018) WINVER=3.0+ */

/* description: */
/*   Install a Non-Maskable Interrupt event procedure. Event procedures are called in install  */
/*   order after the last handler in the NMI handler chain has been executed. Event procedures */
/*   are allowed to make VMM calls that are not permitted in NMI handlers.                     */
/*                                                                                             */
/*   NMI event procedures can be interrupted by another NMI, reentrancy is possible.           */

/* inputs: */
/*   ESI = NmiProc (pointer to NMI event handler) */

/* outputs: */
/*   None */

static inline void Hook_NMI_Event(const void* const NmiProc/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_NMI_Event)
        : /* outputs */
        : /* inputs */ "S" (NmiProc)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Call_When_VM_Ints_Enabled (VMMCall dev=0x0001 serv=0x0019) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure that the system calls whenever the virtual machine enables interrupts. */
/*   The callback is called immediately if interrupts are already enabled. Virtual devices use this to   */
/*   receive notification when the virtual machine enables interrupts.                                   */
/*                                                                                                       */
/*   It is usually more convenient to use Call_Priority_VM_Event, but this call is faster.               */

/* inputs: */
/*   EDX = RefData (pointer to reference data to pass to callback) */
/*   ESI = Callback (pointer to callback function) */

/* outputs: */
/*   None */

static inline void Call_When_VM_Ints_Enabled(const void* const RefData/*edx*/,const void* const Callback/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_When_VM_Ints_Enabled)
        : /* outputs */
        : /* inputs */ "d" (RefData), "S" (Callback)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Enable_VM_Ints (VMMCall dev=0x0001 serv=0x001A) WINVER=3.0+ */

/* description: */
/*   Enable interrupts for the current virtual machine. It has the same effect as if the VM had executed the STI instruction. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Enable_VM_Ints(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Enable_VM_Ints)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Disable_VM_Ints (VMMCall dev=0x0001 serv=0x001B) WINVER=3.0+ */

/* description: */
/*   Disable interrupts for the current virtual machine. It has the same effect as if the VM had executed the CLI instruction. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Disable_VM_Ints(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Disable_VM_Ints)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Map_Flat (VMMCall dev=0x0001 serv=0x001C) WINVER=3.0+ */

/* description: */
/*   Convert a segment:offset or selector:offset pair to a linear address only for the current virtual machine.                          */
/*   The segment is converted as a V86 segment, or protected mode selector, depending on the execution state of the virtual machine.     */
/*   If the virtual machine is running 32-bit protected mode code, then the full 32 bits of the register are used.                       */
/*   For 16-bit protected mode and V86 code, only the lower 16 bits are used.                                                            */
/*                                                                                                                                       */
/*   The parameter in this function is the full 16-bit contents of register AX, which contains the two 8-bit values stored in AH and AL. */
/*   AH is SegOffset, the byte offset from the start of the Client_Reg_Struc structure to the segment/selector register to convert.      */
/*   AL is OffOffset, the byte offset from the start of the Client_Reg_Struc structure to the register with the offset to convert.       */
/*   If AL is -1 (0xFF), then 0 is used as the offset of the address to convert (NOT the offset into the Client_Reg_Struc)               */
/*                                                                                                                                       */
/*   To form the parameter correctly for this function:                                                                                  */
/*                                                                                                                                       */
/*   Map_Flat((SegOffset << 8) + OffOffset);                                                                                             */
/*                                                                                                                                       */
/*   The linear address returned is the ring-0 linear address that corresponds to the segment:offset address specified.                  */

/* inputs: */
/*   AX = SegOffOffset (AX = [AH,AL] 16-bit value, AH=SegOffset AL=OffOffset) */

/* outputs: */
/*   EAX = linear address, or -1 (0xFFFFFFFF) if invalid */

static inline uint32_t Map_Flat(uint16_t const SegOffOffset/*ax*/) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Map_Flat)
        : /* outputs */ "=a" (r)
        : /* inputs */ "a" (SegOffOffset)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Map_Lin_To_VM_Addr (VMMCall dev=0x0001 serv=0x001D) WINVER=3.0+ */

/* description: */
/*   Convert a 32-bit ring-0 linear address to a V86 or protected mode address appropriate                                                */
/*   for the current execution mode of the current virtual machine.                                                                       */
/*                                                                                                                                        */
/*   If the execution state of the virtual machine is V86 mode, then the returned pair is a segment:offset value.                         */
/*   This call will fail in V86 mode if the linear address is outside the 1MB limit of the                                                */
/*   current virtual machine's 1MB virtual 8086 mode address space.                                                                       */
/*                                                                                                                                        */
/*   If the execution state of the virtual machine is protected mode, then the                                                            */
/*   returned pair is a selector:offset value produced by creating a new entry in the                                                     */
/*   virtual machine's LDT (Local Descriptor Table).                                                                                      */
/*                                                                                                                                        */
/*   A device must never free a selector returned by this service. There is no function to free the mapping. Use this function sparingly. */

/* inputs: */
/*   EAX = LineAddr (Linear address to convert) */
/*   ECX = Limit (segment limit in bytes - 1 (a value of 0 means 1 byte long)) */

/* outputs: */
/*   EDX = Offset (address offset) */
/*   CX = SegSel (segment/selector if success) */
/*   CF = error (CF set if error, clear if success) */

typedef struct Map_Lin_To_VM_Addr__response {
    _Bool error; /* CF */
    uint16_t SegSel; /* CX */
    uint32_t Offset; /* EDX */
} Map_Lin_To_VM_Addr__response;

static inline Map_Lin_To_VM_Addr__response Map_Lin_To_VM_Addr(const void* const LineAddr/*eax*/,uint32_t const Limit/*ecx*/) {
    register Map_Lin_To_VM_Addr__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Map_Lin_To_VM_Addr)
        : /* outputs */ "=c" (r.SegSel), "=@ccc" (r.error), "=d" (r.Offset)
        : /* inputs */ "a" (LineAddr), "c" (Limit)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Adjust_Exec_Priority (VMMCall dev=0x0001 serv=0x001E) WINVER=3.0+ */

/* description: */
/*   Raise or lower the execution priority of the specified virtual machine. */

/* inputs: */
/*   EAX = PriorityBoost (*_Boost constant value) */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   None */

static inline void Adjust_Exec_Priority(int32_t const PriorityBoost/*eax*/,vxd_vm_handle_t const VM/*ebx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Adjust_Exec_Priority)
        : /* outputs */
        : /* inputs */ "a" (PriorityBoost), "b" (VM)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* description: */
/*   Flags for Begin_Critical_Section (Block_*)                 */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 1553 */
#define Block_Svc_Ints               0x00000001U /* 1U << 0U bit[0] Service interrupts in the virtual machine even if the virtual machine is blocked */
#define Block_Svc_Ints_Bit           0
#define Block_Svc_If_Ints_Locked     0x00000002U /* 1U << 1U bit[1] Service interrupts in the virtual machine even if the virtual machine is blocked and the VMStat_V86IntsLocked flag is set. */
#define Block_Svc_If_Ints_Locked_Bit 1
#define Block_Enable_Ints            0x00000004U /* 1U << 2U bit[2] Service interrupts in the virtual machine even if the virtual machine does not currently have interrupts enabled. Force interrupts to be enabled. Only relevant if (Svc_Ints | Svc_If_Ints_Locked) is set */
#define Block_Enable_Ints_Bit        2
#define Block_Poll                   0x00000008U /* 1U << 3U bit[3] Do not switch away from the blocked virtual machine unless another machine has higher priority. */
#define Block_Poll_Bit               3

/*-------------------------------------------------------------*/
/* VMM Begin_Critical_Section (VMMCall dev=0x0001 serv=0x001F) WINVER=3.0+ */

/* description: */
/*   Cause the current virtual machine to enter a critical section.                                   */
/*   Only one virtual machine can own the critical section at a time.                                 */
/*   This call will block until the critical section is available.                                    */
/*   The system maintains a count of critical section claim calls.                                    */
/*   The critical section is only released when the count is reduced to zero by End_Critical_Section. */
/*   Claiming the critical section boosts the priority of the current VM by Critical_Section_Boost.   */
/*   While in a critical section, the system will task switch only if the virtual machine blocks      */
/*   on a semaphore or the other task has a time-critical operation.                                  */

/* inputs: */
/*   ECX = Flags (flags for service. See Block_* constants.) */

/* outputs: */
/*   None */

static inline void Begin_Critical_Section(uint32_t const Flags/*ecx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Begin_Critical_Section)
        : /* outputs */
        : /* inputs */ "c" (Flags)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM End_Critical_Section (VMMCall dev=0x0001 serv=0x0020) WINVER=3.0+ */

/* description: */
/*   Release the critical section if claim count is reduced to zero.                                            */
/*   Calling this function decrements the claim count, and releases the critical section if the result is zero. */
/*   Releasing the critical section also lowers the execution priority of the current virtual machine,          */
/*   and may cause a task switch if a higher-priority non-suspended virtual machine is waiting.                 */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void End_Critical_Section(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_End_Critical_Section)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM End_Crit_And_Suspend (VMMCall dev=0x0001 serv=0x0021) WINVER=3.0+ */

/* description: */
/*   Release the critical section and immediately suspend the current virtual machine.                         */
/*   If the claim count is not 1 (and therefore the call will not release the section), the function will fail */
/*   and not change the claim count and return an error. If the system cannot suspend the virtual machine,     */
/*   then it will return an error.                                                                             */

/* inputs: */
/*   None */

/* outputs: */
/*   !CF = CF set if error (not released), CF clear if success */

/* returns: */
/*   Bool true if success, false if error */

static inline _Bool End_Crit_And_Suspend(void) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_End_Crit_And_Suspend)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Claim_Critical_Section (VMMCall dev=0x0001 serv=0x0022) WINVER=3.0+ */

/* description: */
/*   Increment the critical section claim count by the specified amount (as if calling Begin_Critical_Section by that many times) */

/* inputs: */
/*   EAX = Claims (how much to increment. zero is valid, but ignored) */
/*   ECX = Flags (Block_* constants) */

/* outputs: */
/*   None */

static inline void Claim_Critical_Section(uint32_t const Claims/*eax*/,uint32_t const Flags/*ecx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Claim_Critical_Section)
        : /* outputs */
        : /* inputs */ "a" (Claims), "c" (Flags)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Release_Critical_Section (VMMCall dev=0x0001 serv=0x0023) WINVER=3.0+ */

/* description: */
/*   Decrement the critical section claim count by the specified amount (as if calling End_Critical_Section by that many times) */

/* inputs: */
/*   ECX = Claims (how much to decrement. zero is valid, but ignored) */

/* outputs: */
/*   None */

static inline void Release_Critical_Section(uint32_t const Claims/*ecx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Release_Critical_Section)
        : /* outputs */
        : /* inputs */ "c" (Claims)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Call_When_Not_Critical (VMMCall dev=0x0001 serv=0x0024) WINVER=3.0+ */

/* description: */
/*   Install a critical section callback to be called when a virtual device releases the critical section.      */
/*   The callback is not executed until the current VM's execution priority is less than Critical_Section_Boost */
/*   even if the current virtual machine is not in a critical section, so that virtual devices can release      */
/*   a critical section and process any simulated interrupts before the system calls the callback procedure.    */
/*   Any number of callbacks can be installed, but the system will only call the most recent callback, and then */
/*   remove it from the list.                                                                                   */

/* inputs: */
/*   ESI = CritSecCallback (pointer to callback procedure) */
/*   EDX = RefData (pointer to reference data to pass to callback) */

/* outputs: */
/*   None */

static inline void Call_When_Not_Critical(const void* const CritSecCallback/*esi*/,const void* const RefData/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_When_Not_Critical)
        : /* outputs */
        : /* inputs */ "S" (CritSecCallback), "d" (RefData)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Create_Semaphore (VMMCall dev=0x0001 serv=0x0025) WINVER=3.0+ */

/* description: */
/*   Allocate and initialize a new semaphore. */

/* inputs: */
/*   ECX = TokenCount (initial token count) */

/* outputs: */
/*   CF = error (CF set if error, CF clear if success) */
/*   EAX = Semaphore (semaphore handle if CF=0) */

typedef struct Create_Semaphore__response {
    vxd_semaphore_handle_t Semaphore; /* EAX */
    _Bool error; /* CF */
} Create_Semaphore__response;

static inline Create_Semaphore__response Create_Semaphore(uint32_t const TokenCount/*ecx*/) {
    register Create_Semaphore__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Create_Semaphore)
        : /* outputs */ "=@ccc" (r.error), "=a" (r.Semaphore)
        : /* inputs */ "c" (TokenCount)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Destroy_Semaphore (VMMCall dev=0x0001 serv=0x0026) WINVER=3.0+ */

/* description: */
/*   Destroy the specified semaphore. */

/* inputs: */
/*   EAX = Semaphore (semaphore handle to delete) */

/* outputs: */
/*   None */

static inline void Destroy_Semaphore(vxd_semaphore_handle_t const Semaphore/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Destroy_Semaphore)
        : /* outputs */
        : /* inputs */ "a" (Semaphore)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Wait_Semaphore (VMMCall dev=0x0001 serv=0x0027) WINVER=3.0+ */

/* description: */
/*   Block the current virtual machine (wait) until the semaphore is signaled using Signal_Semaphore service. */

/* inputs: */
/*   EAX = Semaphore (semaphore handle to wait on) */
/*   ECX = Flags (Block_* constants) */

/* outputs: */
/*   None */

static inline void Wait_Semaphore(vxd_semaphore_handle_t const Semaphore/*eax*/,uint32_t const Flags/*ecx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Wait_Semaphore)
        : /* outputs */
        : /* inputs */ "a" (Semaphore), "c" (Flags)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Signal_Semaphore (VMMCall dev=0x0001 serv=0x0028) WINVER=3.0+ */

/* description: */
/*   Unblocks the virtual machine (if any) waiting on the semaphore. */

/* inputs: */
/*   EAX = Semaphore (semaphore handle) */

/* outputs: */
/*   None */

static inline void Signal_Semaphore(vxd_semaphore_handle_t const Semaphore/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Signal_Semaphore)
        : /* outputs */
        : /* inputs */ "a" (Semaphore)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_Crit_Section_Status (VMMCall dev=0x0001 serv=0x0029) WINVER=3.0+ */

/* description: */
/*   Returns the claim count and owner of the critical section.               */
/*   If the claim count is zero, it returns VM == Current VM and Claims == 0. */

/* inputs: */
/*   None */

/* outputs: */
/*   ECX = Claims (number of times claimed) */
/*   EBX = VM (VM handle of owner) */
/*   CF = high_priority (CF set if priority is Critical_Section_Boost or higher) */

/* asynchronous: */
/*   no */

typedef struct Get_Crit_Section_Status__response {
    vxd_vm_handle_t VM; /* EBX */
    uint32_t Claims; /* ECX */
    _Bool high_priority; /* CF */
} Get_Crit_Section_Status__response;

static inline Get_Crit_Section_Status__response Get_Crit_Section_Status(void) {
    register Get_Crit_Section_Status__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Crit_Section_Status)
        : /* outputs */ "=b" (r.VM), "=c" (r.Claims), "=@ccc" (r.high_priority)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Call_When_Task_Switched (VMMCall dev=0x0001 serv=0x002A) WINVER=3.0+ */

/* description: */
/*   Install a task-switched callback procedure that is called whenever the system carries out a task switch.  */
/*   Use this service sparingly and optimize the callback procedure for speed.                                 */
/*   For use by virtual devices that must save the state of a hardware device every time a task switch occurs. */
/*   Virtual devices can install any number of callback procedures. The system calls each one in the order     */
/*   installed until all have been called.                                                                     */

/* inputs: */
/*   ESI = TaskSwitchCallback (pointer to callback) */

/* outputs: */
/*   None */

static inline void Call_When_Task_Switched(const void* const TaskSwitchCallback/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_When_Task_Switched)
        : /* outputs */
        : /* inputs */ "S" (TaskSwitchCallback)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Suspend_VM (VMMCall dev=0x0001 serv=0x002B) WINVER=3.0+ */

/* description: */
/*   Suspend the execution of a specific virtual machine.                                                               */
/*   An error occurs if the virtual machine is in a critical section or the VM specified is the system virtual machine. */
/*   This call increments the suspend count of the virtual machine. If the suspend count was zero, then                 */
/*   the virtual machine is suspended and virtual devices are notified of the suspension. Otherwise,                    */
/*   Suspend_VM only increments the value with no other effects.                                                        */
/*                                                                                                                      */
/*   Suspending the VM sets the CB_VM_Status field of the virtual machine's control block.                              */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   !CF = CF set if not suspended (failure), clear if success */

/* returns: */
/*   Bool true if suspended, false if failure */

static inline _Bool Suspend_VM(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Suspend_VM)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Resume_VM (VMMCall dev=0x0001 serv=0x002C) WINVER=3.0+ */

/* description: */
/*   Resume execution of a virtual machine suspended by Suspend_VM.                                    */
/*   This call decrements the suspend count of the virtual machine. If the suspend count becomes zero, */
/*   then the virtual machine is placed into the ready-process queue. The system will task switch to   */
/*   the resumed VM if the virtual machine has a higher priority than the current virtual machine.     */
/*                                                                                                     */
/*   The system notifies every virtual device of the request to resume. Any virtual device can deny    */
/*   the request, which causes this service to return with CF set and the suspend count left at 1.     */
/*                                                                                                     */
/*   TODO: What does this return if the suspend count is greater than 1 and no other error occurs??    */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   !CF = CF set if error, clear if success */

/* returns: */
/*   Bool true if success, false if error */

static inline _Bool Resume_VM(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Resume_VM)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM No_Fail_Resume_VM (VMMCall dev=0x0001 serv=0x002D) WINVER=3.0+ */

/* description: */
/*   Resume execution of a virtual machine suspended by Suspend_VM.                                      */
/*   If the virtual machine cannot be resumed for any reason, the system will notify the user and handle */
/*   the error automatically, resuming the virtual machine when there is sufficient memory available.    */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   None */

static inline void No_Fail_Resume_VM(vxd_vm_handle_t const VM/*ebx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_No_Fail_Resume_VM)
        : /* outputs */
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Nuke_VM (VMMCall dev=0x0001 serv=0x002E) WINVER=3.0+ */

/* description: */
/*   Close a virtual machine that has not yet terminated.                                              */
/*   This call will never return if the VM handle is the current VM or system VM.                      */
/*   If the VM handle specified is the system VM, the service will close Windows and return to MS-DOS. */
/*                                                                                                     */
/*   This is typically used by the virtual shell service to close a virtual machine when the user      */
/*   chooses the Terminate button from the virtual machine's Settings dialog box.                      */
/*                                                                                                     */
/*   Use with caution.                                                                                 */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   None */

static inline void Nuke_VM(vxd_vm_handle_t const VM/*ebx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Nuke_VM)
        : /* outputs */
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Crash_Cur_VM (VMMCall dev=0x0001 serv=0x002F) WINVER=3.0+ */

/* description: */
/*   Abruptly terminate (abort) the current VM.                                        */
/*   A virtual device should call this function when a catastrophic error has occured, */
/*   such as executing an illegal instruction or attempting to program the hardware    */
/*   in a way incompatible with the device virtualization.                             */
/*                                                                                     */
/*   If the system VM is the current VM, Windows will exit with a fatal error without  */
/*   explicitly crashing the other VMs.                                                */
/*                                                                                     */
/*   This call does not return.                                                        */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Crash_Cur_VM(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Crash_Cur_VM)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_Execution_Focus (VMMCall dev=0x0001 serv=0x0030) WINVER=3.0+ */

/* description: */
/*   Return the handle of the virtual machine that currently has the execution focus, */
/*   also known as the foreground virtual machine.                                    */

/* inputs: */
/*   None */

/* outputs: */
/*   EBX = handle of foreground VM */

static inline vxd_vm_handle_t Get_Execution_Focus(void) {
    register vxd_vm_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Execution_Focus)
        : /* outputs */ "=b" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_Execution_Focus (VMMCall dev=0x0001 serv=0x0031) WINVER=3.0+ */

/* description: */
/*   Assign execution focus to the specified virtual machine (make it the foreground VM). */
/*   The foreground VM will then execute with it's foreground priority. If the VM has     */
/*   exclusive execution priority then it will become the only VM to receive time slices. */
/*   When a virtual machine receives the execution focus, the system suspends all other   */
/*   virtual machines except the system virtual machine and background virtual machines.  */
/*   Only the system VM can assign the execution focus to other VMs. A non-system VM      */
/*   can only assign the execution focus to itself.                                       */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   !CF = CF set if focus cannot be set, clear otherwise */

/* returns: */
/*   Bool true if focus was set, false otherwise */

static inline _Bool Set_Execution_Focus(vxd_vm_handle_t const VM/*ebx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_Execution_Focus)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Status flags in VM control block (VMStat_*)               */
/*                                                             */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 448 */
#define VMStat_Exclusive           0x00000001U /* 1U << 0U bit[0] VM is in exclusive mode */
#define VMStat_Exclusive_Bit       0
#define VMStat_Background          0x00000002U /* 1U << 1U bit[1] VM runs in background */
#define VMStat_Background_Bit      1
#define VMStat_Creating            0x00000004U /* 1U << 2U bit[2] VM is in the process of creation */
#define VMStat_Creating_Bit        2
#define VMStat_Suspended           0x00000008U /* 1U << 3U bit[3] VM is suspended (not scheduled) */
#define VMStat_Suspended_Bit       3
#define VMStat_Not_Executeable     0x00000010U /* 1U << 4U bit[4] VM is not executable (partially destroyed) */
#define VMStat_Not_Executeable_Bit 4
#define VMStat_PM_Exec             0x00000020U /* 1U << 5U bit[5] VM is running protected-mode application */
#define VMStat_PM_Exec_Bit         5
#define VMStat_PM_App              0x00000040U /* 1U << 6U bit[6] Protected mode application is present in VM */
#define VMStat_PM_App_Bit          6
#define VMStat_PM_Use32            0x00000080U /* 1U << 7U bit[7] Protected-mode application is 32-bit */
#define VMStat_PM_Use32_Bit        7
#define VMStat_VxD_Exec            0x00000100U /* 1U << 8U bit[8] "Call from VxD" */
#define VMStat_VxD_Exec_Bit        8
#define VMStat_High_Pri_Back       0x00000200U /* 1U << 9U bit[9] High-priority background */
#define VMStat_High_Pri_Back_Bit   9
#define VMStat_Blocked             0x00000400U /* 1U << 10U bit[10] VM is blocked on semaphore */
#define VMStat_Blocked_Bit         10
#define VMStat_Awakening           0x00000800U /* 1U << 11U bit[11] "Woke up after blocked" (FIXME: Woke? Awakening?) */
#define VMStat_Awakening_Bit       11
#define VMStat_PageableV86         0x00001000U /* 1U << 12U bit[12] A part of the virtual 8086 VM is pageable */
#define VMStat_PageableV86Bit      12
#define VMStat_V86IntsLocked       0x00002000U /* 1U << 13U bit[13] "Rest of V86 is locked" */
#define VMStat_V86IntsLockedBit    13
#define VMStat_TS_Sched            0x00004000U /* 1U << 14U bit[14] Scheduled by time-slicer */
#define VMStat_TS_Sched_Bit        14
#define VMStat_Idle                0x00008000U /* 1U << 15U bit[15] VM has released time */
#define VMStat_Idle_Bit            15
#define VMStat_Closing             0x00010000U /* 1U << 16U bit[16] VM is closing (Close_VM called for VM) */
#define VMStat_Closing_Bit         16
#define VMStat_Use32_Mask          0x00000180U /* 3U << 7U bits[8:7] VMStat_PM_Use32 | VMStat_VxD_Exec */

/*-------------------------------------------------------------*/
/* VMM Get_Time_Slice_Priority (VMMCall dev=0x0001 serv=0x0032) WINVER=3.0+ */

/* description: */
/*   Return the time-slice execution flags, foreground and background priorities, and percent of CPU usage for a specific virtual machine. */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   EAX = Flags (Status flags from the CB_VM_Status field of the VM control block (VMStat_*)) */
/*   ECX = Foreground (foreground time-slice priority (hi WORD is always 0)) */
/*   EDX = Background (background time-slice priority (hi WORD is always 0)) */
/*   ESI = CPUTime (percentage of total CPU time used (or, maximum time the VM can run?? docs are a bit confusing.)) */

typedef struct Get_Time_Slice_Priority__response {
    uint32_t Flags; /* EAX */
    uint32_t Foreground; /* ECX */
    uint32_t Background; /* EDX */
    uint32_t CPUTime; /* ESI */
} Get_Time_Slice_Priority__response;

static inline Get_Time_Slice_Priority__response Get_Time_Slice_Priority(vxd_vm_handle_t const VM/*ebx*/) {
    register Get_Time_Slice_Priority__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Time_Slice_Priority)
        : /* outputs */ "=a" (r.Flags), "=S" (r.CPUTime), "=d" (r.Background), "=c" (r.Foreground)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_Time_Slice_Priority (VMMCall dev=0x0001 serv=0x0033) WINVER=3.0+ */

/* description: */
/*   Set the time-slice execution flags, foreground and background priorities for a specific virtual machine. */

/* inputs: */
/*   EAX = Flags (status flags (VMStat_*)) */
/*   EBX = VM (VM handle) */
/*   ECX = Foreground (foreground time-slice priority) */
/*   EDX = Background (background time-slice priority) */

/* outputs: */
/*   !CF = CF set if failure, clear if success */

/* returns: */
/*   Bool, true if success, false if failure */

static inline _Bool Set_Time_Slice_Priority(uint32_t const Flags/*eax*/,vxd_vm_handle_t const VM/*ebx*/,uint32_t const Foreground/*ecx*/,uint32_t const Background/*edx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_Time_Slice_Priority)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "a" (Flags), "b" (VM), "c" (Foreground), "d" (Background)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Time_Slice_Granularity (VMMCall dev=0x0001 serv=0x0034) WINVER=3.0+ */

/* description: */
/*   Return the current time-slice granularity, the minimum millseconds a virtual machine runs before being rescheduled. */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = minimum time-slice in millseconds */

static inline uint32_t Get_Time_Slice_Granularity(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Time_Slice_Granularity)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_Time_Slice_Granularity (VMMCall dev=0x0001 serv=0x0035) WINVER=3.0+ */

/* description: */
/*   Set the minimum time-slice granularity, the minimum milliseconds a virtual machine runs before being rescheduled. */

/* inputs: */
/*   EAX = Time (minimum time-slice in milliseconds) */

/* outputs: */
/*   None */

static inline void Set_Time_Slice_Granularity(uint32_t const Time/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_Time_Slice_Granularity)
        : /* outputs */
        : /* inputs */ "a" (Time)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_Time_Slice_Info (VMMCall dev=0x0001 serv=0x0036) WINVER=3.0+ */

/* description: */
/*   Return information about the number of virtual machines currently scheduled by the time-slicer, and number that are idle. */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = Scheduled (number of virtual machines scheduled) */
/*   EBX = Current (handle of currently scheduled virtual machine) */
/*   ECX = Idle (number of idle virtual machines) */

/* asynchronous: */
/*   yes */

typedef struct Get_Time_Slice_Info__response {
    uint32_t Scheduled; /* EAX */
    uint32_t Current; /* EBX */
    uint32_t Idle; /* ECX */
} Get_Time_Slice_Info__response;

static inline Get_Time_Slice_Info__response Get_Time_Slice_Info(void) {
    register Get_Time_Slice_Info__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Time_Slice_Info)
        : /* outputs */ "=b" (r.Current), "=c" (r.Idle), "=a" (r.Scheduled)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Adjust_Execution_Time (VMMCall dev=0x0001 serv=0x0037) WINVER=3.0+ */

/* description: */
/*   Adjust the amount of execution time a virtual machine is granted with each time slice. */
/*   The effect is the same on all virtual machines regardless of their time-slot priority. */

/* inputs: */
/*   EAX = Time (number of milliseconds) */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   None */

static inline void Adjust_Execution_Time(uint32_t const Time/*eax*/,vxd_vm_handle_t const VM/*ebx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Adjust_Execution_Time)
        : /* outputs */
        : /* inputs */ "a" (Time), "b" (VM)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Release_Time_Slice (VMMCall dev=0x0001 serv=0x0038) WINVER=3.0+ */

/* description: */
/*   Discard remaining time in the current time-slice, and start a new time slice for the next virtual machine in the time-slice queue. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Release_Time_Slice(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Release_Time_Slice)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Wake_Up_VM (VMMCall dev=0x0001 serv=0x0039) WINVER=3.0+ */

/* description: */
/*   Restore an idle virtual machine, allowing the system to schedule the VM for subsequent time-slices.                              */
/*   A VM is idle if it has called Release_Time_Slice or has set the VMStat_Idle flag in the CB_VM_Status field of the control block. */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   None */

static inline void Wake_Up_VM(vxd_vm_handle_t const VM/*ebx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Wake_Up_VM)
        : /* outputs */
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Call_When_Idle (VMMCall dev=0x0001 serv=0x003A) WINVER=3.0+ */

/* description: */
/*   Install a system-wide callback procedure to call when the kernel signals that Windows is idle and all other VMs are idle. */

/* inputs: */
/*   ESI = IdleCallback (pointer to idle callback) */

/* outputs: */
/*   !CF = CF set if not installed, clear if installed */

/* returns: */
/*   Bool, true if installed, false if not installed */

static inline _Bool Call_When_Idle(const void* const IdleCallback/*esi*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Call_When_Idle)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "S" (IdleCallback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Next_VM_Handle (VMMCall dev=0x0001 serv=0x003B) WINVER=3.0+ */

/* description: */
/*   Return the handle of the next virtual machine in the VM list maintained by the system.       */
/*   Each VM only appears once, but no particular order is guaranteed.                            */
/*   The list is circular, so you must check for and stop when the first value comes back around. */

/* inputs: */
/*   EBX = VM (VM handle) */

/* outputs: */
/*   EBX = next VM handle */

static inline vxd_vm_handle_t Get_Next_VM_Handle(vxd_vm_handle_t const VM/*ebx*/) {
    register vxd_vm_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Next_VM_Handle)
        : /* outputs */ "=b" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_Global_Time_Out (VMMCall dev=0x0001 serv=0x003C) WINVER=3.0+ */

/* description: */
/*   Schedule a time-out to occur after the specified number of milliseconds have elapsed. */

/* inputs: */
/*   EAX = Time (number of milliseconds to time-out) */
/*   EDX = RefData (pointer to reference data to pass to callback) */
/*   ESI = TimeOutCallback (pointer to callback procedure) */

/* outputs: */
/*   ESI = timeout handle */

static inline vxd_timeout_handle_t Set_Global_Time_Out(uint32_t const Time/*eax*/,const void* const RefData/*edx*/,const void* const TimeOutCallback/*esi*/) {
    register vxd_timeout_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_Global_Time_Out)
        : /* outputs */ "=S" (r)
        : /* inputs */ "a" (Time), "d" (RefData), "S" (TimeOutCallback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_VM_Time_Out (VMMCall dev=0x0001 serv=0x003D) WINVER=3.0+ */

/* description: */
/*   Schedule a time-out to occur after the virtual machine has run for the specified number of milliseconds have elapsed. */

/* inputs: */
/*   EAX = Time (number of milliseconds to time-out) */
/*   EBX = VM (VM handle) */
/*   EDX = RefData (pointer to reference data to provide to callback) */
/*   ESI = TimeOutCallback (pointer to callback function) */

/* outputs: */
/*   ESI = timeout handle */

static inline vxd_timeout_handle_t Set_VM_Time_Out(uint32_t const Time/*eax*/,vxd_vm_handle_t const VM/*ebx*/,const void* const RefData/*edx*/,const void* const TimeOutCallback/*esi*/) {
    register vxd_timeout_handle_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_VM_Time_Out)
        : /* outputs */ "=S" (r)
        : /* inputs */ "a" (Time), "b" (VM), "d" (RefData), "S" (TimeOutCallback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Cancel_Time_Out (VMMCall dev=0x0001 serv=0x003E) WINVER=3.0+ */

/* description: */
/*   Cancel a time-out scheduled using Set_Global_Time_Out or Set_VM_Time_Out. */

/* inputs: */
/*   ESI = TimeOut (timeout handle) */

/* outputs: */
/*   None */

static inline void Cancel_Time_Out(vxd_timeout_handle_t const TimeOut/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Cancel_Time_Out)
        : /* outputs */
        : /* inputs */ "S" (TimeOut)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_System_Time (VMMCall dev=0x0001 serv=0x003F) WINVER=3.0+ */

/* description: */
/*   Return the time in milliseconds since Windows started. */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = time in milliseconds since Windows started */

/* asynchronous: */
/*   yes */

static inline uint32_t Get_System_Time(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_System_Time)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_VM_Exec_Time (VMMCall dev=0x0001 serv=0x0040) WINVER=3.0+ */

/* description: */
/*   Return the time in milliseconds the VM has run (execution time since creation). */
/*   A newly created VM has a time of zero.                                          */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = execution time of VM */

/* asynchronous: */
/*   yes */

static inline uint32_t Get_VM_Exec_Time(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_VM_Exec_Time)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_V86_Int_Chain (VMMCall dev=0x0001 serv=0x0041) WINVER=3.0+ */

/* description: */
/*   Install a hook procedure the system calls when the specific interrupt happens.                                 */
/*   Virtual devices use this service to monitor software interrupts and simulated hardware interrupts in V86 mode. */
/*   This call is only available during initialization.                                                             */

/* inputs: */
/*   EAX = Interrupt (Interrupt number to hook) */
/*   ESI = HookProc (pointer to hook procedure) */

/* outputs: */
/*   !CF = CF set if not installed, clear if installed */

/* returns: */
/*   Bool true if installed, false if not. */

static inline _Bool Hook_V86_Int_Chain(uint32_t const Interrupt/*eax*/,const void* const HookProc/*esi*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_V86_Int_Chain)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "a" (Interrupt), "S" (HookProc)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_V86_Int_Vector (VMMCall dev=0x0001 serv=0x0042) WINVER=3.0+ */

/* description: */
/*   Return the address of the real-mode interrupt vector in the current virtual machine. */

/* inputs: */
/*   EAX = Interrupt (Interrupt number to retrieve) */

/* outputs: */
/*   CX = Segment (segment address of interrupt routine) */
/*   EDX = Offset (offset of interrupt routine (high WORD is zero)) */

typedef struct Get_V86_Int_Vector__response {
    uint16_t Segment; /* CX */
    uint32_t Offset; /* EDX */
} Get_V86_Int_Vector__response;

static inline Get_V86_Int_Vector__response Get_V86_Int_Vector(uint32_t const Interrupt/*eax*/) {
    register Get_V86_Int_Vector__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_V86_Int_Vector)
        : /* outputs */ "=d" (r.Offset), "=c" (r.Segment)
        : /* inputs */ "a" (Interrupt)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_V86_Int_Vector (VMMCall dev=0x0001 serv=0x0043) WINVER=3.0+ */

/* description: */
/*   Set the real-mode interrupt vector to the specified real-mode address.                         */
/*                                                                                                  */
/*   This affects only the current virtual machine, unless called before Sys_VM_Init, in which case */
/*   the change becomes the default interrupt table for every virtual machine.                      */

/* inputs: */
/*   EAX = Interrupt (Interrupt number to set) */
/*   CX = Segment (segment of address) */
/*   EDX = Offset (offset of address) */

/* outputs: */
/*   None */

static inline void Set_V86_Int_Vector(uint32_t const Interrupt/*eax*/,uint16_t const Segment/*cx*/,uint32_t const Offset/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_V86_Int_Vector)
        : /* outputs */
        : /* inputs */ "a" (Interrupt), "c" (Segment), "d" (Offset)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Get_PM_Int_Vector (VMMCall dev=0x0001 serv=0x0044) WINVER=3.0+ */

/* description: */
/*   Return the address of the protected-mode interupt vector in the current virtual machine. */
/*   If the code segment is 16-bit, the high WORD of the offset is zero.                      */

/* inputs: */
/*   EAX = Interrupt (Interrupt nummber to set) */

/* outputs: */
/*   EDX = Offset (offset) */
/*   CX = Segment (segment selector) */

typedef struct Get_PM_Int_Vector__response {
    uint16_t Segment; /* CX */
    uint32_t Offset; /* EDX */
} Get_PM_Int_Vector__response;

static inline Get_PM_Int_Vector__response Get_PM_Int_Vector(uint32_t const Interrupt/*eax*/) {
    register Get_PM_Int_Vector__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_PM_Int_Vector)
        : /* outputs */ "=d" (r.Offset), "=c" (r.Segment)
        : /* inputs */ "a" (Interrupt)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_PM_Int_Vector (VMMCall dev=0x0001 serv=0x0045) WINVER=3.0+ */

/* description: */
/*   Set the protected-mode interrupt vector to the specified address.                              */
/*                                                                                                  */
/*   This affects only the current virtual machine, unless called before Sys_VM_Init, in which case */
/*   the change becomes the default interrupt table for every virtual machine.                      */
/*   Unless changed, the default protected-mode interrupt vector is a procedure that reflects the   */
/*   interrupt to V86 mode.                                                                         */

/* inputs: */
/*   EAX = Interrupt (Interrupt number to set) */
/*   CX = Segment (segment selector) */
/*   EDX = Offset (offset) */

/* outputs: */
/*   None */

static inline void Set_PM_Int_Vector(uint32_t const Interrupt/*eax*/,uint16_t const Segment/*cx*/,uint32_t const Offset/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_PM_Int_Vector)
        : /* outputs */
        : /* inputs */ "a" (Interrupt), "c" (Segment), "d" (Offset)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Int (VMMCall dev=0x0001 serv=0x0046) WINVER=3.0+ */

/* description: */
/*   Simulate an interrupt in the current virtual machine.                       */
/*   First, hook procedures set by the Hook_V86_Int_Chain service are called.    */
/*   If no hook procedure services the interrupt, this service pushes an IRET    */
/*   frame using the client CS, IP, and Flags onto the stack. When execution     */
/*   resumes, the virtual machine carries out the simulated interrupt and        */
/*   executes the V86 mode interrupt routine.                                    */
/*                                                                               */
/*   The virtual PIC device uses this service to simulate hardware interrupts.   */
/*   Other virtual devices might use the Exec_Int service to do the same.        */
/*                                                                               */
/*   If the virtual machine is in protected mode, then the service will simulate */
/*   a protected mode interrupt. Undesireable effects may occur if a protected   */
/*   mode virtual machine then attempts to reflect the interrupt to V86 mode.    */

/* inputs: */
/*   EAX = Interrupt (Interrupt number) */

/* outputs: */
/*   None */

static inline void Simulate_Int(uint32_t const Interrupt/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Int)
        : /* outputs */
        : /* inputs */ "a" (Interrupt)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Iret (VMMCall dev=0x0001 serv=0x0047) WINVER=3.0+ */

/* description: */
/*   Simulate a return from an interrupt, by popping the top three words from the stack  */
/*   and storing them into Client_Flags, Client_CS, and Client_IP.                       */
/*   The words are 32-bit if the segment is 32-bit, and 16-bit if the segment is 16-bit. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Simulate_Iret(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Iret)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Far_Call (VMMCall dev=0x0001 serv=0x0048) WINVER=3.0+ */

/* description: */
/*   Simulate a far call to a procedure in the current virtual machine.                        */
/*   Save the Client_CS and Client_IP registers to the stack, and set them to the new address. */
/*   When the virtual machine resumes, it will execute the procedure.                          */
/*   If the procedure is in a 16-bit segment, the high WORD of the offset must be zero.        */

/* inputs: */
/*   CX = Segment (segment of procedure) */
/*   EDX = Offset (offset of procedure) */

/* outputs: */
/*   None */

static inline void Simulate_Far_Call(uint16_t const Segment/*cx*/,uint32_t const Offset/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Far_Call)
        : /* outputs */
        : /* inputs */ "c" (Segment), "d" (Offset)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Far_Jmp (VMMCall dev=0x0001 serv=0x0049) WINVER=3.0+ */

/* description: */
/*   Simulate a far jmp to a procedure in the current virtual machine.                  */
/*   Set the Client_CS and Client_IP registers to the new address.                      */
/*   When the virtual machine resumes, it will execute the procedure.                   */
/*   If the procedure is in a 16-bit segment, the high WORD of the offset must be zero. */

/* inputs: */
/*   CX = Segment (segment of procedure) */
/*   EDX = Offset (offset of procedure) */

/* outputs: */
/*   None */

static inline void Simulate_Far_Jmp(uint16_t const Segment/*cx*/,uint32_t const Offset/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Far_Jmp)
        : /* outputs */
        : /* inputs */ "c" (Segment), "d" (Offset)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Far_Ret (VMMCall dev=0x0001 serv=0x004A) WINVER=3.0+ */

/* description: */
/*   Simulate a far return in the current virtual machine.                            */
/*   Pop two words off the stack and restore to Client_CS and Client_IP (as if RETF). */
/*   The words are 32-bit if the segment is 32-bit, else the words are 16-bit.        */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Simulate_Far_Ret(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Far_Ret)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Far_Ret_N (VMMCall dev=0x0001 serv=0x004B) WINVER=3.0+ */

/* description: */
/*   Simulate a far return in the current virtual machine.                            */
/*   Pop two words off the stack and restore to Client_CS and Client_IP (as if RETF). */
/*   The words are 32-bit if the segment is 32-bit, else the words are 16-bit.        */
/*   Then, the number of Bytes specifies are popped.                                  */

/* inputs: */
/*   EAX = Bytes (number of bytes pop from stack) */

/* outputs: */
/*   None */

static inline void Simulate_Far_Ret_N(uint32_t const Bytes/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Far_Ret_N)
        : /* outputs */
        : /* inputs */ "a" (Bytes)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Build_Int_Stack_Frame (VMMCall dev=0x0001 serv=0x004C) WINVER=3.0+ */

/* description: */
/*   Prepare an interrupt stack frame in the current virtual machine.       */
/*   Save the Client_CS, Client_IP, and Client_Flags on the stack, and then */
/*   Client_CS and Client_IP to the procedure.                              */

/* inputs: */
/*   CX = Segment (segment of procedure) */
/*   EDX = Offset (offset of procedure) */

/* outputs: */
/*   None */

static inline void Build_Int_Stack_Frame(uint16_t const Segment/*cx*/,uint32_t const Offset/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Build_Int_Stack_Frame)
        : /* outputs */
        : /* inputs */ "c" (Segment), "d" (Offset)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Push (VMMCall dev=0x0001 serv=0x004D) WINVER=3.0+ */

/* description: */
/*   Push a word onto the stack in the virtual machine.        */
/*   The word is 32-bit if a 32-bit stack, else a 16-bit word. */

/* inputs: */
/*   EAX = Value (value to push) */

/* outputs: */
/*   None */

static inline void Simulate_Push(uint32_t const Value/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Push)
        : /* outputs */
        : /* inputs */ "a" (Value)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Simulate_Pop (VMMCall dev=0x0001 serv=0x004E) WINVER=3.0+ */

/* description: */
/*   Pop a word off the stack in the virtual machine.          */
/*   The word is 32-bit if a 32-bit stack, else a 16-bit word. */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = value popped of the stack */

static inline uint32_t Simulate_Pop(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_Pop)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Heap allocation flags                                     */
/*                                                             */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 626 */
#define HeapZeroInit   0x00000001U /* 1U << 0U bit[0] Fill the memory block with zeros */
#define HeapZeroReInit 0x00000002U /* 1U << 1U bit[1] Fill all bytes, new and existing, with zeros */
#define HeapNoCopy     0x00000004U /* 1U << 2U bit[2] Do not preserve the existing byte contents. Else, the system will copy old contents to new contents. */

/*-------------------------------------------------------------*/
/* VMM _HeapAllocate (VMMCall dev=0x0001 serv=0x004F) WINVER=3.0+ */

/* description: */
/*   Allocate a block of memory from the heap.                                                                                                */
/*   Allocated memory is aligned on doubleword (32-bit) boundaries, however the block size does not have to be a multiple of 4.               */
/*   The system does not provide protection against overrunning the buffer into an adjacent block of memory,                                  */
/*   that is the virtual device's job to enforce.                                                                                             */
/*   The system does not offer any compaction of the heap. Virtual devices must not use the heap in any way that causes severe fragmentation. */

/* inputs: */
/*   __CDECL0 = nbytes (size in bytes to allocate. must not be zero.) */
/*   __CDECL1 = flags (allocation flags. Heap* constants.) */

/* outputs: */
/*   EAX = address of memory block, or zero if failure */

static inline void* _HeapAllocate(uint32_t const nbytes/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register void* r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__HeapAllocate)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (nbytes), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _HeapReAllocate (VMMCall dev=0x0001 serv=0x0050) WINVER=3.0+ */

/* description: */
/*   Reallocate or reinitialize an existing memory block.                             */
/*   If reallocation succeeds, the old memory address is no longer valid.             */
/*   If reallocation fails, the old memory block is not freed and is still valid.     */
/*   Thus, it works much the same way as the C library function realloc().            */
/*                                                                                    */
/*   hAddress MUST have been previously returned by _HeapAllocate or _HeapReAllocate. */

/* inputs: */
/*   __CDECL0 = hAddress (address of the memory block) */
/*   __CDECL1 = nbytes (size in bytes to allocate. must not be zero.) */
/*   __CDECL2 = flags (allocation flags. Heap* constants.) */

/* outputs: */
/*   EAX = address of memory block, or zero if failure */

static inline void* _HeapReAllocate(void* const hAddress/*__cdecl0*/,uint32_t const nbytes/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register void* r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__HeapReAllocate)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hAddress), "g" (nbytes), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _HeapFree (VMMCall dev=0x0001 serv=0x0051) WINVER=3.0+ */

/* description: */
/*   Free an existing memory block of heap.                                           */
/*   hAddress MUST have been previously returned by _HeapAllocate or _HeapReAllocate. */

/* inputs: */
/*   __CDECL0 = hAddress (address of the memory block) */
/*   __CDECL1 = flags (flags. must be zero.) */

/* outputs: */
/*   EAX = nonzero if freed, zero if not freed */

static inline uint32_t _HeapFree(void* const hAddress/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__HeapFree)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hAddress), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _HeapGetSize (VMMCall dev=0x0001 serv=0x0052) WINVER=3.0+ */

/* description: */
/*   Return the size of an existing block of heap.                                    */
/*   hAddress MUST have been previously returned by _HeapAllocate or _HeapReAllocate. */

/* inputs: */
/*   __CDECL0 = hAddress (address of memory block) */
/*   __CDECL1 = flags (flags. must be zero.) */

/* outputs: */
/*   EAX = size in bytes of block, or zero if error */

static inline uint32_t _HeapGetSize(void* const hAddress/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__HeapGetSize)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hAddress), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Page operation flags (Page*)                                                           */
/*                                                                                          */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 665                              */
/*                                                                                          */
/*   PageMAPFreePhysReg + _PageAllocate restriction:                                        */
/*   Must set page type to PG_SYS. VM, AlignMask, min/max phys, and physptr must be zero.   */
/*   A free phsyical region cannot be reallocated or freed. These exist for the duration of */
/*   the Windows session. Available only initialization, and only in Windows 3.1 or later.  */
#define PageZeroInit           0x00000001U /* 1U << 0U bit[0] Fill with zeros on allocate */
#define PageUseAlign           0x00000002U /* 1U << 1U bit[1] Allocate according to alignment and physical addresse range specified. Only available during initialization. Must be used with PageFixed. */
#define PageContig             0x00000004U /* 1U << 2U bit[2] Allocate contiguous physical pages to create the memory block. Must be used with PageUseAlign. */
#define PageFixed              0x00000008U /* 1U << 3U bit[3] Lock the allocated pages in memory at a fixed linear address, prevent pages from being unlocked or moved. */
#define PageDEBUGNulFault      0x00000010U /* 1U << 4U bit[4] ??? */
#define PageZeroReInit         0x00000020U /* 1U << 5U bit[5] TODO */
#define PageNoCopy             0x00000040U /* 1U << 6U bit[6] TODO */
#define PageLocked             0x00000080U /* 1U << 7U bit[7] Lock the allocated pages in memory. Pages can be unlocked using _PageUnlock */
#define PageLockedIfDP         0x00000100U /* 1U << 8U bit[8] Lock the allocated pages in memory only if the virtual pageswap device uses MS-DOS or BIOS functions. */
#define PageSetV86Pageable     0x00000200U /* 1U << 9U bit[9] TODO */
#define PageClearV86Pageable   0x00000400U /* 1U << 10U bit[10] TODO */
#define PageSetV86IntsLocked   0x00000800U /* 1U << 11U bit[11] TODO */
#define PageClearV86IntsLocked 0x00001000U /* 1U << 12U bit[12] TODO */
#define PageMarkPageOut        0x00002000U /* 1U << 13U bit[13] TODO */
#define PagePDPSetBase         0x00004000U /* 1U << 14U bit[14] TODO */
#define PagePDPClearBase       0x00008000U /* 1U << 15U bit[15] TODO */
#define PageDiscard            0x00010000U /* 1U << 16U bit[16] TODO */
#define PagePDPQueryDirty      0x00020000U /* 1U << 17U bit[17] TODO */
#define PageMapFreePhysReg     0x00040000U /* 1U << 18U bit[18] Allocate a free physical region that a virtual device can use to map physical pages. READ DESCRIPTION FOR DETAILS! (Windows 3.1) */

/*-------------------------------------------------------------*/
/* description: */
/*   Page types for page allocation functions (PG_*)            */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 2427 */
#define PG_VM        0x00000000UL /* 0 TODO */
#define PG_SYS       0x00000001UL /* 1 TODO */
#define PG_RESERVED1 0x00000002UL /* 2 TODO */
#define PG_PRIVATE   0x00000003UL /* 3 TODO */
#define PG_RESERVED2 0x00000004UL /* 4 TODO */
#define PG_RELOCK    0x00000005UL /* 5 TODO */
#define PG_INSTANCE  0x00000006UL /* 6 TODO */
#define PG_HOOKED    0x00000007UL /* 7 TODO */
#define PG_IGNORE    0xFFFFFFFFUL /* 0xFFFFFFFF TODO */

/*-------------------------------------------------------------*/
/* VMM _PageAllocate (VMMCall dev=0x0001 serv=0x0053) WINVER=3.0+ */

/* description: */
/*   Allocate a block of memory consisting of the specified number of pages.                                                   */
/*   This service reserves linear address space, and depending on flags, may also map to physical memory and lock them.        */
/*   This service returns both a memory handle and linear memory address.                                                      */
/*                                                                                                                             */
/*   The VM handle must be zero if using PG_SYS. It is only used if the page type is PG_VM and PG_HOOKED.                      */
/*                                                                                                                             */
/*   AlignMask could be thought of as an mask against the PAGE number (not the linear address).                                */
/*   Consider the following table of examples against (linear >> 12):                                                          */
/*   - 0x00000000 4KB alignment no constraint                                                                                  */
/*   - 0x00000001 8KB alignment constraint: ((linear >> 12) & 1) == 0                                                          */
/*   - 0x00000003 16KB alignment constraint: ((linear >> 12) & 3) == 0                                                         */
/*   - 0x00000007 32KB alignment constraint: ((linear >> 12) & 7) == 0                                                         */
/*   and so on, for any power of 2 alignment.                                                                                  */
/*   The documentation seems to specify (not very well) that this alignment is applied to choosing the PHYSICAL memory address */
/*   of the block, not to choosing the LINEAR memory address.                                                                  */

/* inputs: */
/*   __CDECL0 = nPages (number of pages to allocate. must not be zero) */
/*   __CDECL1 = pType (page type (PG_*) enumeration) */
/*   __CDECL2 = VM (VM handle in which to allocate pages) */
/*   __CDECL3 = AlignMask (alignment mask that defines acceptable starting page alignment) */
/*   __CDECL4 = minPhys (minimum acceptable physical page number (if PageUseAlign)) */
/*   __CDECL5 = maxPhys (maximum acceptable physical page number (if PageUseAlign)) */
/*   __CDECL6 = PhysAddr (pointer to uint32_t to receive physical address of memory block (if PageUseAlign)) */
/*   __CDECL7 = flags (operation flags, bitfield) */

/* outputs: */
/*   EAX = Handle (memory handle, or 0 if error) */
/*   EDX = Address (ring-0 address of memory block, or 0 if error) */

typedef struct _PageAllocate__response {
    uint32_t Handle; /* EAX */
    void* Address; /* EDX */
} _PageAllocate__response;

static inline _PageAllocate__response _PageAllocate(uint32_t const nPages/*__cdecl0*/,uint32_t const pType/*__cdecl1*/,vxd_vm_handle_t const VM/*__cdecl2*/,uint32_t const AlignMask/*__cdecl3*/,uint32_t const minPhys/*__cdecl4*/,uint32_t const maxPhys/*__cdecl5*/,uint32_t* const PhysAddr/*__cdecl6*/,uint32_t const flags/*__cdecl7*/) {
    register _PageAllocate__response r;

    __asm__ (
        "push %9\n"
        "push %8\n"
        "push %7\n"
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageAllocate)
        "addl $32,%%esp\n"
        : /* outputs */ "=d" (r.Address), "=a" (r.Handle)
        : /* inputs */ "g" (nPages), "g" (pType), "g" (VM), "g" (AlignMask), "g" (minPhys), "g" (maxPhys), "g" (PhysAddr), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageReAllocate (VMMCall dev=0x0001 serv=0x0054) WINVER=3.0+ */

/* description: */
/*   Reallocate, and possibly reinitialize an existing memory block.                    */
/*   This call can increase or decrease the number of pages in the memory block.        */
/*   The hMem memory handle must have been created by _PageAllocate or _PageReAllocate. */
/*                                                                                      */
/*   If successful, the old memory block is freed and invalid. If not successful,       */
/*   the new block is not allocated and the old memory block remains valid.             */

/* inputs: */
/*   __CDECL0 = hMem (handle of memory to reallocate) */
/*   __CDECL1 = nPages (number of pages in the reallocated memory block. must not be zero.) */
/*   __CDECL2 = flags (operation flags (Page* constants)) */

/* outputs: */
/*   EAX = Handle (new memory handle, or 0 if error) */
/*   EDX = Address (new ring-0 address of memory block, or 0 if error) */

typedef struct _PageReAllocate__response {
    uint32_t Handle; /* EAX */
    void* Address; /* EDX */
} _PageReAllocate__response;

static inline _PageReAllocate__response _PageReAllocate(uint32_t const hMem/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register _PageReAllocate__response r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageReAllocate)
        "addl $12,%%esp\n"
        : /* outputs */ "=d" (r.Address), "=a" (r.Handle)
        : /* inputs */ "g" (hMem), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageFree (VMMCall dev=0x0001 serv=0x0055) WINVER=3.0+ */

/* description: */
/*   Free the specified memory block.                                                        */
/*   The hMem memory handle must have been created by _PageAllocate or _PageReAllocate.      */
/*   Virtual devices that allocate PG_VM or PG_HOOKED pages must free the pages when the     */
/*   virtual machine is destroyed. PG_SYS pages do not need to be freed when Windows exists. */
/*   If a virtual device maps a memory block into V86 address space (_MapIntoV86) it should  */
/*   unmap the memory block before attempting to free it.                                    */

/* inputs: */
/*   __CDECL0 = hMem (handle of memory to free) */
/*   __CDECL1 = flags (operation flags. must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _PageFree(uint32_t const hMem/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageFree)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hMem), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageLock (VMMCall dev=0x0001 serv=0x0056) WINVER=3.0+ */

/* description: */
/*   Lock one or more pages in the specified memory block                                                                 */
/*   This call has no effect on pages locked using the PageFixed value. Such memory is always locked.                     */
/*   Virtual devices must not assume that the requested pages can always be locked.                                       */
/*   Each page in a memory block has a lock count. Locking the page increments the count, unlocking decrements the count. */
/*   When the lock count reaches zero, the page is unlocked.                                                              */
/*   Devices should not leave handles locked when not needed.                                                             */
/*                                                                                                                        */
/*   This call will error out if the sum of nPages and PageOff is greater than the number of pages in the memory block.   */

/* inputs: */
/*   __CDECL0 = hMem (handle of memory to lock) */
/*   __CDECL1 = nPages (number of pages to lock) */
/*   __CDECL2 = PageOff (offset in pages from the start of the memory block) */
/*   __CDECL3 = flags (operating flags (Page* constants)) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _PageLock(uint32_t const hMem/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const PageOff/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageLock)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hMem), "g" (nPages), "g" (PageOff), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageUnLock (VMMCall dev=0x0001 serv=0x0057) WINVER=3.0+ */

/* description: */
/*   Unlock one or more pages in the specified memory block                                                             */
/*                                                                                                                      */
/*   If PageMarkPageOut is specified, the pages are marked for immediate swapping if the lock count falls to zero.      */
/*                                                                                                                      */
/*   This call will error out if the sum of nPages and PageOff is greater than the number of pages in the memory block. */

/* inputs: */
/*   __CDECL0 = hMem (handle of memory to lock) */
/*   __CDECL1 = nPages (number of pages to lock) */
/*   __CDECL2 = PageOff (offset in pages from the start of the memory block) */
/*   __CDECL3 = flags (operating flags (Page* constants)) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _PageUnLock(uint32_t const hMem/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const PageOff/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageUnLock)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hMem), "g" (nPages), "g" (PageOff), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageGetSizeAddr (VMMCall dev=0x0001 serv=0x0058) WINVER=3.0+ */

/* description: */
/*   Return the size and linear ring-0 address of an existing block of memory */

/* inputs: */
/*   __CDECL0 = hMem (handle of memory to examine) */
/*   __CDECL1 = flags (operating flags, must be zero) */

/* outputs: */
/*   EDX = Address (ring-0 linear address of memory block, or 0 if error) */
/*   EAX = Pages (number of pages, or 0 if error) */

typedef struct _PageGetSizeAddr__response {
    uint32_t Pages; /* EAX */
    void* Address; /* EDX */
} _PageGetSizeAddr__response;

static inline _PageGetSizeAddr__response _PageGetSizeAddr(uint32_t const hMem/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register _PageGetSizeAddr__response r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageGetSizeAddr)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r.Pages), "=d" (r.Address)
        : /* inputs */ "g" (hMem), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageGetAllocInfo (VMMCall dev=0x0001 serv=0x0059) WINVER=3.0+ */

/* description: */
/*   Return the size in pages of the largest linear address block allocatable, and also as allocated as locked or fixed.      */
/*   There is no guarantee that a virtual machine can allocate all free pages as returned by this function.                   */
/*   It is also possible (mentioned in the docs) that the number of free pages can be less than the number of lockable pages. */

/* inputs: */
/*   __CDECL0 = flags (operating flags, must be zero) */

/* outputs: */
/*   EDX = Lockable (count of lockable pages) */
/*   EAX = Free (count of free pages) */

typedef struct _PageGetAllocInfo__response {
    uint32_t Free; /* EAX */
    uint32_t Lockable; /* EDX */
} _PageGetAllocInfo__response;

static inline _PageGetAllocInfo__response _PageGetAllocInfo(uint32_t const flags/*__cdecl0*/) {
    register _PageGetAllocInfo__response r;

    __asm__ (
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageGetAllocInfo)
        "addl $4,%%esp\n"
        : /* outputs */ "=a" (r.Free), "=d" (r.Lockable)
        : /* inputs */ "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetFreePageCount (VMMCall dev=0x0001 serv=0x005A) WINVER=3.0+ */

/* description: */
/*   Return the number of pages in the free list. */

/* inputs: */
/*   __CDECL0 = flags (operating flags, must be zero) */

/* outputs: */
/*   EAX = FreePages (number of free pages) */
/*   EDX = LockablePages (number of lockable pages) */

typedef struct _GetFreePageCount__response {
    uint32_t FreePages; /* EAX */
    uint32_t LockablePages; /* EDX */
} _GetFreePageCount__response;

static inline _GetFreePageCount__response _GetFreePageCount(uint32_t const flags/*__cdecl0*/) {
    register _GetFreePageCount__response r;

    __asm__ (
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetFreePageCount)
        "addl $4,%%esp\n"
        : /* outputs */ "=d" (r.LockablePages), "=a" (r.FreePages)
        : /* inputs */ "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetSysPageCount (VMMCall dev=0x0001 serv=0x005B) WINVER=3.0+ */

/* description: */
/*   Return the current number of system pages (pages allocated as PG_SYS). */

/* inputs: */
/*   __CDECL0 = flags (operating flags, must be zero) */

/* outputs: */
/*   EAX = number of pages allocated as PG_SYS */

static inline uint32_t _GetSysPageCount(uint32_t const flags/*__cdecl0*/) {
    register uint32_t r;

    __asm__ (
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetSysPageCount)
        "addl $4,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetVMPgCount (VMMCall dev=0x0001 serv=0x005C) WINVER=3.0+ */

/* description: */
/*   Return the current count of pages allocated to a specific virtual machine. */

/* inputs: */
/*   __CDECL0 = VM (virtual machine handle) */
/*   __CDECL1 = flags (operating flags, must be zero) */

/* outputs: */
/*   EAX = TotalPages (total pages allocated to the virtual machine, or 0 if error) */
/*   EDX = NotMappedIn1MB (total pages allocated but not mapped into the 1MB V86 address space, or 0 if error) */

typedef struct _GetVMPgCount__response {
    uint32_t TotalPages; /* EAX */
    uint32_t NotMappedIn1MB; /* EDX */
} _GetVMPgCount__response;

static inline _GetVMPgCount__response _GetVMPgCount(uint32_t const VM/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register _GetVMPgCount__response r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetVMPgCount)
        "addl $8,%%esp\n"
        : /* outputs */ "=d" (r.NotMappedIn1MB), "=a" (r.TotalPages)
        : /* inputs */ "g" (VM), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _MapIntoV86 (VMMCall dev=0x0001 serv=0x005D) WINVER=3.0+ */

/* description: */
/*   Map one or more pages of a memory block into the V86 address space of the specified virtual machine. */

/* inputs: */
/*   __CDECL0 = hMem (memory block handle (from _PageAllocate, _PageReAllocate)) */
/*   __CDECL1 = VM (VM handle to map it into) */
/*   __CDECL2 = VMLinPgNum (linear page number of V86 address to map to. must be in the range 0x10 through 0x10F inclusive.) */
/*   __CDECL3 = nPages (number of pages to map) */
/*   __CDECL4 = PageOff (offset in pages from start of memory block to first page to map) */
/*   __CDECL5 = flags (operation flags (Page* constants)) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _MapIntoV86(uint32_t const hMem/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const VMLinPgNum/*__cdecl2*/,uint32_t const nPages/*__cdecl3*/,uint32_t const PageOff/*__cdecl4*/,uint32_t const flags/*__cdecl5*/) {
    register uint32_t r;

    __asm__ (
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__MapIntoV86)
        "addl $24,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (hMem), "g" (VM), "g" (VMLinPgNum), "g" (nPages), "g" (PageOff), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PhysIntoV86 (VMMCall dev=0x0001 serv=0x005E) WINVER=3.0+ */

/* description: */
/*   Map the specified phsyical pages into the V86 address space.                                                   */
/*   Devices use this to associate physical device memory (such as video memory) with a particular virtual machine. */

/* inputs: */
/*   __CDECL0 = PhysPage (Physical page number of the start of the region to map (phys addr >> 12)) */
/*   __CDECL1 = VM (VM handle to map it into) */
/*   __CDECL2 = VMLinPgNum (linear page number of V86 address to map to. must be in the range 0x10 through 0x10F inclusive.) */
/*   __CDECL3 = nPages (number of pages to map) */
/*   __CDECL4 = flags (operation flags (Page* constants)) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _PhysIntoV86(uint32_t const PhysPage/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const VMLinPgNum/*__cdecl2*/,uint32_t const nPages/*__cdecl3*/,uint32_t const flags/*__cdecl4*/) {
    register uint32_t r;

    __asm__ (
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PhysIntoV86)
        "addl $20,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (PhysPage), "g" (VM), "g" (VMLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _TestGlobalV86Mem (VMMCall dev=0x0001 serv=0x005F) WINVER=3.0+ */

/* description: */
/*   Test whether a virtual 8086 address range is global, local, or instanced. */

/* inputs: */
/*   __CDECL0 = VMLinAddr (ring-0 linear address of the first byte of V86 address range (NOT real-mode seg:offset)) */
/*   __CDECL1 = nBytes (size in bytes of the V86 address range) */
/*   __CDECL2 = flags (operation flags (Page* constants)) */

/* outputs: */
/*   EAX = 0=local mem/invalid V86  1=global mem  2=local and global  3=global, also includes instance data */

static inline uint32_t _TestGlobalV86Mem(const void* const VMLinAddr/*__cdecl0*/,uint32_t const nBytes/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__TestGlobalV86Mem)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VMLinAddr), "g" (nBytes), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Page table entry bits (PG_*)                               */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 2401 */
#define P_PRES     0x00000001U /* 1U << 0U bit[0] page present */
#define P_PRESBit  0
#define P_WRITE    0x00000002U /* 1U << 1U bit[1] write access bit */
#define P_WRITEBit 1
#define P_USER     0x00000004U /* 1U << 2U bit[2] access bit for user mode */
#define P_USERBit  2
#define P_ACC      0x00000020U /* 1U << 5U bit[5] page accessed bit */
#define P_ACCBit   5
#define P_DIRTY    0x00000040U /* 1U << 6U bit[6] page dirty bit */
#define P_DIRTYBit 6

/*-------------------------------------------------------------*/
#define P_AVAIL         (P_PRES+P_WRITE+P_USER) /* avail to everyone & present */
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/* VMM _ModifyPageBits (VMMCall dev=0x0001 serv=0x0060) WINVER=3.0+ */

/* description: */
/*   Modifies the page attribute bits associated with PG_HOOKED pages in the v86 address space of a virtual machine. */
/*   You are only allowed to modify P_PRES, P_WRITE, and P_USER bits through bitAND and bitOR.                       */
/*   Page attribute bits are modified as follows: attr = (attr & bitAND) | bitOR.                                    */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = VMLinPgNum (linear page number of the first page to modify. all pages must be in the first 1MB of V86 space, at or above the first page of the VM, and at or below page 0x10F) */
/*   __CDECL2 = nPages (number of pages to modify) */
/*   __CDECL3 = bitAND (AND mask for the page attribute bits. All bits except P_PRES, P_WRITE, and P_USER must be set to 1.) */
/*   __CDECL4 = bitOR (OR mask for the page attribute bits. All bits except P_PRES, P_WRITE, and P_USER must be set to 0.) */
/*   __CDECL5 = pType (Page type) */
/*   __CDECL6 = flags (operation flags. must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _ModifyPageBits(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const VMLinPgNum/*__cdecl1*/,uint32_t const nPages/*__cdecl2*/,uint32_t const bitAND/*__cdecl3*/,uint32_t const bitOR/*__cdecl4*/,uint32_t const pType/*__cdecl5*/,uint32_t const flags/*__cdecl6*/) {
    register uint32_t r;

    __asm__ (
        "push %7\n"
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__ModifyPageBits)
        "addl $28,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (VMLinPgNum), "g" (nPages), "g" (bitAND), "g" (bitOR), "g" (pType), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _CopyPageTable (VMMCall dev=0x0001 serv=0x0061) WINVER=3.0+ */

/* description: */
/*   Copy one or more page table entries to a buffer.                                                                                  */
/*   Virtual devices such as the virtual DMA device use this service to analyze the mapping of linear to physical addresses.           */
/*   Page numbers must be in the range 0 to 0xFFFFF inclusive. Page numbers 0 to 0x10F inclusive specify the V86 address space.        */
/*                                                                                                                                     */
/*   The system copies the page table entries into the buffer given. It does not re-copy if changes are later made to the page tables, */
/*   so no guarantees are made that the information will remain accurate as time advances past the copy operation.                     */

/* inputs: */
/*   __CDECL0 = LinPgNum (Number of first page to begin at, for copying page table entries) */
/*   __CDECL1 = nPages (number of pages) */
/*   __CDECL2 = PageBuf (buffer to place page table entries) */
/*   __CDECL3 = flags (operation flags. must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _CopyPageTable(uint32_t const LinPgNum/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t* const PageBuf/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__CopyPageTable)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (LinPgNum), "g" (nPages), "g" (PageBuf), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _LinMapIntoV86 (VMMCall dev=0x0001 serv=0x0062) WINVER=3.0+ */

/* description: */
/*   Map one or more pages into the virtual 8086 address space of a virtual machine. */

/* inputs: */
/*   __CDECL0 = HLinPgNum (linear page number of the first page to map) */
/*   __CDECL1 = VM (VM handle) */
/*   __CDECL2 = VMLinPgNum (linear page number of an address in V86 address space, must be within 0x10 to 0x10F inclusive) */
/*   __CDECL3 = nPages (number of pages to map) */
/*   __CDECL4 = flags (operating flags. must be zero) */

/* outputs: */
/*   EDX = v86mapaddr ("if success, EDX contains the V86 address to which the pages are mapped") */
/*   EAX = mapped (nonzero if success, fail if zero) */

typedef struct _LinMapIntoV86__response {
    uint32_t mapped; /* EAX */
    uint32_t v86mapaddr; /* EDX */
} _LinMapIntoV86__response;

static inline _LinMapIntoV86__response _LinMapIntoV86(uint32_t const HLinPgNum/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const VMLinPgNum/*__cdecl2*/,uint32_t const nPages/*__cdecl3*/,uint32_t const flags/*__cdecl4*/) {
    register _LinMapIntoV86__response r;

    __asm__ (
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__LinMapIntoV86)
        "addl $20,%%esp\n"
        : /* outputs */ "=d" (r.v86mapaddr), "=a" (r.mapped)
        : /* inputs */ "g" (HLinPgNum), "g" (VM), "g" (VMLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _LinPageLock (VMMCall dev=0x0001 serv=0x0063) WINVER=3.0+ */

/* description: */
/*   Lock one or more pages starting at the linear page number */

/* inputs: */
/*   __CDECL0 = HLinPgNum (linear page number of the first page) */
/*   __CDECL1 = nPages (number of pages) */
/*   __CDECL2 = flags (operating flags. (Page*)) */

/* outputs: */
/*   EAX = nonzero if success, fail if zero */

static inline uint32_t _LinPageLock(uint32_t const HLinPgNum/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__LinPageLock)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (HLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _LinPageUnLock (VMMCall dev=0x0001 serv=0x0064) WINVER=3.0+ */

/* description: */
/*   Unlock one or more pages starting at the linear page number */

/* inputs: */
/*   __CDECL0 = HLinPgNum (linear page number of the first page) */
/*   __CDECL1 = nPages (number of pages) */
/*   __CDECL2 = flags (operating flags. (Page*)) */

/* outputs: */
/*   EAX = nonzero if success, fail if zero */

static inline uint32_t _LinPageUnLock(uint32_t const HLinPgNum/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__LinPageUnLock)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (HLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _SetResetV86Pageable (VMMCall dev=0x0001 serv=0x0065) WINVER=3.0+ */

/* description: */
/*   Modify the locking and unlocking behavior associated with a range of V86 memory. */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = VMLinPgNum (linear page number of the first page) */
/*   __CDECL2 = nPages (number of pages) */
/*   __CDECL3 = flags (operating flags. (Page*)) */

/* outputs: */
/*   EAX = nonzero if success, fail if zero */

static inline uint32_t _SetResetV86Pageable(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const VMLinPgNum/*__cdecl1*/,uint32_t const nPages/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__SetResetV86Pageable)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (VMLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetV86PageableArray (VMMCall dev=0x0001 serv=0x0066) WINVER=3.0+ */

/* description: */
/*   Return a copy of the bit array of pages who's behavior has been modified using the _SetResetV86Pageable service. */
/*   Virtual devices can use this to determine whether pages have had locking behavior modified.                      */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = ArrayBuf (pointer to buffer to receive 0x100-bit (32-byte) array) */
/*   __CDECL2 = flags (operating flags. (Page*)) */

/* outputs: */
/*   EAX = nonzero if success, fail if zero */

static inline uint32_t _GetV86PageableArray(vxd_vm_handle_t const VM/*__cdecl0*/,uint8_t* const ArrayBuf/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetV86PageableArray)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (ArrayBuf), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageCheckLinRange (VMMCall dev=0x0001 serv=0x0067) WINVER=3.0+ */

/* description: */
/*   Determine whether all bytes in a specific range of linear addresses are valid.                                                   */
/*   Virtual devices use this call to validate an address range before specifying the range to LinPageLock and LinMapIntoV86 service. */

/* inputs: */
/*   __CDECL0 = HLinPgNum (linear page number of the first page) */
/*   __CDECL1 = nPages (number of pages) */
/*   __CDECL2 = flags (operating flags, must be zero) */

/* outputs: */
/*   EAX = number of actual pages that are valid. zero if none are valid */

static inline uint32_t _PageCheckLinRange(uint32_t const HLinPgNum/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageCheckLinRange)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (HLinPgNum), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageOutDirtyPages (VMMCall dev=0x0001 serv=0x0068) WINVER=3.0+ */

/* description: */
/*   Flush dirty pages. Used by the virtual pageswap service to prevent too many dirty pages from accumulating. */

/* inputs: */
/*   __CDECL0 = nPages (number of pages) */
/*   __CDECL1 = flags (operating flags (Page*)) */

/* outputs: */
/*   EAX = count of dirty pages */

static inline uint32_t _PageOutDirtyPages(uint32_t const nPages/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageOutDirtyPages)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _PageDiscardPages (VMMCall dev=0x0001 serv=0x0069) WINVER=3.0+ */

/* description: */
/*   Mark pages as no longer in use, allowing the system to discard the pages.                                */
/*   Accessing the page after this call does not cause the system to read the contents of the page from swap. */

/* inputs: */
/*   __CDECL0 = LinPgNum (linear page number of the first page) */
/*   __CDECL1 = VM (VM handle) */
/*   __CDECL2 = nPages (number of pages) */
/*   __CDECL3 = flags (operating flags (Page*)) */

/* outputs: */
/*   EAX = nonzero if successful, zero if failure */

static inline uint32_t _PageDiscardPages(uint32_t const LinPgNum/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const nPages/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__PageDiscardPages)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (LinPgNum), "g" (VM), "g" (nPages), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetNulPageHandle (VMMCall dev=0x0001 serv=0x006A) WINVER=3.0+ */

/* description: */
/*   Return the memory handle of the system nul page. This page is used to occupy regions */
/*   of the address space which are unused but for which it is not desireable to cause a  */
/*   page fault when accessed. It can be mapped to multiple locations, the contents are   */
/*   always random.                                                                       */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = handle of system nul page */

static inline uint32_t _GetNulPageHandle(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetNulPageHandle)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetFirstV86Page (VMMCall dev=0x0001 serv=0x006B) WINVER=3.0+ */

/* description: */
/*   Return page number of the first page in the current virtual machine */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = first page of V86 memory */

static inline uint32_t _GetFirstV86Page(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetFirstV86Page)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _MapPhysToLinear (VMMCall dev=0x0001 serv=0x006C) WINVER=3.0+ */

/* description: */
/*   Return the linear address of the first byte in the specified range of physical addresses */

/* inputs: */
/*   __CDECL0 = PhysAddr (32-bit physical address of the start of the region to examine) */
/*   __CDECL1 = nBytes (length of bytes of physical region) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = ring-0 linear address of first byte of physical region, or 0xFFFFFFFF if not addressable */

static inline void* _MapPhysToLinear(uint32_t const PhysAddr/*__cdecl0*/,uint32_t const nBytes/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register void* r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__MapPhysToLinear)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (PhysAddr), "g" (nBytes), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetAppFlatDSAlias (VMMCall dev=0x0001 serv=0x006D) WINVER=3.0+ */

/* description: */
/*   Return a ring-3, read-only, GDT selector that provides access to the same memory as the system's ring-0 data segment selector.      */
/*   Virtual devices can use this service to support protected-mode APIs that let protected-mode applications read from the same memory. */

/* inputs: */
/*   None */

/* outputs: */
/*   EAX = read-only GDT selector */

static inline uint32_t _GetAppFlatDSAlias(void) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetAppFlatDSAlias)
        : /* outputs */ "=a" (r)
        : /* inputs */
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _SelectorMapFlat (VMMCall dev=0x0001 serv=0x006E) WINVER=3.0+ */

/* description: */
/*   Return the base address of the specified GDT or LDT selector.                                 */
/*   Address mapper code can use this to convert segment:offset pointers to flat linear addresses. */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = Selector (GDT or LDT selector) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   None */

static inline void _SelectorMapFlat(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const Selector/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    __asm__ (
        "push %2\n"
        "push %1\n"
        "push %0\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__SelectorMapFlat)
        "addl $12,%%esp\n"
        : /* outputs */
        : /* inputs */ "g" (VM), "g" (Selector), "g" (flags)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/*

    Data structure for _GetDemandPageInfo

 */
#pragma pack(push,1)
/* struct DemandInfoStruc */
typedef struct DemandInfoStruc {
    uint32_t        DILin_Total_Count;              /* +0x0000 # pages in linear address space */
    uint32_t        DIPhys_Count;                   /* +0x0004 Count of phys pages */
    uint32_t        DIFree_Count;                   /* +0x0008 Count of free phys pages */
    uint32_t        DIUnlock_Count;                 /* +0x000C Count of unlocked Phys Pages */
    uint32_t        DILinear_Base_Addr;             /* +0x0010 Base of pageable address space */
    uint32_t        DILin_Total_Free;               /* +0x0014 Total Count of free linear pages */
    uint32_t        DIReserved[10];                 /* +0x0018 Resvd for expansion */
} DemandInfoStruc;
/* end DemandInfoStruc (total 0x0040 bytes) */
#pragma pack(pop)
/*-------------------------------------------------------------*/

/*-------------------------------------------------------------*/
/* VMM _GetDemandPageInfo (VMMCall dev=0x0001 serv=0x006F) WINVER=3.0+ */

/* description: */
/*   Retrieve information used for demand paging, copying the information to the specified structure. */
/*   For exclusive use by the virtual paging device.                                                  */

/* inputs: */
/*   __CDECL0 = DemandInfo (structure to fill) */
/*   __CDECL1 = flags (operation flags, must be zero) */

/* outputs: */
/*   None */

static inline void _GetDemandPageInfo(DemandInfoStruc* const DemandInfo/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    __asm__ (
        "push %1\n"
        "push %0\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetDemandPageInfo)
        "addl $8,%%esp\n"
        : /* outputs */
        : /* inputs */ "g" (DemandInfo), "g" (flags)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* description: */
/*   Flags for _GetSetPageOutCount                             */
/*                                                             */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 718 */
#define GSPOC_F_Get 0x00000001U /* 1U << 0U bit[0] Return the current value of the page out count, NewCount is ignored */

/*-------------------------------------------------------------*/
/* VMM _GetSetPageOutCount (VMMCall dev=0x0001 serv=0x0070) WINVER=3.0+ */

/* description: */
/*   Set or return the page out count. For exclusive use by the virtual paging device. */

/* inputs: */
/*   __CDECL0 = NewCount (new page out count, if GSPOC_F_Get is NOT set in flags) */
/*   __CDECL1 = flags (oprating flags, GSPOC_F_*) */

/* outputs: */
/*   EAX = page out count, if GSPOC_F_Get is given in flags */

static inline uint32_t _GetSetPageOutCount(uint32_t const NewCount/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetSetPageOutCount)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (NewCount), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_V86_Page (VMMCall dev=0x0001 serv=0x0071) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure to handle faults for the specified page.                                             */
/*   Virtual devices, such as the virtual display device, use this to detect when certain address ranges are accessed. */

/* inputs: */
/*   EAX = PageNum (page number, must be between the last v86 page and 0xFF inclusive) */
/*   ESI = Callback (pointer to callback procedure) */

/* outputs: */
/*   !CF = clear if success, set if failure */

static inline _Bool Hook_V86_Page(uint32_t const PageNum/*eax*/,const void* const Callback/*esi*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_V86_Page)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "a" (PageNum), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _Assign_Device_V86_Pages (VMMCall dev=0x0001 serv=0x0072) WINVER=3.0+ */

/* description: */
/*   Assign to a virtual device one or more pages of the V86 address space. */

/* inputs: */
/*   __CDECL0 = VMLinrPage (Linear page number of the first page of V86 address space to assign. Must be 0 to 0x10F inclusive) */
/*   __CDECL1 = nPages (number of pages to assign) */
/*   __CDECL2 = VM (VM handle to assign to, or zero to apply to all virtual machines) */
/*   __CDECL3 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if successful, zero if not */

static inline uint32_t _Assign_Device_V86_Pages(uint32_t const VMLinrPage/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,vxd_vm_handle_t const VM/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Assign_Device_V86_Pages)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VMLinrPage), "g" (nPages), "g" (VM), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _DeAssign_Device_V86_Pages (VMMCall dev=0x0001 serv=0x0073) WINVER=3.0+ */

/* description: */
/*   Unassign a region in the V86 address space assigned by _Assign_Device_V86_Pages */

/* inputs: */
/*   __CDECL0 = VMLinrPage (Linear page number of the first page of V86 address space to assign. Must be 0 to 0x10F inclusive) */
/*   __CDECL1 = nPages (number of pages to assign) */
/*   __CDECL2 = VM (VM handle to assign to, or zero to apply to all virtual machines) */
/*   __CDECL3 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if successful, zero if not */

static inline uint32_t _DeAssign_Device_V86_Pages(uint32_t const VMLinrPage/*__cdecl0*/,uint32_t const nPages/*__cdecl1*/,vxd_vm_handle_t const VM/*__cdecl2*/,uint32_t const flags/*__cdecl3*/) {
    register uint32_t r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__DeAssign_Device_V86_Pages)
        "addl $16,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VMLinrPage), "g" (nPages), "g" (VM), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _Get_Device_V86_Pages_Array (VMMCall dev=0x0001 serv=0x0074) WINVER=3.0+ */

/* description: */
/*   Retrive a copy of the assignment array used by the _Assign_Device_V86_Pages and _DeAssign_Device_V86_Pages.        */
/*   Virtual devices can use this to determine which regions of the V86 address space are currently assigned.           */
/*                                                                                                                      */
/*   The meaning of each bit is whether or not the page is assigned.                                                    */
/*   The global array does not indicate whether the page is assigned locally.                                           */
/*   A page is available for global assignment only if neither global nor locally assigned.                             */
/*   A virtual device must check both global and local array to determine if a page is available for global assignment. */

/* inputs: */
/*   __CDECL0 = VM (VM handle, or 0 for global assignment array) */
/*   __CDECL1 = ArrayBuf (pointer to a 36-byte (0x110-bit) buffer that receives the assignment array) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if successful, zero if not */

static inline uint32_t _Get_Device_V86_Pages_Array(vxd_vm_handle_t const VM/*__cdecl0*/,void* const ArrayBuf/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Get_Device_V86_Pages_Array)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (ArrayBuf), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM MMGR_SetNULPageAddr (VMMCall dev=0x0001 serv=0x0075) WINVER=3.0+ */

/* description: */
/*   Set the physical address of the system nul page.                                          */
/*   For exclusive use by the virtual V86MMGR device, called during the Init_Complete message, */
/*   to set the address of a known nonexistent page in the system.                             */

/* inputs: */
/*   EAX = PhysAddr (physical page address (page number << 12) of system nul page) */

/* outputs: */
/*   None */

static inline void MMGR_SetNULPageAddr(uint32_t const PhysAddr/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_MMGR_SetNULPageAddr)
        : /* outputs */
        : /* inputs */ "a" (PhysAddr)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM _Allocate_GDT_Selector (VMMCall dev=0x0001 serv=0x0076) WINVER=3.0+ */

/* description: */
/*   Create a selector and add it to the Global Descriptor Table. */

/* inputs: */
/*   __CDECL0 = DescDWORD1 (High DWORD of the descriptor (high 16 bits of base addr, high 4 bits of limit, status, type)) */
/*   __CDECL1 = DescDWORD2 (Low DWORD of the descriptor (low 16 bits of base addr, limit)) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   EDX = SelCount (selector for GDT (low 16 bits) and size of GDT (upper 16 bits)) */
/*   EAX = GDTSel (selector for the GDT, or zero if failure) */

typedef struct _Allocate_GDT_Selector__response {
    uint32_t GDTSel; /* EAX */
    uint32_t SelCount; /* EDX */
} _Allocate_GDT_Selector__response;

static inline _Allocate_GDT_Selector__response _Allocate_GDT_Selector(uint32_t const DescDWORD1/*__cdecl0*/,uint32_t const DescDWORD2/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register _Allocate_GDT_Selector__response r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Allocate_GDT_Selector)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r.GDTSel), "=d" (r.SelCount)
        : /* inputs */ "g" (DescDWORD1), "g" (DescDWORD2), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _Free_GDT_Selector (VMMCall dev=0x0001 serv=0x0077) WINVER=3.0+ */

/* description: */
/*   Free a GDT selector previously allocated using the Allocate_GDT_Selector service. */

/* inputs: */
/*   __CDECL0 = Selector (Selector to free (allocated by Allocate_GDT_Selector)) */
/*   __CDECL1 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _Free_GDT_Selector(uint32_t const Selector/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Free_GDT_Selector)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (Selector), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _Allocate_LDT_Selector (VMMCall dev=0x0001 serv=0x0078) WINVER=3.0+ */

/* description: */
/*   Create a selector and add it to the Local Descriptor Table of a virtual machine. */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = DescDWORD1 (High DWORD of the descriptor (high 16 bits of base addr, high 4 bits of limit, status, type)) */
/*   __CDECL2 = DescDWORD2 (Low DWORD of the descriptor (low 16 bits of base addr, limit)) */
/*   __CDECL3 = Count (number of contiguous LDT selectors to allocate if flags param does not specify ALDTSpecSel) */
/*   __CDECL4 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = Selector (Selector of LDT (first one, if multiple allocated) or zero if error) */
/*   EDX = SelCount (selector for LDT (low 16 bits) and size of LDT (upper 16 bits)) */

typedef struct _Allocate_LDT_Selector__response {
    uint32_t Selector; /* EAX */
    uint32_t SelCount; /* EDX */
} _Allocate_LDT_Selector__response;

static inline _Allocate_LDT_Selector__response _Allocate_LDT_Selector(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const DescDWORD1/*__cdecl1*/,uint32_t const DescDWORD2/*__cdecl2*/,uint32_t const Count/*__cdecl3*/,uint32_t const flags/*__cdecl4*/) {
    register _Allocate_LDT_Selector__response r;

    __asm__ (
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Allocate_LDT_Selector)
        "addl $20,%%esp\n"
        : /* outputs */ "=d" (r.SelCount), "=a" (r.Selector)
        : /* inputs */ "g" (VM), "g" (DescDWORD1), "g" (DescDWORD2), "g" (Count), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _Free_LDT_Selector (VMMCall dev=0x0001 serv=0x0079) WINVER=3.0+ */

/* description: */
/*   Free a LDT selector previously allocated using the Allocate_LDT_Selector service. */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = Selector (Selector to free) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _Free_LDT_Selector(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const Selector/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register uint32_t r;

    __asm__ (
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__Free_LDT_Selector)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (Selector), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Flags for _BuildDescriptorDWORDs                          */
/*                                                             */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 740 */
#define BDDExplicitDPL 0x00000001U /* 1U << 0U bit[0] Use DPL bits in the DESCType param */

/*-------------------------------------------------------------*/
/* VMM _BuildDescriptorDWORDs (VMMCall dev=0x0001 serv=0x007A) WINVER=3.0+ */

/* description: */
/*   Build a descriptor parameter used in calls to _Allocate_GDT_Selector and _Allocate_LDT_Selector. */
/*                                                                                                    */
/*   flags:                                                                                           */
/*   - BDDExplicitDPL: use the DPL bits in the DESCType parameter. If not specified, the call will    */
/*   - set the DPL bits to the value of the RPL bits for protected applications.                      */

/* inputs: */
/*   __CDECL0 = DESCBase (32-bit base address) */
/*   __CDECL1 = DESCLimit (20-bit limit for the descriptor) */
/*   __CDECL2 = DESCType (present bit, DPL, type (only low 8 bits valid, others must be zero)) */
/*   __CDECL3 = DESCSize (granularity, big/default. only bits 4-7 are valid, others must be zero) */
/*   __CDECL4 = flags (operation flags) */

/* outputs: */
/*   EAX = desc_lo (low DWORD of descriptor) */
/*   EDX = desc_hi (high DWORD of descriptor) */

typedef struct _BuildDescriptorDWORDs__response {
    uint32_t desc_lo; /* EAX */
    uint32_t desc_hi; /* EDX */
} _BuildDescriptorDWORDs__response;

static inline _BuildDescriptorDWORDs__response _BuildDescriptorDWORDs(uint32_t const DESCBase/*__cdecl0*/,uint32_t const DESCLimit/*__cdecl1*/,uint32_t const DESCType/*__cdecl2*/,uint32_t const DESCSize/*__cdecl3*/,uint32_t const flags/*__cdecl4*/) {
    register _BuildDescriptorDWORDs__response r;

    __asm__ (
        "push %6\n"
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__BuildDescriptorDWORDs)
        "addl $20,%%esp\n"
        : /* outputs */ "=a" (r.desc_lo), "=d" (r.desc_hi)
        : /* inputs */ "g" (DESCBase), "g" (DESCLimit), "g" (DESCType), "g" (DESCSize), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _GetDescriptor (VMMCall dev=0x0001 serv=0x007B) WINVER=3.0+ */

/* description: */
/*   Retrieve a copy of the descriptor associated with the given LDT or GDT selector. */

/* inputs: */
/*   __CDECL0 = Selector (GDT or LDT selector) */
/*   __CDECL1 = VM (virtual machine handle to which the LDT belongs, ignored if GDT) */
/*   __CDECL2 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = desc_lo (low DWORD of descriptor) */
/*   EDX = desc_hi (high DWORD of descriptor) */

typedef struct _GetDescriptor__response {
    uint32_t desc_lo; /* EAX */
    uint32_t desc_hi; /* EDX */
} _GetDescriptor__response;

static inline _GetDescriptor__response _GetDescriptor(uint32_t const Selector/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const flags/*__cdecl2*/) {
    register _GetDescriptor__response r;

    __asm__ (
        "push %4\n"
        "push %3\n"
        "push %2\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__GetDescriptor)
        "addl $12,%%esp\n"
        : /* outputs */ "=a" (r.desc_lo), "=d" (r.desc_hi)
        : /* inputs */ "g" (Selector), "g" (VM), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM _SetDescriptor (VMMCall dev=0x0001 serv=0x007C) WINVER=3.0+ */

/* description: */
/*   Set the descriptor for the given LDT or GDT selector. */

/* inputs: */
/*   __CDECL0 = Selector (GDT or LDT descriptor) */
/*   __CDECL1 = VM (virtual machine handle to which the LDT belongs, ignored if GDT) */
/*   __CDECL2 = DescDWORD1 (low DWORD of descriptor) */
/*   __CDECL3 = DescDWORD2 (high DWORD of descriptor) */
/*   __CDECL4 = flags (operation flags, must be zero) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure */

static inline uint32_t _SetDescriptor(uint32_t const Selector/*__cdecl0*/,vxd_vm_handle_t const VM/*__cdecl1*/,uint32_t const DescDWORD1/*__cdecl2*/,uint32_t const DescDWORD2/*__cdecl3*/,uint32_t const flags/*__cdecl4*/) {
    register uint32_t r;

    __asm__ (
        "push %5\n"
        "push %4\n"
        "push %3\n"
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__SetDescriptor)
        "addl $20,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (Selector), "g" (VM), "g" (DescDWORD1), "g" (DescDWORD2), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Flags for _MMGR_Toggle_HMA                                */
/*                                                             */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 754 */
#define MMGRHMAPhysical 0x00000001U /* 1U << 0U bit[0] */
#define MMGRHMAEnable   0x00000002U /* 1U << 1U bit[1] */
#define MMGRHMADisable  0x00000004U /* 1U << 2U bit[2] */
#define MMGRHMAQuery    0x00000008U /* 1U << 3U bit[3] */

/*-------------------------------------------------------------*/
/* VMM _MMGR_Toggle_HMA (VMMCall dev=0x0001 serv=0x007D) WINVER=3.0+ */

/* description: */
/*   Enable or disable the high memory area.                                                            */
/*   For use by the V86MMGR XMS device to control the state of the HMA for a specified virtual machine. */

/* inputs: */
/*   __CDECL0 = VM (VM handle) */
/*   __CDECL1 = flags (operation flags (MMGRHMA*)) */

/* outputs: */
/*   EAX = nonzero if success, zero if failure. if MMGRHMAQuery is specified, nonzero if HMA enabled, zero if disabled. */

static inline uint32_t _MMGR_Toggle_HMA(vxd_vm_handle_t const VM/*__cdecl0*/,uint32_t const flags/*__cdecl1*/) {
    register uint32_t r;

    __asm__ (
        "push %2\n"
        "push %1\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr__MMGR_Toggle_HMA)
        "addl $8,%%esp\n"
        : /* outputs */ "=a" (r)
        : /* inputs */ "g" (VM), "g" (flags)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Fault_Hook_Addrs (VMMCall dev=0x0001 serv=0x007E) WINVER=3.0+ */

/* description: */
/*   Return addresses of the V86 mode, protected-mode, and VMM fault handlers for a specific fault */

/* inputs: */
/*   EAX = Interrupt (interrupt number) */

/* outputs: */
/*   !CF = Success (CF=0 if success, CF=1 if error) */
/*   EDI = FaultHandler_VMM (address of VMM fault handler, or zero if none installed) */
/*   ESI = FaultHandler_PM (address of protected mode fault handler, or zero if none installed) */
/*   EDX = FaultHandler_V86 (address of V86 fault handler, or zero if none installed) */

/* returns: */
/*   Success==1 if success, handler addresses */

typedef struct Get_Fault_Hook_Addrs__response {
    _Bool Success; /* !CF */
    uint32_t FaultHandler_V86; /* EDX */
    uint32_t FaultHandler_PM; /* ESI */
    uint32_t FaultHandler_VMM; /* EDI */
} Get_Fault_Hook_Addrs__response;

static inline Get_Fault_Hook_Addrs__response Get_Fault_Hook_Addrs(uint32_t const Interrupt/*eax*/) {
    register Get_Fault_Hook_Addrs__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Fault_Hook_Addrs)
        : /* outputs */ "=@ccnc" (r.Success), "=S" (r.FaultHandler_PM), "=d" (r.FaultHandler_V86), "=D" (r.FaultHandler_VMM)
        : /* inputs */ "a" (Interrupt)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_V86_Fault (VMMCall dev=0x0001 serv=0x007F) WINVER=3.0+ */

/* description: */
/*   Install a fault handler for V86 mode.                                                                                                             */
/*   Typically a virtual device will use this during Sys_Critical_Init to handle faults (usually GPF) that the VMM's own fault handlers cannot handle. */
/*   The VMM will install it's own fault handlers after the Sys_Critical_Init control message.                                                         */
/*   Virtual devices will install their own after Sys_Critical_Init.                                                                                   */
/*                                                                                                                                                     */
/*   Do not use this service to install a fault handler for the Non-Maskable Interrupt, or for hardware interrupts.                                    */

/* inputs: */
/*   EAX = Interrupt (interrupt number) */
/*   ESI = FaultProc (points to a fault handler) */

/* outputs: */
/*   !CF = Success (carry set if not installed) */
/*   ESI = Previous (previous fault handler, if any, or zero if none was installed) */

typedef struct Hook_V86_Fault__response {
    _Bool Success; /* !CF */
    const void* Previous; /* ESI */
} Hook_V86_Fault__response;

static inline Hook_V86_Fault__response Hook_V86_Fault(uint32_t const Interrupt/*eax*/,const void* const FaultProc/*esi*/) {
    register Hook_V86_Fault__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_V86_Fault)
        : /* outputs */ "=S" (r.Previous), "=@ccnc" (r.Success)
        : /* inputs */ "a" (Interrupt), "S" (FaultProc)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_PM_Fault (VMMCall dev=0x0001 serv=0x0080) WINVER=3.0+ */

/* description: */
/*   Install a fault handler for protected mode.                                                                                                       */
/*   Typically a virtual device will use this during Sys_Critical_Init to handle faults (usually GPF) that the VMM's own fault handlers cannot handle. */
/*   The VMM will install it's own fault handlers after the Sys_Critical_Init control message.                                                         */
/*   Virtual devices will install their own after Sys_Critical_Init.                                                                                   */
/*                                                                                                                                                     */
/*   Do not use this service to install a fault handler for the Non-Maskable Interrupt, or for hardware interrupts.                                    */

/* inputs: */
/*   EAX = Interrupt (interrupt number) */
/*   ESI = FaultProc (points to a fault handler) */

/* outputs: */
/*   !CF = Success (carry set if not installed) */
/*   ESI = Previous (previous fault handler, if any, or zero if none was installed) */

typedef struct Hook_PM_Fault__response {
    _Bool Success; /* !CF */
    const void* Previous; /* ESI */
} Hook_PM_Fault__response;

static inline Hook_PM_Fault__response Hook_PM_Fault(uint32_t const Interrupt/*eax*/,const void* const FaultProc/*esi*/) {
    register Hook_PM_Fault__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_PM_Fault)
        : /* outputs */ "=S" (r.Previous), "=@ccnc" (r.Success)
        : /* inputs */ "a" (Interrupt), "S" (FaultProc)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_VMM_Fault (VMMCall dev=0x0001 serv=0x0081) WINVER=3.0+ */

/* description: */
/*   Install a fault handler for the VMM.                                                                                                              */
/*   Typically a virtual device will use this during Sys_Critical_Init to handle faults (usually GPF) that the VMM's own fault handlers cannot handle. */
/*   The VMM will install it's own fault handlers after the Sys_Critical_Init control message.                                                         */
/*   Virtual devices will install their own after Sys_Critical_Init.                                                                                   */
/*                                                                                                                                                     */
/*   Do not use this service to install a fault handler for the Non-Maskable Interrupt, or for hardware interrupts.                                    */

/* inputs: */
/*   EAX = Interrupt (interrupt number) */
/*   ESI = FaultProc (points to a fault handler) */

/* outputs: */
/*   ESI = Previous (previous fault handler, if any, or zero if none was installed) */
/*   !CF = Success (carry set if not installed) */

typedef struct Hook_VMM_Fault__response {
    _Bool Success; /* !CF */
    const void* Previous; /* ESI */
} Hook_VMM_Fault__response;

static inline Hook_VMM_Fault__response Hook_VMM_Fault(uint32_t const Interrupt/*eax*/,const void* const FaultProc/*esi*/) {
    register Hook_VMM_Fault__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_VMM_Fault)
        : /* outputs */ "=S" (r.Previous), "=@ccnc" (r.Success)
        : /* inputs */ "a" (Interrupt), "S" (FaultProc)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Begin_Nest_V86_Exec (VMMCall dev=0x0001 serv=0x0082) WINVER=3.0+ */

/* description: */
/*   Set the current virtual machine to V86 mode and prepare the virtual machine for nested execution.                 */
/*   Virtual machines use this service to call software in the virtual machine.                                        */
/*                                                                                                                     */
/*   On return, the Client_CS and Client_IP registers point to a break point used by the nested execution services.    */
/*                                                                                                                     */
/*   This service saves the current execution mode of the virtual machine, which End_Nest_Exec later restores.         */
/*                                                                                                                     */
/*   This service should only be used by the virtual devices that convert protected-mode calls into V86 calls.         */
/*   The virtual MS-DOS manager uses this for example to map INT 21h calls from protected mode into calls in V86 mode. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Begin_Nest_V86_Exec(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Begin_Nest_V86_Exec)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Begin_Nest_Exec (VMMCall dev=0x0001 serv=0x0083) WINVER=3.0+ */

/* description: */
/*   Starts a nested execution block. Virtual devices use these services to call software in the virtual machine.       */
/*                                                                                                                      */
/*   On return, the Client_CS and Client_IP registers point to a break point used by the nested execution services.     */
/*                                                                                                                      */
/*   If the call changes the virtual machine registers, the changes are reflected in the client state.                  */
/*   Before creating the nested execution block, a virtual device should save the client state using Save_Client_State. */
/*   After ending the execution block, the virtual device should restore the client state using Restore_Client_State.   */
/*                                                                                                                      */
/*   This service forces the virtual machine into protected mode if there is a protected mode application running in    */
/*   the current virtual machine, otherwise the virtual machine remains in V86 mode. End_Nest_Exec will restore the     */
/*   virtual machine to the mode it was running prior to Begin_Nest_Exec.                                               */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Begin_Nest_Exec(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Begin_Nest_Exec)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Exec_Int (VMMCall dev=0x0001 serv=0x0084) WINVER=3.0+ */

/* description: */
/*   Simulates the specified interrupt and resumes execution of the virtual machine.                                    */
/*   This service may only be called within a nested execution block created by Begin_Nest_Exec or Begin_Nest_V86_Exec. */

/* inputs: */
/*   EAX = Interrupt (interrupt number to execute) */

/* outputs: */
/*   None */

static inline void Exec_Int(uint32_t const Interrupt/*eax*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Exec_Int)
        : /* outputs */
        : /* inputs */ "a" (Interrupt)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Resume_Exec (VMMCall dev=0x0001 serv=0x0085) WINVER=3.0+ */

/* description: */
/*   Immediately execute the current virtual machine.                                                                   */
/*   This service may only be called within a nested execution block created by Begin_Nest_Exec or Begin_Nest_V86_Exec. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Resume_Exec(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Resume_Exec)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM End_Nest_Exec (VMMCall dev=0x0001 serv=0x0086) WINVER=3.0+ */

/* description: */
/*   End a nested execution block.                                                                                     */
/*                                                                                                                     */
/*   On return, Client_CS and Client_IP contain the original values saved when the nested execution block was created. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void End_Nest_Exec(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_End_Nest_Exec)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Allocate_PM_App_CB_Area (VMMCall dev=0x0001 serv=0x0087) WINVER=3.0+ */

/* description: */
/*   Allocate space in the control block of the current virtual machine for a protected-mode application control block.                    */
/*   This call is only available during initialization (of the VM?).                                                                       */
/*   This call returns the offset from the beginning of the virtual machine control block to the protected-mode application control block. */

/* inputs: */
/*   ECX = Size (number of bytes to reserve) */

/* outputs: */
/*   EAX = offset of application control block */

static inline uint32_t Allocate_PM_App_CB_Area(uint32_t const Size/*ecx*/) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Allocate_PM_App_CB_Area)
        : /* outputs */ "=a" (r)
        : /* inputs */ "c" (Size)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Get_Cur_PM_App_CB (VMMCall dev=0x0001 serv=0x0088) WINVER=3.0+ */

/* description: */
/*   Return a pointer to the application control block for a protected-mode application. */

/* inputs: */
/*   EBX = VM (handle of VM running protected mode application) */

/* outputs: */
/*   EDI = address of application control block */

static inline void* Get_Cur_PM_App_CB(vxd_vm_handle_t const VM/*ebx*/) {
    register void* r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Get_Cur_PM_App_CB)
        : /* outputs */ "=D" (r)
        : /* inputs */ "b" (VM)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Set_V86_Exec_Mode (VMMCall dev=0x0001 serv=0x0089) WINVER=3.0+ */

/* description: */
/*   Force the current virtual machine into V86 mode. If already in V86 mode, this call has no effect. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Set_V86_Exec_Mode(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_V86_Exec_Mode)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Set_PM_Exec_Mode (VMMCall dev=0x0001 serv=0x008A) WINVER=3.0+ */

/* description: */
/*   Force the current virtual machine into protected mode. If already in protected mode, this call has no effect. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Set_PM_Exec_Mode(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Set_PM_Exec_Mode)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Begin_Use_Locked_PM_Stack (VMMCall dev=0x0001 serv=0x008B) WINVER=3.0+ */

/* description: */
/*   Lock the protected mode stack, to prevent demand paging of the stack.                                  */
/*                                                                                                          */
/*   The client VM SS:SP registers are updated with the address of the locked stack, if not already locked. */
/*   Otherwise, the client registers are unchanged.                                                         */
/*                                                                                                          */
/*   The calling device is responsible for checking that the VM is running in protected mode, according     */
/*   to VMStat_PM_Exec and the CB_VM_Status field.                                                          */
/*                                                                                                          */
/*   Devices are allowed to call this multiple times, only the first call has effect.                       */
/*   Each call increments a counter. If a device locks the stack, it must eventually unlock the             */
/*   stack using End_Use_Locked_PM_Stack service.                                                           */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void Begin_Use_Locked_PM_Stack(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Begin_Use_Locked_PM_Stack)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM End_Use_Locked_PM_Stack (VMMCall dev=0x0001 serv=0x008C) WINVER=3.0+ */

/* description: */
/*   Unlock the protected mode stack, when locked by Begin_Use_Locked_PM_Stack.                                  */
/*                                                                                                               */
/*   This call decrements a locked stack counter, and restores the previous VM SS:SP stack pointer               */
/*   when the counter reaches zero.                                                                              */
/*                                                                                                               */
/*   If the locked stack counter does not reach zero after this call, the VM's SS:SP stack pointer is unchanged. */

/* inputs: */
/*   None */

/* outputs: */
/*   None */

static inline void End_Use_Locked_PM_Stack(void) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_End_Use_Locked_PM_Stack)
        : /* outputs */
        : /* inputs */
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Save_Client_State (VMMCall dev=0x0001 serv=0x008D) WINVER=3.0+ */

/* description: */
/*   Copy the contents of the current VM's Client_Reg_Struc to the specified buffer. */

/* inputs: */
/*   EDI = Buffer (Buffer to receive the client state. Must be at least the size of the client reg struct) */

/* outputs: */
/*   None */

static inline void Save_Client_State(void* const Buffer/*edi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Save_Client_State)
        : /* outputs */
        : /* inputs */ "D" (Buffer)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Restore_Client_State (VMMCall dev=0x0001 serv=0x008E) WINVER=3.0+ */

/* description: */
/*   Restore the contents of the current VM's Client_Reg_Struc from the specified buffer.                              */
/*                                                                                                                     */
/*   This will change execution mode if the restore state is different.                                                */
/*   This may change the state of the interrupt flag, causing the system to call event callbacks previously scheduled. */

/* inputs: */
/*   ESI = Buffer (Buffer containing the client state, saved from Save_Client_State) */

/* outputs: */
/*   None */

static inline void Restore_Client_State(const void* const Buffer/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Restore_Client_State)
        : /* outputs */
        : /* inputs */ "S" (Buffer)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Exec_VxD_Int (VMMCall dev=0x0001 serv=0x008F) WINVER=3.0+ */

/* description: */
/*   Execute the specified software interrupt. Devices use this service to call MS-DOS or the BIOS, outside the scope of a nested execution block. */
/*   The device should set CPU registers for the call, then call this service.                                                                     */
/*   CPU registers will be updated on return according to the call, including flags.                                                               */
/*                                                                                                                                                 */
/*   This service should not be called directly, but only from inline ASM.                                                                         */

/* inputs: */
/*   __CDECL0 = Interrupt (Interrupt number to call) */
/*   EAX = in_eax (EAX input) */
/*   EBX = in_ebx (EBX input) */
/*   ECX = in_ecx (ECX input) */
/*   EDX = in_edx (EDX input) */
/*   ESI = in_esi (ESI input) */
/*   EDI = in_edi (EDI input) */

/* outputs: */
/*   EAX = out_eax (EAX output) */
/*   EBX = out_ebx (EBX output) */
/*   ZF = out_zf (ZF flag output) */
/*   ESI = out_esi (ESI output) */
/*   EDX = out_edx (EDX output) */
/*   ECX = out_ecx (ECX output) */
/*   CF = out_cf (CF flag output) */
/*   EDI = out_edi (EDI output) */

typedef struct Exec_VxD_Int__response {
    uint32_t out_eax; /* EAX */
    uint32_t out_ebx; /* EBX */
    uint32_t out_ecx; /* ECX */
    uint32_t out_edx; /* EDX */
    uint32_t out_esi; /* ESI */
    uint32_t out_edi; /* EDI */
    _Bool out_cf; /* CF */
    _Bool out_zf; /* ZF */
} Exec_VxD_Int__response;

static inline Exec_VxD_Int__response Exec_VxD_Int(uint32_t const Interrupt/*__cdecl0*/,uint32_t const in_eax/*eax*/,uint32_t const in_ebx/*ebx*/,uint32_t const in_ecx/*ecx*/,uint32_t const in_edx/*edx*/,uint32_t const in_esi/*esi*/,uint32_t const in_edi/*edi*/) {
    register Exec_VxD_Int__response r;

    __asm__ (
        "push %8\n"
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Exec_VxD_Int)
        "addl $4,%%esp\n"
        : /* outputs */ "=D" (r.out_edi), "=@ccc" (r.out_cf), "=d" (r.out_edx), "=S" (r.out_esi), "=c" (r.out_ecx), "=@ccz" (r.out_zf), "=b" (r.out_ebx), "=a" (r.out_eax)
        : /* inputs */ "g" (Interrupt), "a" (in_eax), "b" (in_ebx), "c" (in_ecx), "d" (in_edx), "S" (in_esi), "D" (in_edi)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_Device_Service (VMMCall dev=0x0001 serv=0x0090) WINVER=3.0+ */

/* description: */
/*   This service allows a device to monitor or replace the services of another virtual device. */
/*   The hook should preserve the full functionality of the virtual device being hooked.        */
/*   More than one virtual device can hook a service. The last hook installed is called first.  */
/*   The hook procedure must save and restore registers that are not modified by the service,   */
/*   including flags. If the service uses the C calling convention, the hook procedure must     */
/*   preserve those across the call as well.                                                    */

/* inputs: */
/*   EAX = Service (service to hook) */
/*   ESI = HookProc (hook procedure) */

/* outputs: */
/*   !CF = CF set if error, so return value nonzero if success */

static inline _Bool Hook_Device_Service(uint32_t const Service/*eax*/,const void* const HookProc/*esi*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_Device_Service)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "a" (Service), "S" (HookProc)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_Device_V86_API (VMMCall dev=0x0001 serv=0x0091) WINVER=3.0+ */

/* description: */
/*   Installs an API callback procedure that allows a virtual device to intercept calls to    */
/*   the V86 mode API of another device. This is meant for devices that need to monitor calls */
/*   to the APIs of other devices.                                                            */

/* inputs: */
/*   EAX = ID (device ID) */
/*   ESI = Callback (API callback) */

/* outputs: */
/*   !CF = Success (CF set if error, return value nonzero if success) */
/*   ESI = PreviousCallback (previous callback if success) */

typedef struct Hook_Device_V86_API__response {
    const void* PreviousCallback; /* ESI */
    _Bool Success; /* !CF */
} Hook_Device_V86_API__response;

static inline Hook_Device_V86_API__response Hook_Device_V86_API(uint32_t const ID/*eax*/,const void* const Callback/*esi*/) {
    register Hook_Device_V86_API__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_Device_V86_API)
        : /* outputs */ "=@ccnc" (r.Success), "=S" (r.PreviousCallback)
        : /* inputs */ "a" (ID), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Hook_Device_PM_API (VMMCall dev=0x0001 serv=0x0092) WINVER=3.0+ */

/* description: */
/*   Installs an API callback procedure that allows a virtual device to intercept calls to          */
/*   the protected mode API of another device. This is meant for devices that need to monitor calls */
/*   to the APIs of other devices.                                                                  */

/* inputs: */
/*   EAX = ID (device ID) */
/*   ESI = Callback (API callback) */

/* outputs: */
/*   !CF = Success (CF set if error, return value nonzero if success) */
/*   ESI = PreviousCallback (previous callback if success) */

typedef struct Hook_Device_PM_API__response {
    const void* PreviousCallback; /* ESI */
    _Bool Success; /* !CF */
} Hook_Device_PM_API__response;

static inline Hook_Device_PM_API__response Hook_Device_PM_API(uint32_t const ID/*eax*/,const void* const Callback/*esi*/) {
    register Hook_Device_PM_API__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Hook_Device_PM_API)
        : /* outputs */ "=S" (r.PreviousCallback), "=@ccnc" (r.Success)
        : /* inputs */ "a" (ID), "S" (Callback)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM System_Control (VMMCall dev=0x0001 serv=0x0093) WINVER=3.0+ */

/* description: */
/*   This service sends a system control message to all virtual devices and the VMM */

/* inputs: */
/*   EAX = Message (system control message) */
/*   EBX = VM (VM handle, if needed by message) */
/*   ESI = Param1 () */
/*   EDI = Param2 () */
/*   EDX = Param3 () */

/* outputs: */
/*   EDI = out_edi () */
/*   EDX = out_edx () */
/*   ESI = out_esi () */
/*   !CF = Success (CF set if error, return value nonzero if success) */
/*   EAX = out_eax () */
/*   EBX = out_ebx () */

typedef struct System_Control__response {
    _Bool Success; /* !CF */
    uint32_t out_eax; /* EAX */
    uint32_t out_ebx; /* EBX */
    uint32_t out_esi; /* ESI */
    uint32_t out_edi; /* EDI */
    uint32_t out_edx; /* EDX */
} System_Control__response;

static inline System_Control__response System_Control(uint32_t const Message/*eax*/,vxd_vm_handle_t const VM/*ebx*/,uint32_t const Param1/*esi*/,uint32_t const Param2/*edi*/,uint32_t const Param3/*edx*/) {
    register System_Control__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_System_Control)
        : /* outputs */ "=D" (r.out_edi), "=d" (r.out_edx), "=S" (r.out_esi), "=b" (r.out_ebx), "=@ccnc" (r.Success), "=a" (r.out_eax)
        : /* inputs */ "a" (Message), "b" (VM), "S" (Param1), "D" (Param2), "d" (Param3)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* description: */
/*   Type of I/O enumeration, for I/O trap routines             */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 2069 */
#define Byte_Input   0x00000000UL /* 0x00 */
#define Byte_Output  0x00000004UL /* 0x04 */
#define Word_Input   0x00000008UL /* 0x08 */
#define Word_Output  0x0000000CUL /* 0x0C */
#define Dword_Input  0x00000010UL /* 0x10 */
#define Dword_Output 0x00000014UL /* 0x14 */

/*-------------------------------------------------------------*/
/* description: */
/*   Type of I/O enumeration, for I/O trap routines             */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 2069 */
#define IO_Seg_Mask  0xFFFF0000UL /* 0xffff0000 TODO */
#define IO_Seg_Shift 0x00000010UL /* 0x10 TODO */

/*-------------------------------------------------------------*/
/* description: */
/*   Type of I/O enumeration, for I/O trap routines             */
/*                                                              */
/*   Source: Windows 3.1 DDK, D:\386\INCLUDE\VMM.INC, line 2069 */
#define Output     0x00000004U /* 1U << 2U bit[2] Output operation */
#define Word_IO    0x00000008U /* 1U << 3U bit[3] Word size I/O, 16-bit */
#define Dword_IO   0x00000010U /* 1U << 4U bit[4] Dword size I/O, 32-bit */
#define String_IO  0x00000020U /* 1U << 5U bit[5] Operation is string I/O operation */
#define Rep_IO     0x00000040U /* 1U << 6U bit[6] Operation is rep string I/O operation */
#define Addr_32_IO 0x00000080U /* 1U << 7U bit[7] Operation uses 32-bit addresses */
#define Reverse_IO 0x00000100U /* 1U << 8U bit[8] Operation is reverse string (DF=1) */

/*-------------------------------------------------------------*/
/* VMM Simulate_IO (VMMCall dev=0x0001 serv=0x0094) WINVER=3.0+ */

/* description: */
/*   The purpose of this service is to reduce complex I/O instructions to simpler terms.                 */
/*   I/O callback procedures will jump to this service to handle I/O types it does not directly support. */

/* inputs: */
/*   EAX = Data (data, for output operation) */
/*   EBX = VM (current VM handle) */
/*   ECX = IOType (I/O type, as given to callback) */
/*   EDX = Port (I/O port) */
/*   EBP = crs (Pointer to Client_Reg_Struc) */

/* outputs: */
/*   EAX = input data, if input operation */

static inline uint32_t Simulate_IO(uint32_t const Data/*eax*/,vxd_vm_handle_t const VM/*ebx*/,uint32_t const IOType/*ecx*/,uint32_t const Port/*edx*/,void* const crs/*ebp*/) {
    register uint32_t r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Simulate_IO)
        : /* outputs */ "=a" (r)
        : /* inputs */ "a" (Data), "b" (VM), "c" (IOType), "d" (Port), "ebp" (crs)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Install_Mult_IO_Handlers (VMMCall dev=0x0001 serv=0x0095) WINVER=3.0+ */

/* description: */
/*   Install I/O callback procedures for one or more I/O ports.          */
/*   This service is only available during initialization.               */
/*                                                                       */
/*   The I/O table must be created in code using the Begin_Vxd_IO_Table, */
/*   End_Vxd_IO_Table, and Vxd_IO macros.                                */

/* inputs: */
/*   EDI = IOTable (pointer to a table created using IO table macros) */

/* outputs: */
/*   EDX = BadPort (if failed, the port number that failed) */
/*   !CF = Success (CF set if failed, nonzero if success) */

typedef struct Install_Mult_IO_Handlers__response {
    uint32_t BadPort; /* EDX */
    _Bool Success; /* !CF */
} Install_Mult_IO_Handlers__response;

static inline Install_Mult_IO_Handlers__response Install_Mult_IO_Handlers(const void* const IOTable/*edi*/) {
    register Install_Mult_IO_Handlers__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Install_Mult_IO_Handlers)
        : /* outputs */ "=d" (r.BadPort), "=@ccnc" (r.Success)
        : /* inputs */ "D" (IOTable)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Install_IO_Handler (VMMCall dev=0x0001 serv=0x0096) WINVER=3.0+ */

/* description: */
/*   Install a callback procedure for trapping I/O ports and enables trapping for the specific port. */
/*   This service is only available during initialization.                                           */
/*                                                                                                   */
/*   The callback procedure is called when a program in a virtual machine attempts to access the     */
/*   I/O port.                                                                                       */
/*                                                                                                   */
/*   When called:                                                                                    */
/*   EBX = VM                                                                                        */
/*   ECX = IOType                                                                                    */
/*   EDX = Port                                                                                      */
/*   EBP = pointer to Client_Reg_Struc                                                               */
/*   EAX = Data                                                                                      */
/*   call [IOCallback]                                                                               */
/*   Data = EAX                                                                                      */

/* inputs: */
/*   ESI = IOCallback (Callback procedure) */
/*   EDX = Port (I/O port) */

/* outputs: */
/*   !CF = CF set if failed, nonzero if success */

static inline _Bool Install_IO_Handler(const void* const IOCallback/*esi*/,uint32_t const Port/*edx*/) {
    register _Bool r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Install_IO_Handler)
        : /* outputs */ "=@ccnc" (r)
        : /* inputs */ "S" (IOCallback), "d" (Port)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM Enable_Global_Trapping (VMMCall dev=0x0001 serv=0x0097) WINVER=3.0+ */

/* description: */
/*   Enable I/O port trapping for the specified port, in every virtual machine */

/* inputs: */
/*   EDX = Port (I/O port) */

/* outputs: */
/*   None */

static inline void Enable_Global_Trapping(uint32_t const Port/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Enable_Global_Trapping)
        : /* outputs */
        : /* inputs */ "d" (Port)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Enable_Local_Trapping (VMMCall dev=0x0001 serv=0x0098) WINVER=3.0+ */

/* description: */
/*   Enable I/O port trapping for the specified port in the specified VM */

/* inputs: */
/*   EBX = VM (Virtual machine) */
/*   EDX = Port (I/O port) */

/* outputs: */
/*   None */

static inline void Enable_Local_Trapping(vxd_vm_handle_t const VM/*ebx*/,uint32_t const Port/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Enable_Local_Trapping)
        : /* outputs */
        : /* inputs */ "b" (VM), "d" (Port)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Disable_Global_Trapping (VMMCall dev=0x0001 serv=0x0099) WINVER=3.0+ */

/* description: */
/*   Disable I/O port trapping for the specified port, in every virtual machine */

/* inputs: */
/*   EDX = Port (I/O port) */

/* outputs: */
/*   None */

static inline void Disable_Global_Trapping(uint32_t const Port/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Disable_Global_Trapping)
        : /* outputs */
        : /* inputs */ "d" (Port)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM Disable_Local_Trapping (VMMCall dev=0x0001 serv=0x009A) WINVER=3.0+ */

/* description: */
/*   Disable I/O port trapping for the specified port in the specified VM */

/* inputs: */
/*   EBX = VM (Virtual machine) */
/*   EDX = Port (I/O port) */

/* outputs: */
/*   None */

static inline void Disable_Local_Trapping(vxd_vm_handle_t const VM/*ebx*/,uint32_t const Port/*edx*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_Disable_Local_Trapping)
        : /* outputs */
        : /* inputs */ "b" (VM), "d" (Port)
        : /* clobbered */
    );
}

/*-------------------------------------------------------------*/
/* VMM List_Create (VMMCall dev=0x0001 serv=0x009B) WINVER=3.0+ */

/* description: */
/*   Create a list structure and return a handle to the list. */

/* inputs: */
/*   EAX = Flags (creation flags) */
/*   ECX = NodeSize (size in bytes of node in the list) */

/* outputs: */
/*   ESI = List (list handle if Success) */
/*   !CF = Success (CF set if error, Success set if success) */

typedef struct List_Create__response {
    _Bool Success; /* !CF */
    uint32_t List; /* ESI */
} List_Create__response;

static inline List_Create__response List_Create(uint32_t const Flags/*eax*/,uint32_t const NodeSize/*ecx*/) {
    register List_Create__response r;

    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_List_Create)
        : /* outputs */ "=@ccnc" (r.Success), "=S" (r.List)
        : /* inputs */ "a" (Flags), "c" (NodeSize)
        : /* clobbered */
    );

    return r;
}

/*-------------------------------------------------------------*/
/* VMM List_Destroy (VMMCall dev=0x0001 serv=0x009C) WINVER=3.0+ */

/* description: */
/*   Deallocate all nodes of a list and destroy the list handle. */

/* inputs: */
/*   ESI = List (list handle to destroy) */

/* outputs: */
/*   None */

static inline void List_Destroy(uint32_t const List/*esi*/) {
    __asm__ (
        VXD_AsmCall(VMM_Device_ID,VMM_snr_List_Destroy)
        : /* outputs */
        : /* inputs */ "S" (List)
        : /* clobbered */
    );
}

# endif /*GCC_INLINE_ASM_SUPPORTS_cc_OUTPUT*/
#endif /*defined(__GNUC__)*/
