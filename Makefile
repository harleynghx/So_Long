# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hang <hang@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 01:02:08 by hang              #+#    #+#              #
#    Updated: 2024/10/28 19:33:52 by hang             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PROG	= so_long

SRCS 	= srcs/so_long.c srcs/errors.c srcs/map.c srcs/graphics.c srcs/controls.c srcs/floodfill.c srcs/floodfill_collectibles.c
OBJS 	= ${SRCS:.c=.o}

CC 		= gcc 
CFLAGS 	= -Wall -Wextra -Werror -g

.c.o:
	@gcc ${CFLAGS} -Iminilibx-linux ${HEADER} -c $< -o $@

all: 		${PROG}

${PROG}:	${OBJS}
					@echo "\033[33m----Compiling lib----"
					@make re -C ./libft
					@$(CC) ${OBJS} -framework OpenGL -framework AppKit -o ${PROG} -Llibft -lft -Lminilibx-linux -lmlx
clean:
					@make clean -C ./libft
					@rm -f ${OBJS}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f ${PROG}

re:			fclean all


party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re party