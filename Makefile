# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egaraz <egaraz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/10 15:38:52 by egaraz            #+#    #+#              #
#    Updated: 2018/02/11 02:24:27 by egaraz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FILES = fdf.c mlx.c

OBJECTS = $(FILES:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAG) -I libft/ -c $(FILES)
	gcc $(CFLAG) -o $(NAME) $(OBJECTS) $(ATTACH)

clean:
	/bin/rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

norme:
	norminette $(FILES)
