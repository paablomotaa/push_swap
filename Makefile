NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = src/main.c src/utils.c src/operations.c src/parse.c src/normalize.c src/radix_sort.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
