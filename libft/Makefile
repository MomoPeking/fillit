# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 17:38:51 by qdang             #+#    #+#              #
#    Updated: 2019/10/29 20:59:42 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJECTS = *.o

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@gcc $(FLAGS) -c *.c -I *.h
	@ar rc $(NAME) *.o

all: $(NAME)

clean:
	@rm -f *.o
	@rm -f *.gch

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
