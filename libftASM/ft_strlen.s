;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 16:46:03 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 18:51:40 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strlen

_ft_strlen:
	mov rcx, -1
	mov rax, 0x0
	cmp rdi, rax
	je ifnull
	repne scasb
	mov rax, -2
	sub rax, rcx
	jmp exit

ifnull:
	mov rax, 0
	jmp exit
	
exit:	
	ret