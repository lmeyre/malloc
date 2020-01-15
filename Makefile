FLAG = -Wall -Werror -Wextra

VPATH = $(SRCS_DIR)

NAME = libft_malloc_$HOSTTYPE.so

MAKE = Makefile

INCLUDESDIR = includes

HEADER = $(INCLUDESDIR)/malloc.h

SRCDIR = srcs

SRC = srcs/main.c

BIN = $(SRC:.c=.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(MAKE) $(BIN) $(HEADER)
	@ar rc $(NAME) $(BIN)

%.o: %.c $(HEADER)
	@gcc -o $@ -c $< -I $(INCLUDESDIR)

clean:
	@/bin/rm -rf $(BIN)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all