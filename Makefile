all:
	cc push_swap.c sort.c check_sort.c sort_utils.c movements.c frees.c lst_utils.c validations.c init_stack.c push_swap_utils.c ./libft/*.c -Wall -Werror -Wextra -g3 && ./a.out "1 4 99 7 64 22 0 8 -3"
	# cc init_stack.c push_swap_utils.c ./libft/*.c -Wall -Werror -Wextra -g3 && ./a.out

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out "-3 0 2 7 10 22 64 1 4 9"
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out "4 99 7 64 22 0 1 -3"
	# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./a.out 4 99 7 64 22 0 1 -3

#git submodule update --remote --merge