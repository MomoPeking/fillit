# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 15:56:06 by qdang             #+#    #+#              #
#    Updated: 2019/11/07 21:14:47 by qdang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -g

$(NAME): 
	@gcc $(FLAGS) -c libft/*.c -I libft/*.h
	@gcc $(FLAGS) -c *.c -I *.h 
	@gcc *.o -o $(NAME)

all: $(NAME)

clean:
	@rm -f *.o
	@rm -f libft/*.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all
