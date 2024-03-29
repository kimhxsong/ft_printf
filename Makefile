.PHONY : all claen fclean re

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c\
		read_utils_1.c\
		read_utils_2.c\
		put_utils_1.c\
		put_utils_2.c\
		put_utils_3.c\
		utils/ft_atoi.c\
		utils/ft_calloc.c\
		utils/ft_isdigit.c\
		utils/ft_isspace.c\
		utils/ft_itoa.c\
		utils/ft_memset.c\
		utils/ft_putchar.c\
		utils/ft_putstr.c\
		utils/ft_strchr.c\
		utils/ft_strlen.c\
		utils/ft_uitoa_base.c\
		utils/ft_ulltoa_base.c\
		utils/ft_strdup.c\
		utils/ft_memcpy.c\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $@ $^

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
