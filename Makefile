# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/11 19:59:34 by tsilva            #+#    #+#              #
#    Updated: 2015/01/11 20:00:18 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBFT = "libft/"
X11 = "/usr/X11/lib"

INC_FLAGS = -I $(LIBFT)
LIB_FLAGS = -L $(LIBFT) -L $(X11)

COMPILED = main.o \
		ft_auxiliar_functions.o ft_color_42.o ft_create_image.o\
		ft_mlx.o ft_define_proj_type.o ft_isometric.o ft_parallel.o\
		ft_make_initial_list.o ft_mlx_put_pixel_image.o ft_return_errs.o\
		ft_set_colors.o

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

.PHONY: all clean fclean re
