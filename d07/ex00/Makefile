#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/23 15:00:23 by tsilva            #+#    #+#              #
#    Updated: 2015/06/23 15:00:24 by tsilva           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =			whatever

CC =			clang++
FLAGS =			-Wall -Werror -Wextra

COMPILED =		whatever.o


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