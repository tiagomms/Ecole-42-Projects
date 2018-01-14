section .text
		global _ft_strncpy

_ft_strncpy :
		enter 	0,0
		cmp 	rdi, 0
		je		ko
		cmp		rsi, 0
		je		ko
		push	rdi
		cmp		rdx, 0
		je		end

	cpy :
		cmp		rdx, 0
		je		end
		cmp		byte [rsi], 0
		je		fill
		mov		al, [rsi]
		mov		[rdi], al
		dec		rdx
		inc		rdi
		inc		rsi
		jmp		cpy

	fill :
		cmp		rdx, 0
		je		end
		mov		al, 0
		mov		[rdi], al
		dec		rdx
		inc		rdi
		jmp		fill

	ko :
		mov		rax, 0
		leave
		ret

	end :
		pop		rax
		leave
		ret
