# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:07:33 by souahidi          #+#    #+#              #
#    Updated: 2025/01/02 09:21:52 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libalgebra.a
TEST_NAME	= run_test

CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I../../includes/

SRCS = matrix3_apply_rotation.c vec3_create.c vec3_dot.c vec3_length_squared.c \
			 vec3_reflect.c matrix3_create_rotation.c vec3_cross.c vec3_is_zero.c \
			 vec3_mul.c vec3_sub.c vec3_add.c vec3_div.c vec3_length.c vec3_normalize.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)



all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

test: $(NAME) $(TEST_NAME)
	@./$(TEST_NAME)



-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test
.SECONDARY: $(OBJS) $(DEPS)

