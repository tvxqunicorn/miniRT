# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 09:46:39 by xli               #+#    #+#              #
#    Updated: 2021/05/12 12:51:12 by xli              ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

HEAD = includes

LIB = lib/

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I $(HEAD)

INCLUDE = includes/bmp.h includes/math_0.h includes/minirt.h includes/parse.h\
		includes/put.h

FILES = main.c error.c

OBJECT_FILES = camera.c light.c objects.c sphere.c plane.c square.c\
		cylinder.c cylinder1.c triangle.c

PARSE_FILES = parse_scene.c parse_r.c parse_a.c parse_c.c parse_l.c\
		parse_sp.c parse_pl.c parse_sq.c parse_cy.c parse_tr.c

PUT_FILES = open_window.c deal_key.c load_image.c put_screen.c\
		put_screen_norm_0.c put_screen_norm_1.c put_screen_norm_2.c\
		put_screen_norm_3.c put_screen_norm_4.c

MATH_FILES = math0.c math1.c math2.c

BMP_FILES = do_bmp.c

OBJECT_DIR = object/

PARSE_DIR = parse/

PUT_DIR = put/

MATH_DIR = math/

BMP_DIR = bmp/

SRCS_DIR = srcs/

FILES += $(addprefix $(OBJECT_DIR), $(OBJECT_FILES))

FILES += $(addprefix $(PARSE_DIR), $(PARSE_FILES))

FILES += $(addprefix $(PUT_DIR), $(PUT_FILES))

FILES += $(addprefix $(MATH_DIR), $(MATH_FILES))

FILES += $(addprefix $(BMP_DIR), $(BMP_FILES))

SRCS = $(addprefix $(SRCS_DIR), $(FILES))

OBJS = $(SRCS:.c=.o)

%.o : %.c $(INCLUDE) $(LIB)
	$(CC) $(CFLAGS) -c $< -o $@

LIBFLAGS = -L $(LIB)libft -lft

MACOS_MACRO = -D MACOS

MACOS_MINILIBX = $(addprefix $(LIB), mlx)

MLX_FLAGS = libmlx.dylib -framework OpenGL -framework AppKit

LIBFLAGS += $(MACOS_FLAGS)

CFLAGS += $(MACOS_MACRO)

MINILIBX = $(MACOS_MINILIBX)

IMAGES = images

$(NAME): $(OBJS) $(IMAGES)
		make -C $(MINILIBX)
		mv $(MINILIBX)/libmlx.dylib .
		make -C $(LIB)libft
		$(CC) $(OBJS) $(CFLAGS) $(MLX_FLAGS) $(LIBFLAGS) -o $(NAME)

$(IMAGES):
		mkdir images

all : $(NAME)

clean :
	make clean -C $(MINILIBX)
	make clean -C $(LIB)libft
	rm -rf $(OBJS)

fclean :
	make clean -C $(MINILIBX)
	make fclean -C $(LIB)libft
	rm -rf $(OBJS)
	rm -rf $(NAME)

re :	fclean all

.PHONY : all clean fclean re bonus
