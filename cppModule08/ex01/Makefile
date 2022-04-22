NAME	= Span

SRC		= ./sources/main.cpp ./sources/Span.cpp

COMP	= clang++

RM		= rm -f

FLAGS	= -Wall -Wextra -Werror

OBJ		= ${SRC:.cpp=.o}

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJd)
			$(COMP) $(FLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:	clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re