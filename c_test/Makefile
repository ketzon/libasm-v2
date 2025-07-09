NAME= a.out
CC= gcc
CFLAGS= -Wall -Werror -Wextra -g
RM = rm -rf
SRCS= fonction/ft_strcpy.c fonction/ft_strcmp.c main.c fonction/ft_strdup.c
OBJS = ${SRCS:.c=.o}
.c.o:
	${CC} ${CFLAGS} -c $< -o $@
all: ${NAME}

${NAME}: ${OBJS} 
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
