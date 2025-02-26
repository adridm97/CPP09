# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 16:49:01 by adrian            #+#    #+#              #
#    Updated: 2025/02/25 19:11:45 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= PmergeMe
CPP		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -fsanitize=address
HEADER	= PmergeMe.hpp
SRC		= PmergeMe.cpp main.cpp
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
re: all fclean
.PHONY: re fclean clean all