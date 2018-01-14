#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/28 13:20:18 by tsilva            #+#    #+#              #
#    Updated: 2015/06/28 13:20:19 by tsilva           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			ft_gkrellm

# Compilation settings
CC = clang++
CFLAGS = -O3 -Werror -Wextra -Wall

# Custom paths
OBJ_DIR = ./objs/
INC_DIR_FUNC = ./includes/

#SFML graphics folder
SFML = ./SFML-2.3-osx-clang-universal

#SFML external libraries
SFML_EXTLIBS = $(SFML)/extlibs
SFML_FRAMEWORKS = $(SFML)/Frameworks


#Library directory:
LIB_DIR = ~/Library/Frameworks

#PWD of our git repository
PWD := $(shell pwd)

#Includes
INC_FLAGS =	-I$(INC_DIR_FUNC) -I$(SFML)/include

#Library
LIB_FLAGS = -L$(SFML)/lib -lsfml-graphics -lsfml-window -lsfml-system

#framework
FRAMEWORK = -lcurses -framework OpenGL -framework AppKit

#FILES compiled
COMPILED =	CPU.o \
			DateTime.o \
			HostUserName.o \
			Network.o \
			OSInfo.o \
			RAM.o \
			main_test.o \
			NcursesModule.o \
			SFMLDisplay.o

OBJ_FILES = $(COMPILED:%=$(OBJ_DIR)%)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(COMPILED)
	$(CC) $(FLAGS) $(FRAMEWORK) $(LIB_FLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "made" $(NAME)

$(COMPILED): %.o: %.cpp
	$(CC) -c $(FLAGS) $(INC_FLAGS) -o $(OBJ_DIR)$@ $<

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