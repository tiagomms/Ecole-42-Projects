;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/05 16:13:19 by tsilva            #+#    #+#              ;
;    Updated: 2015/05/01 16:33:06 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

%define MACHSYSCALL(nb) 0x2000000 | nb

section .data
	READ equ 3
	EXIT equ 1
	WRITE equ 4
	STD_OUT equ 1
	BUFFER times 6 db 0 			;non_initialized variables. buffer[1024]	
	SIZE equ $ - BUFFER

section .text
	global _ft_cat

_ft_cat:
	cmp rdi, 0
	jl invalid_fd
	push rdi					;storing fd	

read:
	pop rdi
	lea rsi, [rel BUFFER]		;set buffer
	mov rdx, SIZE
	mov rax, MACHSYSCALL(READ)
	syscall						;read(fd, buf, bufsize)
	jc error
	cmp rax, 0					
	je exit					;if eof or error

display:
	push rdi
	mov rdi, STD_OUT
	mov rdx, rax				;return size from read
	mov rax, MACHSYSCALL(WRITE)
	syscall						;write(fd, buf[full], ret)
	jmp read

invalid_fd:
	mov rdi, 1
	mov rax, MACHSYSCALL(EXIT)
	
error:
	mov rax, 1
	
exit:
	ret
	
