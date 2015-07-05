section	.text
		global	_ft_strnew
		extern	_ft_bzero
		extern	_malloc

_ft_strnew :
		enter	0, 0
		inc		rdi
		mov		rsi, rdi
		push	rsi
		call	_malloc
		pop		rsi
		mov		rdi, rax
		call	_ft_bzero

	end :
		leave
		ret
