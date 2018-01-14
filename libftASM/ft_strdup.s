;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/04/05 10:53:36 by tsilva            #+#    #+#              ;
;    Updated: 2015/04/05 11:47:04 by tsilva           ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

section .text
	global _ft_strdup	
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	mov r12, rdi				;address of initial string
	mov rax, 0					
	call _ft_strlen
	inc rax						;increment for /0

prepare_malloc:
	mov rdi, rax
	push rdi					;result from strlen
	call _malloc
	pop rdx						;result from strlen
	
prepare_memcpy:
	mov rsi, r12				;address of initial string
	mov rdi, rax				;malloced string to 1st arg
	call _ft_memcpy			

	;; \0???
	
exit:
	ret
	
	
