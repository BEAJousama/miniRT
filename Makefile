# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:39:16 by eabdelha          #+#    #+#              #
#    Updated: 2022/05/22 14:24:55 by obeaj            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
NAME_LIBFT = libft.a
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

MLX_INCLUDE = /usr/local/include
INCLUDE_1 = ./includes/minirt.h
INCLUDE_2 = ./includes/elements.h
INCLUDE_3 = ./includes/defines.h

FOBJ_SRC = object_files
OBJECT_PATH = ./object_files/

LIBFT_PATH = ./libft
SRC_PATH = ./src/
PARSE_PATH = ./parsing/
DISPLAY_PATH = ./display/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# BSRC =  minirt_bonus.c     		\

SRC =  	minirt.c         		\
		read_map.c				\
		read_map_utils.c 		\
		check_A_C_L_elements.c		\
		check_pl_sp_cy_elements.c	\
		check_elements_utils.c	\
		print_error_msg.c		\
		parse_elements_utils.c	\
		display.c				\
		vectors_opp.c			\
		fill_matrix.c			\
		matrix_opp.c			\
		cogo_manipulations.c	\
		sphere_intersection.c	\
		plane_intersection.c    \
		cylinder_intersection.c \
		rgb_calculations.c		\
		objects_shading.c		\
		objects_intersections.c \

		


.PHONY : all bonus clean fclean re

M_OBJECTS =  $(addprefix $(OBJECT_PATH), $(SRC:.c=.o))
# B_OBJECTS =  $(addprefix $(OBJECT_PATH), $(BSRC:.c=.o))

all: $(NAME)


$(NAME): $(FOBJ_SRC) $(M_OBJECTS) $(MLX_INCLUDE)
	@make -C $(LIBFT_PATH)
	@printf "linking object files...\n"
	@$(CC) $(CFLAGS) $(M_OBJECTS) $(LIBFT_PATH)/$(NAME_LIBFT) $(MLX) -o $(NAME)

$(OBJECT_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJECT_PATH)%.o: $(SRC_PATH)$(PARSE_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJECT_PATH)%.o: $(SRC_PATH)$(DISPLAY_PATH)%.c $(INCLUDE_1) $(INCLUDE_2) $(INCLUDE_3)
	$(CC) $(CFLAGS) -o $@ -c $<

$(FOBJ_SRC) : 
	@mkdir $@

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJECTS)
	@rm -rf $(FOBJ_SRC)

fclean: clean
	@make fclean -C $(LIBFT_PATH) 
	@rm -rf $(NAME)

re: fclean all


