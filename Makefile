all:
	cc push_swap.c init_stack.c push_swap_utils.c ./libft/*.c -Wall -Werror -Wextra -g3 && ./a.out "4 99 7 64 22 0 1 -3"
