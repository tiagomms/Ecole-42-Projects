;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/02 16:06:29 by tsilva            #+#    #+#              ;
;    Updated: 2015/07/01 18:55:36 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_bzero

_ft_bzero :
	enter	0, 0
	cmp		rsi, 0
	je		end

loop :
	cmp		rsi, byte 0
	je		end
	mov		[rdi], byte 0
	inc		rdi
	dec		rsi
	jmp		loop

end:
	leave
	ret