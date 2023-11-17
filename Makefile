SRCS = 

NAME    = libftprintf.a

OBJS    =  ${SRCS:.c=.o}

HEADERS    = includes/

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${OBJS} : 
	$(CC) $(CFLAGS) -I ${HEADERS} -c ${@:.o=.c} -o $@

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re