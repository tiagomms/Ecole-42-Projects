# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 17:06:05 by mbooth            #+#    #+#              #
#    Updated: 2015/03/26 18:15:07 by mbooth           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			ft_minishell1

CC =			gcc
FLAGS =			-Wall -Werror -Wextra
LIBFT =			"libft/"

INC_FLAGS =		-I $(LIBFT)
LIB_FLAGS =		-L $(LIBFT)

COMPILED =		main.o\
				custom_split.o\
				built_ins.o\
				env_modifiers.o\
				array_functions.o\
				handle_paths.o\
				create_environment.o\
				ft_cd.o\
				change_shlvl.o\
				ft_disp_bonus.o\
				handle_shell.o\
				custom_putstr.o\
				signals.o\

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
