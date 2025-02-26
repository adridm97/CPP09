# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 17:07:14 by adrian            #+#    #+#              #
#    Updated: 2025/02/24 19:33:46 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc
CPP		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
HEADER	= BitcoinExchange.hpp
SRC		= BitcoinExchange.cpp main.cpp
OBJ		= $(SRC:.cpp=.o)

%.o: %.cpp Makefile $(HEADER)
	$(CPP) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: re fclean clean all