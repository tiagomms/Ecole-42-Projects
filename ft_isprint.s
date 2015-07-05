;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 11:06:40 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 11:12:08 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data
	FIRST_PRINTABLE equ 32			;from space to del (32-126) 
	LAST_PRINTABLE equ 126
	
section .text
	global _ft_isprint

_ft_isprint:
	mov rax, 0
	cmp rdi, FIRST_PRINTABLE
	jge is_smaller_than_last
	jmp exit

is_smaller_than_last:
	cmp rdi, LAST_PRINTABLE
	jle true
	jmp exit

true:
	mov rax, 1
	jmp exit

exit:
	ret
	