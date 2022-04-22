SRCS_PH = main.c srcs.c usage.c

OBJS    = ${SRCS_PH:.c=.o}

NAME    = philo

RM      = rm -f

CFLAGS  = -Wall -Wextra -Werror

all:	$(NAME)
$(NAME):		$(OBJS)
		gcc ${CFLAGS} -c ${SRCS_PH}
		gcc ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		${RM} ${OBJS}

fclean:
		${RM} ${OBJS} ${NAME}

re:		fclean all
.PHONY: all clean fclean re
