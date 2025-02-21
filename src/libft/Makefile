# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:07:33 by souahidi          #+#    #+#              #
#    Updated: 2025/01/01 09:17:57 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS	= -Wall -Wextra -Werror

INCLUDES = -I../../includes/

SRCS = ft_arrlen.c ft_isascii.c ft_memset.c ft_strcmp.c ft_strmapi.c ft_substr.c \
			 ft_arrmapi.c ft_isdigit.c ft_numvalid.c ft_strcpy.c ft_strncmp.c ft_tolower.c \
			 ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_strcspn.c ft_strndup.c ft_toupper.c \
			 ft_atoi_safe.c ft_isspace.c ft_putendl_fd.c ft_strdup.c ft_strnstr.c get_next_line.c \
			 ft_bzero.c ft_itoa.c ft_putnbr_fd.c ft_striteri.c ft_strpbrk.c get_next_line_utils.c \
			 ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c \
			 ft_del.c ft_memcmp.c ft_split.c ft_strlcat.c ft_strreplace.c \
			 ft_isalnum.c ft_memcpy.c ft_split_stack.c ft_strlcpy.c ft_strtod_safe.c \
			 ft_isalpha.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strtrim.c

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
