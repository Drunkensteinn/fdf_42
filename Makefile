# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/11 22:46:39 by ablizniu          #+#    #+#              #
#    Updated: 2018/06/11 22:46:40 by ablizniu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME = fdf
SRCFILL = fdf_draw.o \
		fdf_keycode.o\
		fdf_move_centralize.o\
		fdf_rotation_move.o\
		fdf_start.o \
		mlx_read_and_parse.o\
		mlx_read_and_parse_1.o\
		main.o
BINS = $(SRCFILL:.c=.o)
LIBFT = libft/

all: $(NAME)

$(NAME): $(BINS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCFILL) libft/libft.a

.c.o:
	$(CC) -c $(GFLAGS) $<

clean:
	make clean -C $(LIBFT)
	rm -f $(BINS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
