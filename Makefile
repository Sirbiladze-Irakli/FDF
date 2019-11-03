# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:44:07 by cdubuque          #+#    #+#              #
#    Updated: 2019/11/03 21:38:46 by jormond-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF = fdf

INC = ./inc/fdf.h

LIB = libft/libft.a -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FDFFILES = main.c valid_map.c read_map.c tools.c window_init.c draw_lines.c \
			rotates.c events.c change_col.c 
FDFSRC = $(addprefix src/,$(FDFFILES))

FDFOBJ = $(addprefix obj/,$(FDFFILES:.c=.o))

all : $(FDF)

$(FDF) : $(FDFOBJ)
	@make -C libft/
	@gcc -o $(FDF) $(FDFOBJ) $(LIB)
	@echo "$(FDF):     $(GREEN)$(FDF) was created$(RESET)"

obj/%.o: src/%.c $(INC)
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(FDF)

re : fclean all
