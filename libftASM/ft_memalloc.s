section	.text
		global	_ft_memalloc
		extern	_ft_bzero
		extern	_malloc

_ft_memalloc :
		enter	0, 0
		mov		rsi, rdi
		push	rsi
		call	_malloc
		pop		rsi
		mov		rdi, rax
		call	_ft_bzero

	end :
		leave
		ret
