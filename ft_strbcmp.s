section .text
		global _ft_strbcmp

_ft_strbcmp:
		mov     r8, rdi
		or      r8, rsi
		cmp     r8, 0
		je      equal

	cmp_loop:
		mov     r8, [rdi]
		cmp     r8, 0
		je      bcmp
		cmp     byte [rsi], 0
		je      bcmp
		cmp     r8b, byte [rsi]
		ja      greater
		jb      lower
		inc     rdi
		inc     rsi
		jmp     cmp_loop

	bcmp:
		cmp     r8b, byte [rsi]
		ja      greater
		jb      lower
		je      equal

	equal:
		mov     rax, 0
		ret

	greater:
		mov     rax, 1
		ret

	lower:
		mov     rax, -1
		ret
