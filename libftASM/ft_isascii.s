;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 10:54:27 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/04 11:51:05 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .data
	ASCII_NUL equ 0 			;decimal ascii code set from 0-127 
	ASCII_DEL equ 127
	
section .text
	global _ft_isascii

_ft_isascii:
	mov rax, 0
	cmp rdi, ASCII_NUL
	jge is_smaller_than_del
	jmp exit

is_smaller_than_del:
	cmp rdi, ASCII_DEL
	jle true
	jmp exit

true:
	mov rax, 1
	jmp exit

exit:
	ret
	