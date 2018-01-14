# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 17:06:05 by tsilva            #+#    #+#              #
#    Updated: 2015/02/24 17:06:06 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

CC =			gcc
FLAGS =			-Wall -Wextra -Werror	
LIBFT =			"libft/"

INC_FLAGS =		-I $(LIBFT)
LIB_FLAGS =		-L $(LIBFT)

COMPILED =		alternative.o\
				correct_order.o\
				custom_atoi.o\
				handlerotations.o\
				main.o\
				operations_loop.o\
				print_tracker.o\
				sort_numbers.o\
				swappush.o\

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) -lft $(COMPILED)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.c
	@$(CC) -c $(FLAGS) $(INC_FLAGS) $< -o $@

clean:
	@make -C $(LIBFT) clean
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@make -C $(LIBFT) fclean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
	@echo "Done."

fonly: all clean
