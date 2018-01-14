#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/15 14:42:38 by tsilva            #+#    #+#              #
#    Updated: 2015/06/15 17:35:19 by tsilva           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			hitech_phonebook

CC =			clang++
FLAGS =			-Wall -Werror -Wextra

INC_FLAGS = -I .

COMPILED =		main.o\
				Contact.class.o\

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