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

INCLUDES	:= -I../../includes/

SRCS	:= camera_transform.c event_utils2.c event_utils.c key_handler.c object_transform.c
OBJS	:= $(SRCS:.c=.o)
DEPS	:= $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
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
