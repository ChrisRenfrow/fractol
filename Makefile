# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 15:37:31 by crenfrow          #+#    #+#              #
#    Updated: 2017/07/03 15:36:19 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

OSXV		= $(sw_vers -productVersion | grep '10.11.[0-9]+')

FILES		= main view hooks mouse_handler \
				key_handler draw image color \
				julia mandel utils render_text \
				parse_schemes color_scheme thread
CFILES		= $(addsuffix .c, $(FILES))
OFILES		= $(addsuffix .o, $(FILES))
SRCFILES	= $(addprefix src/, $(CFILES))

LIBDIR		= lib/
# Change as per your operating
ifeq ($(OSXV),)
	LIBMLX 		= $(LIBDIR)libmlx_cap
else
	LIBMLX 		= $(LIBDIR)libmlx_sierra
endif

LIBFILES	= libft/libft.a $(LIBMLX)libmlx.a

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
LIBFLAGS	= -L lib/libft -L $(LIBMLX) -lmlx -lft
INCFLAGS	= -I lib/libft/inc/ -I $(LIBMLX)
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
	make -C $(LIBMLX)
	# $(CC) $(INCFLAGS) $(SRCFILES) -o $@ $(FLAGS)
	$(CC) $(DEBUG) $(INCFLAGS) $(SRCFILES) -o $@ $(FLAGS)
