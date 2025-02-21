# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souahidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 09:18:45 by souahidi          #+#    #+#              #
#    Updated: 2025/01/01 09:21:17 by souahidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I../../includes/

CFLAGS	= -Wall -Wextra -Werror

SRCS = calculate_lighting.c find_nearest_intersection.c noise.c render_scene.c \
			 color.c handle_events.c ray_cone_intersect.c solve_quadratic.c \
			 cone_calc.c init_scene.c ray_intersection_shading.c cone_hit.c \
			 is_in_shadow.c ray_plane_intersect.c cone_surface_solver.c material.c \
			 ray_sphere_intersect.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS) $(DEPS)
