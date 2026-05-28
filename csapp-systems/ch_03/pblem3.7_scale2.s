
scale2:
.LFB0:
	.cfi_startproc
	endbr64
	# x in %rdi, y in %rsi, z in %rdx.
	leaq	(%rdi,%rdi,4), %rax		#  rax = 4x + x
	leaq	(%rax,%rsi,2), %rax		# rax = 5x + 2y
	leaq	(%rax,%rdx,8), %rax		# rax = 5x+ 2y + 8z
	ret								# return rax
