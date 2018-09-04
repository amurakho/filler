# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 16:46:31 by amurakho          #+#    #+#              #
#    Updated: 2018/08/29 16:46:32 by amurakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = visu.c getmap_xy.c put_pixel.c

OBJ = $(SRC:.c=.o)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) -L../includes/mlx/ -lmlx -framework OpenGL -framework AppKit ../libft/libft.a

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

