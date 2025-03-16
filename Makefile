NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src_files/operations.c src_files/parsing.c src_files/push_swap.c src_files/sorting.c \
		utils/utils_1.c utils/utils_2.c utils/utils_3.c utils/utils_4.c utils/utils_linked_list.c \
		the_rules/push.c the_rules/reverse_rotate.c the_rules/rotate.c the_rules/swap.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
