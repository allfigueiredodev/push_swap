all:
	cc push_swap.c frees.c validations.c init_stack.c push_swap_utils.c ./libft/*.c -Wall -Werror -Wextra -g3
	# cc init_stack.c push_swap_utils.c ./libft/*.c -Wall -Werror -Wextra -g3 && ./a.out

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out "4 4 99 7 64 22 0 1 -3"