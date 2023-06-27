
.global vxd_control_proc

.text

vxd_control_proc:
	push %esi
	lea __vxd_control_entry, %esi
loop:
	cmpl $-1, (%esi)
	je NotUs
	cmpl (%esi), %eax
	je Found
	addl $8, %esi
	jmp loop
Found:
	movl 4(%esi), %eax
	pop %esi
	call *%eax
	or %eax, %eax
	jnz NoErr
	stc
	ret
NotUs:
	pop %esi
NoErr:
	clc
	ret
