SECTIONS
{
  .text :
  {
  	KEEP(*(.ddb*))
  	*(.text*)
  	_eh_frame = .;
  	KEEP(*(.eh_frame*))
  	PROVIDE_HIDDEN (__init_array_start = .);
  	KEEP(*(.init_array*))
  	PROVIDE_HIDDEN (__init_array_end = .);
  	PROVIDE_HIDDEN (__fini_array_start = .);
  	KEEP(*(.fini_array*))
  	PROVIDE_HIDDEN (__fini_array_end = .);

  	# now data but we need it in one section
  	
    PROVIDE_HIDDEN (__vxd_control_entry = .);
  	KEEP(*(.vxd_control*))
  	KEEP(*(.vxd_control_end*))
  	*(.data*) 
  	*(.rodata*)
  	*(.bss*) 
  }
  /DISCARD/ :
  {
    *(.comment*)
  }
}