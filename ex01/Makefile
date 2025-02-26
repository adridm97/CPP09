# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 19:03:59 by adrian            #+#    #+#              #
#    Updated: 2025/02/25 16:46:15 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN
CPP		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address
HEADER	= RPN.hpp
SRC		= main.cpp RPN.cpp
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