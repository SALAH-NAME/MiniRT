# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:07:33 by souahidi          #+#    #+#              #
#    Updated: 2025/01/06 10:33:30 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= libparser.a

CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR		:= ../libft/
LIBFT				:= $(LIBFT_DIR)/libft.a
LIBFT_SRCS	:= $(LIBFT_DIR)/ft_arrlen.c $(LIBFT_DIR)/ft_isascii.c $(LIBFT_DIR)/ft_memset.c \
							 $(LIBFT_DIR)/ft_strcmp.c $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_substr.c \
							 $(LIBFT_DIR)/ft_arrmapi.c $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_numvalid.c \
							 $(LIBFT_DIR)/ft_strcpy.c $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_tolower.c \
							 $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_putchar_fd.c \
							 $(LIBFT_DIR)/ft_strcspn.c $(LIBFT_DIR)/ft_strndup.c $(LIBFT_DIR)/ft_toupper.c \
							 $(LIBFT_DIR)/ft_atoi_safe.c $(LIBFT_DIR)/ft_isspace.c $(LIBFT_DIR)/ft_putendl_fd.c \
							 $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/get_next_line.c \
							 $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_putnbr_fd.c \
							 $(LIBFT_DIR)/ft_striteri.c $(LIBFT_DIR)/ft_strpbrk.c $(LIBFT_DIR)/get_next_line_utils.c \
							 $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_memchr.c $(LIBFT_DIR)/ft_putstr_fd.c \
							 $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_strrchr.c $(LIBFT_DIR)/ft_del.c \
							 $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strlcat.c \
							 $(LIBFT_DIR)/ft_strreplace.c $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_memcpy.c \
							 $(LIBFT_DIR)/ft_split_stack.c $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strtod_safe.c \
							 $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_strchr.c \
							 $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_strtrim.c

INCLUDES	:= -I../../includes/

SRCS	:= acl_init.c free.c parse_errors.c parse_inits_extra.c parsing_utils.c \
				 config.c object_init.c parse_inits.c parsing.c print_scene.c
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
