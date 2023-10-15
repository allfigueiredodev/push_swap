# NAME = push_swap
# LIBFT_PATH = ./libft
# LIBFT_MAKE = $(MAKE) -C $(LIBFT_PATH)
# LIBFT_LIB = $(LIBFT_PATH)/libft.a
# MAKE = make
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SRC = push_swap.c check_sort.c fill_a.c fill_b.c frees.c \
init_stack.c lst_utils.c movements.c push_swap_utils.c \
sort_utils.c cost_and_direction.c validations.c sort_algorithms_1.c \
sort_algorithms_2.c move_calculations.c

# OBJS = $(SRC:.c=.o)

all: $(NAME)
	$(CC) $(SRC) ./libft/*.c $(FLAGS) -g3 && ./a.out "7 1 -10 3 5 8 -2 6 4 9"
# why 0 at the beggin does not appear

# $(LIBFT_LIB):
# 	@make -C $(LIBFT_PATH)

# $(NAME): $(LIBFT_LIB) $(OBJS)
# 	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I ./ -Llibft -lft

# .c.o:
# 	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I ./

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out "2 1 7 4 -3 6"

# bonus: all

# clean:
# 	rm -rf $(OBJS)
# 	$(LIBFT_MAKE) clean

# fclean: clean
# 	rm -rf $(NAME)
# 	$(LIBFT_MAKE) fclean

# re: fclean all

# .PHONY: all clean fclean re

#git submodule update --remote --merge