SRCS = ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c \
	   ./libft/ft_memccpy.c ./libft/ft_isdigit.c ./libft/ft_tolower.c \
	   ./libft/ft_toupper.c ./libft/ft_isascii.c ./libft/ft_isalpha.c \
	   ./libft/ft_isalnum.c ./libft/ft_isprint.c ./libft/ft_strlen.c \
	   ./libft/ft_memmove.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
	   ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
	   ./libft/ft_atoi.c ./libft/ft_strdup.c ./libft/ft_strnstr.c \
	   ./libft/ft_calloc.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c \
	   ./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c \
	   ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_putnbr_fd.c \
	   ./libft/ft_strmapi.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
	   ./libft/ft_putendl_fd.c ./libft/ft_utoa.c ./libft/ft_itoa_hex.c \
	   ft_printf.c put_p_hex_low.c put_p_hex_up.c put_p_int.c \
	   put_p_pointer.c put_hex_up.c put_hex_low.c wht_spec.c put_p_char.c \
	   functions.c ft_printf.c put_p_str.c

SRCS_PR = ft_printf.c put_p_hex_low.c put_p_hex_up.c put_p_int.c put_p_pointer.c put_hex_up.c put_hex_low.c wht_spec.c put_p_char.c functions.c ft_printf.c put_p_str.c

OBJS    = ${SRCS:.c=.o}

NAME    = libftprintf.a

CC      = gcc

RM      = rm -f

CFLAGS  = -Wall -Wextra -Werror

all:	$(NAME)
$(NAME):		$(OBJS)
		${CC} ${CFLAGS} -c ${SRCS_PR}
		make -C ./libft/
		cp ./libft/libft.a ./
		ar rcs ${NAME} ${OBJS} libft.a

clean:
		${RM} ${OBJS}
		make clean -C libft

fclean:
		${RM} ${OBJS} ${NAME}
		make fclean -C libft
		${RM} libft.a

re:		fclean all
.PHONY: all clean fclean re
