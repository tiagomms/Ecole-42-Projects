# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/24 17:06:05 by mbooth            #+#    #+#              #
#    Updated: 2015/06/13 14:29:06 by tsilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			computor

CC =			g++
FLAGS =			-Wall -Werror -Wextra

INC_DIR = ./includes/
INC_FLAGS =	-I $(INC_DIR)

COMPILED =		main.o\
				coefficients.o\
				getcoefs_from_equation.o\
				linkedlists.o\
				printIrreducibleFractions.o\
				solutions.o\
				usages.o\

all: $(NAME)

$(NAME): $(COMPILED)
	@$(CC) $(FLAGS) -o $(NAME) $(COMPILED) 
	@echo "made" $(NAME)

$(COMPILED): %.o: %.cpp
	@$(CC) -c $(FLAGS) $(INC_FLAGS) -o $@ $<

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
	@echo "Done."

fonly: all clean
