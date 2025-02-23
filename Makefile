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
BONUS_NAME	:= miniRT_bonus

CC			:= cc
CFLAGS	:= -Wall -Wextra -Werror -ggdb
DFLAGS	:= -MMD -MP

INCLUDES	:= -I./includes -I/usr/local/include
SCENE_DIR := scenes


SRC_DIR	:= src
# LIBS_DIR	:= libs
MLX_DIR	:= /usr/local/lib/

EVENT_DIR    := $(SRC_DIR)/events
ALGEBRA_DIR	:= $(SRC_DIR)/algebra
CORE_DIR		:= $(SRC_DIR)/core
LIBFT_DIR		:= $(SRC_DIR)/libft
PARSER_DIR	:= $(SRC_DIR)/parser
LIST_DIR		:= $(SRC_DIR)/list
BONUS_PARSER_DIR := $(SRC_DIR)/bonus_parser

ALGEBRA_SRC	:= $(ALGEBRA_DIR)/matrix3_apply_rotation.c $(ALGEBRA_DIR)/vec3_create.c \
		$(ALGEBRA_DIR)/vec3_dot.c $(ALGEBRA_DIR)/vec3_length_squared.c $(ALGEBRA_DIR)/vec3_reflect.c \
		$(ALGEBRA_DIR)/matrix3_create_rotation.c $(ALGEBRA_DIR)/vec3_cross.c $(ALGEBRA_DIR)/vec3_is_zero.c \
		$(ALGEBRA_DIR)/vec3_mul.c $(ALGEBRA_DIR)/vec3_sub.c $(ALGEBRA_DIR)/vec3_add.c \
		$(ALGEBRA_DIR)/vec3_div.c $(ALGEBRA_DIR)/vec3_length.c $(ALGEBRA_DIR)/vec3_normalize.c

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

PARSER_SRCS	:=  $(PARSER_DIR)/acl_init.c $(PARSER_DIR)/free.c $(PARSER_DIR)/object_init.c \
								$(PARSER_DIR)/parse_inits.c $(PARSER_DIR)/parsing.c $(PARSER_DIR)/print_scene.c \
								$(PARSER_DIR)/config.c $(PARSER_DIR)/parse_errors.c \
								$(PARSER_DIR)/parse_inits_extra.c $(PARSER_DIR)/parsing_utils.c

BONUS_PARSER_SRCS := $(BONUS_PARSER_DIR)/bonus_acl_parse.c $(BONUS_PARSER_DIR)/bonus_free.c \
                     $(BONUS_PARSER_DIR)/bonus_object_parse.c $(BONUS_PARSER_DIR)/bonus_parse_inits.c \
                     $(BONUS_PARSER_DIR)/bonus_parsing.c $(BONUS_PARSER_DIR)/bonus_print_scene.c \
                     $(BONUS_PARSER_DIR)/bonus_config.c $(BONUS_PARSER_DIR)/bonus_parse_errors.c \
                     $(BONUS_PARSER_DIR)/bonus_parse_inits_extra.c $(BONUS_PARSER_DIR)/bonus_parsing_utils.c

LIST_SRCS		:= $(LIST_DIR)/list_free.c $(LIST_DIR)/list_get.c $(LIST_DIR)/list_insert_shift.c \
							 $(LIST_DIR)/list_length.c $(LIST_DIR)/list_map.c $(LIST_DIR)/list_predicate.c \
							 $(LIST_DIR)/list_push_pop.c


SRCS	:= $(SRC_DIR)/main.c
OBJS	:= $(SRCS:.c=.o)
DEPS	:= $(OBJS:.o=.d)

CORE_SRCS := $(CORE_DIR)/calculate_lighting.c $(CORE_DIR)/find_nearest_intersection.c \
						 $(CORE_DIR)/noise.c $(CORE_DIR)/render_scene.c $(CORE_DIR)/color.c \
						 $(CORE_DIR)/ray_cylinder_intersect.c $(CORE_DIR)/ray_cone_intersect.c \
						 $(CORE_DIR)/solve_quadratic.c $(CORE_DIR)/cone_calc.c $(CORE_DIR)/init_scene.c \
						 $(CORE_DIR)/ray_intersection_shading.c $(CORE_DIR)/cone_hit.c \
						 $(CORE_DIR)/is_in_shadow.c $(CORE_DIR)/ray_plane_intersect.c \
						 $(CORE_DIR)/cone_surface_solver.c $(CORE_DIR)/material.c $(CORE_DIR)/ray_sphere_intersect.c

