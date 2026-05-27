NAME = libftprintf.a
TEST = ft_printf_test

SOURCES = \
	ft_printf.c ft_putnbr.c ft_putnbr_base.c ft_putstr.c ft_putpointer.c ft_putvar.c ft_putwidth.c \
	helper.c ft_lstformat.c ft_putunnum.c ft_return.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $(OBJECTS)

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c $(NAME) -o $(TEST)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all bonus clean fclean re
