section .text
		global _ft_strcpy

_ft_strcpy:
		enter		0, 0
		cmp			rsi, 0
		je			null
		cmp			rdi, 0
		je			null
		mov			rbx, rdi
		mov			rax, rdi

	loop:
		cmp			[rsi], byte 0
		je			end
		mov			bl, [rsi]
		mov			[rdi], bl
		inc			rdi
		inc			rsi
		jmp			loop

	null:
		mov			rax, 0
		leave
		ret

	end:
		mov			[rdi], byte 0
		leave
		ret