EVENT_SRCS   := $(EVENT_DIR)/key_handler.c $(EVENT_DIR)/object_transform.c $(EVENT_DIR)/camera_transform.c $(EVENT_DIR)/event_utils.c

CORE_OBJS := $(CORE_SRCS:.c=.o)
CORE_DEPS := $(CORE_OBJS:.o=.d)

ALGEBRA_LIB	:= $(ALGEBRA_DIR)/libalgebra.a
LIBFT_LIB		:= $(LIBFT_DIR)/libft.a
PARSER_LIB	:= $(PARSER_DIR)/libparser.a
BONUS_PARSER_LIB := $(BONUS_PARSER_DIR)/libbonusparser.a
LIST_LIB		:= $(LIST_DIR)/liblist.a
EVENT_LIB    := $(EVENT_DIR)/libevent.a

LIBS	:= $(ALGEBRA_LIB)  $(LIBFT_LIB) $(PARSER_LIB) $(LIST_LIB) $(EVENT_LIB)
BONUS_LIBS	:= $(ALGEBRA_LIB)  $(LIBFT_LIB) $(BONUS_PARSER_LIB) $(LIST_LIB) $(EVENT_LIB) 

LIB_PATH	:= -L$(ALGEBRA_DIR) \
						 -L$(PARSER_DIR) \
						 -L$(LIBFT_DIR) \
						 -L$(MLX_DIR) \
						 -L$(LIST_DIR) \
						 -L$(EVENT_DIR) \

BONUS_LIB_PATH	:= -L$(ALGEBRA_DIR) \
						 -L$(LIBFT_DIR) \
						 -L$(MLX_DIR) \
						 -L$(LIST_DIR) \
						 -L$(EVENT_DIR) \
						 -L$(BONUS_PARSER_DIR)



LIB_FLAGS	:=  -lparser -lft -llist -lalgebra -levent  -lmlx -lXext -lX11 -lm -lz
BONUS_LIB_FLAGS	:=  -lbonus_parser -lft -llist -lalgebra -levent  -lmlx -lXext -lX11 -lm -lz


all: $(NAME) 
bonus: CFLAGS += -D BONUS
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_LIBS) $(CORE_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CORE_OBJS) $(BONUS_LIB_PATH) $(BONUS_LIB_FLAGS) -o $(BONUS_NAME)

$(NAME): $(LIBS) $(CORE_OBJS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(CORE_OBJS) $(LIB_PATH) $(LIB_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS): ./includes/minirt.h

$(CORE_OBJS): ./includes/minirt.h

$(CORE_DIR)/%.o: $(CORE_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(ALGEBRA_LIB): $(ALGEBRA_SRC)
	$(MAKE) -C $(ALGEBRA_DIR) CFLAGS="$(CFLAGS)"

$(LIBFT_LIB): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR) CFLAGS="$(CFLAGS)"

$(PARSER_LIB): $(PARSER_SRCS)
	$(MAKE) -C $(PARSER_DIR) CFLAGS="$(CFLAGS)"

$(BONUS_PARSER_LIB): $(BONUS_PARSER_SRCS)
	$(MAKE) -C $(BONUS_PARSER_DIR) CFLAGS="$(CFLAGS)"

$(LIST_LIB): $(LIST_SRCS)
	$(MAKE) -C $(LIST_DIR) CFLAGS="$(CFLAGS)"

$(EVENT_LIB): $(EVENT_SRCS)
	$(MAKE) -C $(EVENT_DIR) CFLAGS="$(CFLAGS)"

-include $(DEPS) $(CORE_DEPS)

clean:
	find . -name "*.o" -type f -delete
	find . -name "*.d" -type f -delete
	$(MAKE) -C $(ALGEBRA_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PARSER_DIR) clean
	$(MAKE) -C $(LIST_DIR) clean
	$(MAKE) -C $(EVENT_DIR) clean
	$(MAKE) -C $(BONUS_PARSER_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	$(MAKE) -C $(ALGEBRA_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PARSER_DIR) fclean
	$(MAKE) -C $(LIST_DIR) fclean
	$(MAKE) -C $(EVENT_DIR) fclean
	$(MAKE) -C $(BONUS_PARSER_DIR) fclean

re: fclean all

sanitize: CFLAGS += -fsanitize=address -g
sanitize: fclean all

valgrind: CFLAGS += -g
valgrind: fclean all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(SCENE)

yusuf: all
	./$(NAME) scenes/file.rt
# ./$(BONUS_NAME) $(SCENE_DIR)/bonus_scene.rt


.PHONY: all clean fclean re sanitize valgrind
.SECONDARY:

