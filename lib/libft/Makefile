# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenfrow <crenfrow@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:49:42 by crenfrow          #+#    #+#              #
#    Updated: 2017/06/17 16:26:00 by crenfrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libft.a
# My bonus functions
FILENAMES	=	ft_abs			\
				ft_lstct		\
				ft_ctwrd		\
				ft_memrcpy		\
				ft_digilen		\
				ft_strrev		\
				ft_lstget		\
				ft_lstaddend	\
				ft_memrealloc	\
				ft_memreallocf	\
				ft_strlchr		\
				ft_realloc		\
				ft_strlchr		\
				get_next_line	\
# Assignment Part 1
FILENAMES 	+= 	ft_memset		\
				ft_bzero 		\
				ft_memcpy 		\
				ft_memccpy 		\
				ft_memmove 		\
				ft_memchr 		\
				ft_memcmp 		\
				ft_strlen 		\
				ft_strdup 		\
				ft_strcpy 		\
				ft_strncpy 		\
				ft_strcat 		\
				ft_strncat 		\
				ft_strlcat 		\
				ft_strchr 		\
				ft_strrchr 		\
				ft_strstr 		\
				ft_strnstr 		\
				ft_strcmp 		\
				ft_strncmp 		\
				ft_atoi 		\
				ft_isalpha 		\
				ft_isdigit 		\
				ft_isalnum 		\
				ft_isascii 		\
			   	ft_isprint 		\
				ft_toupper 		\
				ft_tolower		\
# Assignment Part 2
FILENAMES	+=	ft_memalloc 	\
				ft_memdel 		\
				ft_strnew 		\
				ft_strdel 		\
				ft_strclr 		\
				ft_striter 		\
				ft_striteri	 	\
				ft_strmap 		\
				ft_strmapi 		\
				ft_strequ 		\
				ft_strnequ 		\
				ft_strsub 		\
				ft_strjoin 		\
				ft_strtrim 		\
				ft_strsplit	 	\
				ft_itoa 		\
				ft_putchar 		\
				ft_putstr 		\
				ft_putendl 		\
				ft_putnbr 		\
				ft_putchar_fd 	\
				ft_putchar_fd 	\
				ft_putstr_fd 	\
				ft_putendl_fd 	\
				ft_putnbr_fd	\
# Assignment Bonus
FILENAMES	+=	ft_lstnew		\
				ft_lstdelone	\
				ft_lstdel		\
				ft_lstadd		\
				ft_lstiter		\
				ft_lstmap		\
				ft_itoa_base	\
				ft_strtoupper	\
				ft_strtolower	\

CFILES 		= $(addsuffix .c, $(FILENAMES))
SOURCES		= $(addprefix src/, $(CFILES))
BUILD 		= $(addprefix build/, $(CFILES:.c=.o))
INCDIR		= -I inc/
FLAGS 		= -g -Wall -Wextra -Werror
CC 			= gcc

all: $(NAME)

$(NAME): $(SOURCES) | $(BUILD)
		ar rcs $@ $(BUILD)

build/%.o: src/%.c | build
		$(CC) $(FLAGS) $(INCDIR) -c $^ -o $@

clean:
		rm -rf build/

fclean: clean
		rm -rf $(NAME)

re: fclean all

build:
	mkdir build/

.PHONY: all clean fclean re
