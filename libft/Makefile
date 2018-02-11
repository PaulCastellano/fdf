NAME 		= libft.a

CC			= clang

FLAGS		= -Wall -Wextra -Werror

SRC_FILES 	= *.c

OBJ_FILES 	= *.o

all: $(NAME)

$(NAME): $(OBJ_FILES)
		ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_FILES):
		$(CC) -c $(CFLAGS) $(SRC_FILES)

clean:
		-rm -f *.o

fclean: clean
		-rm -f $(NAME)

re: fclean all
