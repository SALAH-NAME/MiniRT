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

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)


TEST_DIR = tests/
TEST_SRCS	= $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS	= $(TEST_SRCS:.c=.o)
TEST_DEPS	= $(TEST_OBJS:.o=.d)

TEST_FLAGS = -g

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

test: $(NAME) $(TEST_NAME)
	@./$(TEST_NAME)

$(TEST_NAME): $(TEST_OBJS) $(NAME)
	$(CC) $(CFLAGS) $(TEST_OBJS) -o $(TEST_NAME) -L. -lalgebra -lm

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(TEST_FLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TEST_OBJS) $(TEST_DEPS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

.PHONY: all clean fclean re test
.SECONDARY: $(OBJS) $(DEPS) $(TEST_OBJS) $(TEST_DEPS)

