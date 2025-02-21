# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:19:05 by souahidi          #+#    #+#              #
#    Updated: 2025/01/22 16:05:02 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblist.a

CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I../../includes/

SRCS = list_free.c list_get.c list_insert_shift.c list_length.c list_map.c \
			 list_predicate.c  list_push_pop.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

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
