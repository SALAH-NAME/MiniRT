# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 08:54:43 by souahidi          #+#    #+#              #
#    Updated: 2025/01/05 22:30:49 by ysemlali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CC			:= cc
CFLAGS	:= -Wall -Wextra -Werror
DFLAGS	:= -MMD -MP

INCLUDES	:= -I./includes -I/usr/local/include
SCENE 		:= scenes/file.rt

SRC_DIR	:= src
# LIBS_DIR	:= libs
MLX_DIR	:= /usr/local/lib/

ALGEBRA_DIR		:= $(SRC_DIR)/algebra
CORE_DIR		:= $(SRC_DIR)/core
LIBFT_DIR		:= $(SRC_DIR)/libft
PARSER_DIR		:= $(SRC_DIR)/parser
UTILS_DIR		:= $(SRC_DIR)/utils
WINDOW_DIR 		:= $(SRC_DIR)/window

SRCS	:= $(wildcard $(SRC_DIR)/*.c)
OBJS	:= $(SRCS:.c=.o)
DEPS	:= $(OBJS:.o=.d)

CORE_SRCS := $(wildcard $(CORE_DIR)/*.c)
CORE_OBJS := $(CORE_SRCS:.c=.o)
CORE_DEPS := $(CORE_OBJS:.o=.d)

ALGEBRA_LIB	:= $(ALGEBRA_DIR)/libalgebra.a
LIBFT_LIB		:= $(LIBFT_DIR)/libft.a
PARSER_LIB	:= $(PARSER_DIR)/libparser.a
UTILS_LIB		:= $(UTILS_DIR)/libutils.a
WINDOW_LIB 		:= $(WINDOW_DIR)/libwindow.a

LIBS	:= $(ALGEBRA_LIB)  $(LIBFT_LIB) $(PARSER_LIB) $(UTILS_LIB) $(WINDOW_LIB)

LIB_PATH	:= -L$(ALGEBRA_DIR) \
						 -L$(PARSER_DIR) \
						 -L$(UTILS_DIR) \
						 -L$(LIBFT_DIR) \
						 -L$(WINDOW_DIR) \
						 -L$(MLX_DIR)

LIB_FLAGS	:= -lalgebra -lparser -lutils -lwindow -lft -lmlx -lXext -lX11 -lm -lz


all: $(NAME)


$(NAME): $(LIBS) $(CORE_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CORE_OBJS) $(LIB_PATH) $(LIB_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CORE_DIR)/%.o: $(CORE_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ALGEBRA_LIB):
	$(MAKE) -C $(ALGEBRA_DIR) CFLAGS="$(CFLAGS)"

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(PARSER_LIB):
	$(MAKE) -C $(PARSER_DIR) CFLAGS="$(CFLAGS)"

$(UTILS_LIB):
	$(MAKE) -C $(UTILS_DIR) CFLAGS="$(CFLAGS)"

$(WINDOW_LIB):
	$(MAKE) -C $(WINDOW_DIR) CFLAGS="$(CFLAGS)"

-include $(DEPS) $(CORE_DEPS)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.d" -type f -delete
	$(MAKE) -C $(ALGEBRA_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PARSER_DIR) clean
	$(MAKE) -C $(UTILS_DIR) clean
	$(MAKE) -C $(WINDOW_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(ALGEBRA_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PARSER_DIR) fclean
	$(MAKE) -C $(UTILS_DIR) fclean
	$(MAKE) -C $(WINDOW_DIR) fclean

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g
sanitize: fclean all

valgrind: CFLAGS += -g
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(SCENE)

yusuf : all
	./$(NAME) scenes/file.rt


.PHONY: all clean fclean re sanitize valgrind
.SECONDARY:
