#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 17:52:57 by tfleming          #+#    #+#              #
#    Updated: 2015/02/26 10:40:57 by mbooth           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			fractol

CC =			gcc
FLAGS =			-g
LIBFT =			"libft/"
X11 =			"/usr/X11/lib"

INC_FLAGS =		-I $(LIBFT)
LIB_FLAGS =		-L $(LIBFT) -L $(X11)

COMPILED =		main.o\
				set_data.o\
				custom_atoi.o\
				hooks.o\
				handle_fractol.o\

all: $(NAME)

$(NAME): $(COMPILED)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(LIB_FLAGS) -lft -lmlx -lXext -lX11 $(COMPILED)
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
