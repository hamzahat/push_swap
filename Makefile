NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c parsing.c operations.c utils.c sorting.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
