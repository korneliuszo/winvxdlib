SECTIONS
{
  .text :
  {
  	KEEP(*(.ddb*))
  	*(.init*)
  	*(.fini*)
  	*(.text*)
  	_eh_frame = .;
  	*(.eh_frame*)
  	*(.init_array*)
  	*(.fini_array*)
  	
  	# now data but we need it in one section
  	
    __vxd_control_entry = .;
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