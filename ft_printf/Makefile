NAME = libftprintf.a

SOURCES = ft_printf_hex.c ft_printf_int.c ft_printf_ptr.c ft_printf_uint.c \
ft_printf_utils.c ft_printf.c

OBJECTS = ${SOURCES:.c=.o}

CC = gcc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.o.c:
	${CC} ${CFLAGS} ${OBJECTS} $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all
