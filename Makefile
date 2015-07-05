# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 17:06:05 by tsilva            #+#    #+#              #
#    Updated: 2015/07/03 11:09:12 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libfts.a

OBJ_LIB		=	$(SRC_LIB:.s=.o)

all:		$(NAME)

SRC_LIB =		ft_bzero.s	 \
				ft_isalnum.s \
				ft_isalpha.s \
				ft_isascii.s \
				ft_isdigit.s \
				ft_isprint.s \
				ft_toupper.s \
				ft_tolower.s \
				ft_puts.s	 \
				ft_strcat.s	 \
				ft_strlen.s \
				ft_memcpy.s \
				ft_memset.s \
				ft_strdup.s \
				ft_cat.s \
				ft_strbcmp.s \
				ft_isspace.s \
				ft_strnew.s \
				ft_memalloc.s \
				ft_strcpy.s \
				ft_strncpy.s \


NFLAGS += -i $(realpath inc)/

ifeq ($(shell uname), Linux)
		NFLAGS += -felf64 -DLINUX
	else
		NFLAGS += -fmacho64 
	endif

$(NAME):	$(OBJ_LIB)
	ar -rcs $(NAME) $(OBJ_LIB)
	ranlib $(NAME)


%.o:		%.s
	~/.brew/bin/nasm $(NFLAGS) -o $@ -s $< 

clean:
	@/bin/rm -f $(OBJ_LIB)

fclean:		clean
	@/bin/rm -f $(NAME)

re:			fclean all

test:		re
	@gcc -Wl,-no_pie $(NAME) main.c
	@./a.out


.PHONY:		all re fclean clean test
