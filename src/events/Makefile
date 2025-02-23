# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:07:33 by souahidi          #+#    #+#              #
#    Updated: 2025/02/15 01:32:22 by ysemlali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libevent.a

LIBFT_DIR		:= ../libft/
LIBFT				:= $(LIBFT_DIR)/libft.a
LIBFT_SRCS	:= $(wildcard $(LIBFT_DIR)/*.c)

INCLUDES	:= -I../../includes/

SRCS	:= $(wildcard *.c)
OBJS	:= $(SRCS:.c=.o)
DEPS	:= $(SRCS:.c=.d)

all: $(NAME)

$(LIBFT): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(DEPS)
