NAME = push_swap
LIBFT_PATH = ./libft
LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
LIBFT_LIB = $(LIBFT_PATH)/libft.a
MAKE = make
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = push_swap.c check_sort.c fill_a.c fill_b.c frees.c \
init_stack.c lst_utils.c movements.c push_swap_utils.c \
sort_utils.c sort.c validations.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./push_swap 2 1 7 -4

bonus: all

clean:
	rm -rf $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -rf $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re

#git submodule update --remote --merge