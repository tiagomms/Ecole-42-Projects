;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/03 16:51:12 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 11:10:03 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_isalnum

_ft_isalnum:
	mov	rax, 0
	mov rbx, rdi
	cmp rbx, 57
	jle is_digit
	cmp rbx, 90
	jle is_upper
	cmp rbx, 122
	jle is_lower
	jmp exit

is_digit:	
	cmp rbx, 48
	jge true
	jmp exit

is_lower:	
	cmp rbx, 97
	jge true
	jmp exit

is_upper:
	cmp rbx, 65
	jge true
	jmp exit

true:
	mov rax, 1
	jmp exit
	
exit:
	ret