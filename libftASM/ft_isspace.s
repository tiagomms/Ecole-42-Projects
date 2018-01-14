section	.text
	global _ft_isspace

_ft_isspace:
	enter	0, 0
	cmp		rdi, 32
	je		ok
	cmp		rdi, 9
	je		ok
	cmp		rdi, 11
	je		ok
	cmp		rdi, 10
	je		ok
	cmp		rdi, 13
	je		ok
	cmp		rdi, 12
	je		ok
	mov		rax, 0
	leave
	ret

	ok:
	mov		rax, 1
	leave
	ret
