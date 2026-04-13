	.file	"pblem-2.36.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	leaq	.LC0(%rip), %rbx
	xorl	%edx, %edx
	movl	$2, %edi
	movq	%rbx, %rsi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	xorl	%edx, %edx
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	xorl	%edx, %edx
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	xorl	%edx, %edx
	movl	$2, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	movl	$1, %edx
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	movq	%rbx, %rsi
	movl	$1, %edx
	xorl	%eax, %eax
	movl	$2, %edi
	call	__printf_chk@PLT
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.text
	.p2align 4
	.globl	mult_ok
	.type	mult_ok, @function
mult_ok:
.LFB24:
	.cfi_startproc
	endbr64
	movslq	%esi, %rsi
	movslq	%edi, %rdi
	movl	$2147483648, %eax
	imulq	%rsi, %rdi
	addq	%rax, %rdi
	xorl	%eax, %eax
	shrq	$32, %rdi
	sete	%al
	ret
	.cfi_endproc
.LFE24:
	.size	mult_ok, .-mult_ok
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0"
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
