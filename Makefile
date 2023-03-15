# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 11:28:30 by dcologgi          #+#    #+#              #
#    Updated: 2023/03/15 12:07:14 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = ./ft_printf/libftprintf.a

SERVER_SOURCES = server.c
CLIENT_SOURCES = client.c

SERVER_OBJECTS = ${SERVER_SOURCES:.c=.o}
CLIENT_OBJECTS = ${CLIENT_SOURCES:.c=.o}

NAME_SERVER = server
NAME_CLIENT = client

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@

all : ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${SERVER_OBJECTS} ${FT_PRINTF}
				${CC} ${SERVER_OBJECTS} ${FT_PRINTF} -o ${NAME_SERVER}

${NAME_CLIENT}: ${CLIENT_OBJECTS} ${FT_PRINTF}
				${CC} ${CLIENT_OBJECTS} ${FT_PRINTF} -o ${NAME_CLIENT}

${FT_PRINTF}:
				make -C ./ft_printf

clean :
		${RM} ${SERVER_OBJECTS} ${CLIENT_OBJECTS}
		make clean -C ./ft_printf

fclean : clean
		rm -f ${NAME_SERVER} ${NAME_CLIENT}
		rm -f ${FT_PRINTF}

re : fclean all
