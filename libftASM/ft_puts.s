;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/04 12:00:25 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/05 18:56:38 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACHSYSCALL(nb)  0x2000000 | nb  
	
section .data
	WRITE equ 4
	STD_OUT equ 1
	string db "(null)", 10

section .text
	global _ft_puts
	
_ft_puts:
	push rdi
	mov rsi, rdi
	mov rdi, STD_OUT
	mov rdx, 0
	cmp rsi, 0
	je print_null

find_end_s1:
	cmp [rsi], byte 0
	je  write 			
	inc rsi
	inc rdx
	jmp find_end_s1

write:
	pop rsi
	mov rax, MACHSYSCALL(WRITE)
	syscall

printNewLine:
    lea rsi, [rel string + 6]
	mov rdx, 1
	mov rdi, STD_OUT
	mov rax, MACHSYSCALL(WRITE)	
	syscall
	mov rax, 1
	jmp exit

print_null:
	lea rsi, [rel string]
	mov rdx, 7
	mov rax, MACHSYSCALL(WRITE)
	syscall
	mov rax, 10
	pop rsi
	
exit:	
	ret