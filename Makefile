# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/26 16:06:11 by amurakho          #+#    #+#              #
#    Updated: 2018/08/26 16:06:12 by amurakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amurakho.filler

SRCS := src/main.c 
SRCS +=	src/for_parsemap.c 
SRCS +=	src/get_line.c
SRCS +=	src/parse_fig.c 
SRCS +=	src/parse_map.c
SRCS +=	src/testing_fig.c
SRCS += src/testing_point.c
SRCS += src/token_size.c

FLAGS = -Wall -Werror -Wextra -I./inc

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C visu
	gcc -o $(NAME) $(FLAGS) $(OBJ) libft/libft.a

clean:
	make clean -C libft
	make clean -C visu
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C visu
	rm -f $(NAME)

re: fclean all
