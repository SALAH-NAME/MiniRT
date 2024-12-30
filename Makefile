CC = cc 
CFLAGS = -Wall -Wextra -Werror -ggdb 
SRC = main.c parsing.c #ray.c sphere.c vector.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
NAME = miniRT




# custom command : remove (./miniRT file.rt) later
all: $(LIBFT) $(NAME)
	./miniRT file.rt


$(LIBFT):
	@make -s -C libft all

$(NAME): $(OBJ) miniRT.h
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
