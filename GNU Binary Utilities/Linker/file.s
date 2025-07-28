	.file	"file.c"
	.text
	.globl	hello
	.bss
	.type	hello, @object
	.size	hello, 1
hello:
	.zero	1
	.globl	z
	.data
	.align 8
	.type	z, @object
	.size	z, 8
z:
	.quad	10
	.globl	global_constant_var
	.section	.rodata
	.align 4
	.type	global_constant_var, @object
	.size	global_constant_var, 4
global_constant_var:
	.long	10
	.data
	.align 4
	.type	static_global_initialized, @object
	.size	static_global_initialized, 4
static_global_initialized:
	.long	4
	.align 4
	.type	static_glob_uninit, @object
	.size	static_glob_uninit, 4
static_glob_uninit:
	.long	5
	.section	.rodata
.LC0:
	.string	"File main is running!"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$5, -8(%rbp)
	movl	$0, %eax
	call	func@PLT
	movl	%eax, -4(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
