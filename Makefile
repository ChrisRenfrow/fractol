# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 15:37:31 by crenfrow          #+#    #+#              #
#    Updated: 2017/09/06 13:47:39 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

FILES		= main view hooks mouse_handler \
				key_handler draw image color \
				julia mandel burning_ship utils \
				render_text parse_schemes \
				color_scheme thread

CFILES		= $(addsuffix .c, $(FILES))
OFILES		= $(addsuffix .o, $(FILES))
SRCFILES	= $(addprefix src/, $(CFILES))
LIBFILES	= libft/libft.a libmlx/libmlx.a

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -L lib/libft/ -L lib/libmlx/ -lmlx -lft
INCFLAGS	= -I lib/libft/inc/ -I lib/libmlx/
INCFLAGS	+= -I inc/
MLXFLAGS	= -framework OpenGL -framework AppKit
FLAGS		= $(CFLAGS) $(LIBFLAGS) $(MLXFLAGS)
DEBUG		=  -g #-fsanitize=address

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf $(OFILES)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(SRCFILES)
	make -C lib/libft
	make -C lib/libmlx
	# $(CC) $(INCFLAGS) $(SRCFILES) -o $@ $(FLAGS)
	$(CC) $(DEBUG) $(INCFLAGS) $(SRCFILES) -o $@ $(FLAGS)
