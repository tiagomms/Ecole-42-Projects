;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/03 17:24:01 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/05 12:55:57 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strcat
	extern _ft_memcpy
	extern _ft_strlen

_ft_strcat:
	push rdi
	mov rcx, -1
	mov rax, 0x0
	repne scasb
	dec rdi
	push rdi					;end of s1

strlen_s2:
	mov  rdi, rsi
	call _ft_strlen
	mov rdx, rax
	
copy_second_string:
	pop rdi
	call _ft_memcpy
	pop rax

exit:
	ret