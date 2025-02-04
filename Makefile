# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 08:54:43 by souahidi          #+#    #+#              #
#    Updated: 2025/02/03 19:57:52 by ysemlali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CC			:= cc
CFLAGS	:= -Wall -Wextra -Werror -ggdb
DFLAGS	:= -MMD -MP

INCLUDES	:= -I./includes -I/usr/local/include
SCENE 		:= scenes/file.rt

SRC_DIR	:= src
# LIBS_DIR	:= libs
MLX_DIR	:= /usr/local/lib/

ALGEBRA_DIR	:= $(SRC_DIR)/algebra
CORE_DIR		:= $(SRC_DIR)/core
LIBFT_DIR		:= $(SRC_DIR)/libft
PARSER_DIR	:= $(SRC_DIR)/parser
UTILS_DIR		:= $(SRC_DIR)/utils
LIST_DIR		:= $(SRC_DIR)/list

ALGEBRA_SRC	:= $(wildcard $(ALGEBRA_DIR)/*.c)
LIBFT_SRCS	:= $(wildcard $(LIBFT_DIR)/*.c)
PARSER_SRCS	:= $(wildcard $(PARSER_DIR)/*.c)
UTILS_SRCS	:= $(wildcard $(UTILS_DIR)/*.c)
LIST_SRCS		:= $(wildcard $(LIST_DIR)/*.c)

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
LIST_LIB		:= $(LIST_DIR)/liblist.a

LIBS	:= $(ALGEBRA_LIB)  $(LIBFT_LIB) $(PARSER_LIB) $(UTILS_LIB) $(LIST_LIB)

LIB_PATH	:= -L$(ALGEBRA_DIR) \
						 -L$(PARSER_DIR) \
						 -L$(UTILS_DIR) \
						 -L$(LIBFT_DIR) \
						 -L$(MLX_DIR) \
						 -L$(LIST_DIR)

LIB_FLAGS	:= -lalgebra -lparser -lutils -lft -llist -lmlx -lXext -lX11 -lm -lz


all: $(NAME) 

$(NAME): $(LIBS)  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) $(LIB_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(CORE_OBJS): ./includes/minirt.h

$(CORE_DIR)/%.o: $(CORE_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ALGEBRA_LIB): $(ALGEBRA_SRC)
	$(MAKE) -C $(ALGEBRA_DIR) CFLAGS="$(CFLAGS)"

$(LIBFT_LIB): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(PARSER_LIB): $(PARSER_SRCS)
	$(MAKE) -C $(PARSER_DIR) CFLAGS="$(CFLAGS)"

$(UTILS_LIB): $(UTILS_SRCS)
	$(MAKE) -C $(UTILS_DIR) CFLAGS="$(CFLAGS)"

$(LIST_LIB): $(LIST_SRCS)
	$(MAKE) -C $(LIST_DIR) CFLAGS="$(CFLAGS)"

-include $(DEPS) $(CORE_DEPS)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.d" -type f -delete
	$(MAKE) -C $(ALGEBRA_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PARSER_DIR) clean
	$(MAKE) -C $(UTILS_DIR) clean
	$(MAKE) -C $(LIST_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(ALGEBRA_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PARSER_DIR) fclean
	$(MAKE) -C $(UTILS_DIR) fclean
	$(MAKE) -C $(LIST_DIR) fclean

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g
sanitize: fclean all

valgrind: CFLAGS += -g
valgrind: fclean all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(SCENE)
yusuf: all
	./$(NAME) scenes/file.rt


.PHONY: all clean fclean re sanitize valgrind
.SECONDARY:

