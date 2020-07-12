# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:35:44 by aortega-          #+#    #+#              #
#    Updated: 2020/06/29 11:00:54 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = miniRT

FLAGS =  -lm -lmlx -lXext -lX11 -L ./minilibx -pthread -Wall -Wextra -Werror

SRCS = getnextline/get_next_line_utils.c getnextline/get_next_line.c srcs/apply_root.c srcs/change_camera.c srcs/color.c srcs/color2.c srcs/compute_ray.c srcs/constant_values.c srcs/cylinder_read.c srcs/cylinder.c srcs/ft_atof.c srcs/get_color_ultimate.c srcs/get_color_ultimate2.c srcs/hit.c srcs/manage_keys.c srcs/plane_read.c srcs/plane.c srcs/read_functions.c srcs/read_params1.c srcs/read_params2.c srcs/scene_creator.c srcs/sphere_read.c srcs/sphere.c srcs/square_read.c srcs/square.c srcs/triangle_read.c srcs/triangle.c srcs/vector.c srcs/vector2.c srcs/vector3.c raytracing.c main.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@cd libft && $(MAKE)
		@cp libft/libft.a libft.a
		@cd minilibx && $(MAKE)
		@cd ../
		@cd printf && $(MAKE)
		@cp printf/libftprintf.a libftprintf.a
		@#ar -rcs $(NAME) $(OBJS)
		
		gcc -I /usr/local/include $(OBJS) libft.a libftprintf.a $(FLAGS) -o $(NAME)
		@#gcc -I /usr/local/include $(OBJS) -lm -lmlx -lXext -lX11 -L ./libft -pthread
		@#g++ -I /usr/local/include raytracing.c++ ./libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
f:	
	gcc *.c libft/*.c

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./printf
		$(MAKE) clean -C ./minilibx
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		rm -f libftprintf.a
		$(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./printf
		$(MAKE) clean  -C ./minilibx
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
	