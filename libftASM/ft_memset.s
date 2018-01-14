;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 19:06:54 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 19:33:57 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_memset

_ft_memset:
	push rdi					; void pointer
	mov rcx, rdx				; size_t len
	mov rax, rsi  				; int c
	rep stosb					; copy from register to memory (rdi)
	pop rax	
	ret
	