;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 11:10:49 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 11:15:24 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data
	LOWER_A equ 97			;from a to z (97-122) 
	LOWER_Z equ 122
	
section .text
	global _ft_toupper

_ft_toupper:
	mov rax, rdi
	cmp rax, LOWER_A
	jge is_smaller_than_z
	jmp exit

is_smaller_than_z:
	cmp rax, LOWER_Z
	jle true
	jmp exit

true:
	sub rax, 32
	jmp exit

exit:
	ret
	