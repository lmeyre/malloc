ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

COMPILER = clang

FLAG = -Wall -Werror -Wextra

NAME = libft_malloc_$(HOSTTYPE).so

MAKE = Makefile

INCLUDESDIR = includes

HEADER = malloc.h

SRCSDIR = srcs/

SRCS_NAME =	malloc.c \
			heap.c \
			block.c \
			utils.c \
			statiks.c \
			misc.c \
			free.c \
			realloc.c \
			show_alloc_mem.c \

SRCS = $(addprefix $(SRCSDIR), $(SRCS_NAME))

BINDIR = objs/

BIN_NAME = $(SRCS_NAME:.c=.o)

BIN = $(addprefix $(BINDIR), $(BIN_NAME))

.PHONY: all clean fclean re

all : $(NAME)

$(NAME) : $(BIN)
	@echo "Compiling $(NAME)"
	@ln -sf $(NAME) libft_malloc.so
	@ar rc $(NAME) $(BIN)
 
$(BINDIR)%.o: $(SRCSDIR)%.c
	@$(COMPILER) $(FLAG) -I INCLUDESDIR -o $@ -c $<

clean:
	@echo "Cleaning Bins"
	@/bin/rm -rf $(BIN)

fclean: clean
	@echo "Full Cleaning"
	@/bin/rm -rf $(NAME)
	@rm -rf libft_malloc.so

re: fclean all
