# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/18 03:16:59 by tsilva            #+#    #+#              #
#    Updated: 2015/02/15 17:34:40 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libftprintf.a

CC =				gcc
FLAGS =				-Wall -Werror -Wextra -g

FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./printf

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	$(PRINTF_SRC_DIR)ft_printf.h

FT_COMPILED=ft_list_size.o\
	ft_list_reverse.o\
	ft_list_remove_if.o\
	ft_list_push_params.o\
	ft_list_push_front.o\
	ft_list_last.o\
	ft_list_find_end.o\
	ft_list_find.o\
	ft_list_clear.o\
	ft_list_at.o\
	ft_list_create_elem.o\
	ft_list_push_back.o\
	get_next_line.o\
	ft_memset.o\
	ft_bzero.o\
	ft_memcpy.o\
	ft_memccpy.o\
	ft_memmove.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_strlen.o\
	ft_strdup.o\
	ft_strcpy.o\
	ft_strncpy.o\
	ft_strcat.o\
	ft_strncat.o\
	ft_strlcat.o\
	ft_strchr.o\
	ft_strrchr.o\
	ft_strstr.o\
	ft_strnstr.o\
	ft_strcmp.o\
	ft_strncmp.o\
	ft_atoi.o\
	ft_isalpha.o\
	ft_isdigit.o\
	ft_isalnum.o\
	ft_isascii.o\
	ft_isprint.o\
	ft_toupper.o\
	ft_tolower.o\
	ft_memalloc.o\
	ft_memdel.o\
	ft_strnew.o\
	ft_strdel.o\
	ft_strclr.o\
	ft_striter.o\
	ft_striteri.o\
	ft_strmap.o\
	ft_strmapi.o\
	ft_strequ.o\
	ft_strnequ.o\
	ft_strsub.o\
	ft_strjoin.o\
	ft_strtrim.o\
	ft_strsplit.o\
	ft_itoa.o\
	ft_putchar.o\
	ft_putstr.o\
	ft_putendl.o\
	ft_putnbr.o\
	ft_putchar_fd.o\
	ft_putstr_fd.o\
	ft_putendl_fd.o\
	ft_putnbr_fd.o\
	ft_list_remove_node.o\
	ft_putchar_if.o\
	ft_ptrswp.o\
	ft_list_sort.o\
	ft_ptrequ.o\
	ft_strrev.o\


PRINTF_COMPILED =	ft_printf.o \
					dealing_with_flags.o \
					dealing_with_width.o \
					customatoi.o \
					dealing_with_precision.o \
					dealing_with_length.o\
					dealing_with_specifier.o\
					ft_putnbr_intmax.o\
					printstring.o\
					printint.o\
					print_char.o\
					print_hexnbr.o\
					justify_functions.o\
					print_octal.o\
					typestring.o\
					print_wide_string.o\
					typeint.o\
					ft_itoa_uintmax.o\
					count_wint_bytes.o\
					print_wint.o\
					add_widths.o\
					null_hex_case.o\

COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
