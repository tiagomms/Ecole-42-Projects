;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 11:10:49 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 11:51:17 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data
	UPPER_A equ 65			;from a to z (97-122) 
	UPPER_Z equ 90
	
section .text
	global _ft_tolower

_ft_tolower:
	mov rax, rdi
	cmp rax, UPPER_A
	jge is_smaller_than_z
	jmp exit

is_smaller_than_z:
	cmp rax, UPPER_Z
	jle true
	jmp exit

true:
	add rax, 32
	jmp exit

exit:
	ret
	