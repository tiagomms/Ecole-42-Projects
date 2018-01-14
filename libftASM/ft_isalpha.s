;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalpha.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/03 16:51:12 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/03 17:12:48 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isalpha

_ft_isalpha:
	enter 0, 0
	mov	rax, 0
	mov rbx, rdi
	cmp rbx, 90
	jle is_capital
	cmp rbx, 97
	jge is_lower
	jmp exit

is_capital:	
	cmp rbx, 65
	jge true
	jmp exit

is_lower:	
	cmp rbx, 122
	jle true
	jmp exit
	
true:
	mov rax, 1
	jmp exit
	
exit:
	leave
	ret