CC = cc 
CFLAGS = -Wall -Wextra -Werror -ggdb 
SRC = main.c parsing.c #ray.c sphere.c vector.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
INCLUDES = miniRT.h includes/meta_data.h
NAME = miniRT




# custom command : remove custom command  later
all: $(LIBFT) $(NAME)
	@ valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./miniRT "file.rt"


$(LIBFT):
	@make -s -C libft all

$(NAME): $(OBJ) $(INCLUDES)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
