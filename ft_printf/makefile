NAME = libftprintf.a

HEADERS = ft_printf.h

SRCS = ft_printf.c ft_putone.c ft_puttwo.c ft_swprint.c

OBJETS = ${SRCS:%.c=./.build/%.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIB = ar -rc

./.build/%.o : %.c
	${CC} -I. -o $@ -c $? ${FLAGS}

${NAME}	 : ${OBJETS}
		${LIB} ${NAME} ${OBJETS}

all: 
	mkdir -p .build
	make ${NAME}

clean :
	rm -rf .build

fclean : clean
	rm -f ${NAME}

re :  fclean all

PHONY = all clean fclean re
