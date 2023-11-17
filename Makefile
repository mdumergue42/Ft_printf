SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_strlen.c \
		ft_putnbr_uns_int.c \
		ft_putnbr_hexa.c

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