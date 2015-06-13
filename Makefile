#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/13 15:03:16 by tsilva            #+#    #+#              #
#    Updated: 2015/06/13 15:47:32 by tsilva           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			computor

CC =			g++
FLAGS =			-Wall -Werror -Wextra

INC_DIR = ./includes/
INC_FLAGS =	-I $(INC_DIR)
OBJ_DIR = ./objs/

COMPILED =		main.o\
				coefficients.o\
				getcoefs_from_equation.o\
				linkedlists.o\
				printIrreducibleFractions.o\
				solutions.o\
				usages.o\

OBJ_FILES = $(COMPILED:%=$(OBJ_DIR)%)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(COMPILED)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_FILES) 
	@echo "made" $(NAME)

$(COMPILED): %.o: %.cpp
	@$(CC) -c $(FLAGS) $(INC_FLAGS) -o $(OBJ_DIR)$@ $<

clean:
	@-/bin/rm -f $(OBJ_FILES)
	@-/bin/rm -rf $(OBJ_DIR)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
	@echo "Done."

fonly: all clean
