test:
.LFB0:
	.cfi_startproc
	endbr64
	# x in %rdi, y in %rsi , z in %rdx
	leaq	(%rdi,%rsi), %rax
	addq	%rdx, %rax			# rax = x + y + z
	cmpq	$-3, %rdi			# if  x < -3
	jge	.L2						# branch1
	cmpq	%rdx, %rsi			# if y < z
	jge	.L3						# branch2
	movq	%rdi, %rax			
	imulq	%rsi, %rax			# rax = x * y
	ret							# return rax
.L3:							# else, from branch 2 (inner)
	movq	%rsi, %rax			
	imulq	%rdx, %rax			# rax = y * z
	ret							# return rax
.L2:
	cmpq	$2, %rdi			# x > 2
	jle	.L1						
	movq	%rdi, %rax
	imulq	%rdx, %rax			# rax = x * z
.L1:
	ret							# return rax
	.cfi_endproc
