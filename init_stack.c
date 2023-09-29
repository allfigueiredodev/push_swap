/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:57:12 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/28 21:06:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_data *data)
{
	data->stack_a = (t_list *)ft_calloc(1, sizeof(t_list));
	data->stack_b = (t_list *)ft_calloc(1, sizeof(t_list));
	data->total_nbrs = 0;
	if(!data->stack_a || !data->stack_b)
	{
		ft_printf("Bad allocation\n");
		return ;
	}
}

void init_data_from_arguments(int argc, char **argv, t_data *data)
{
	int total_arguments;
	int i;
	int *nbr;

	total_arguments = argc - 1;
	i = 0;
	while(i <= total_arguments)
	{
		nbr = (int *)ft_calloc(1, sizeof(int));
		*nbr = ft_atoi(argv[i]);
		if(check_for_digit(argv[i]) && !data->stack_a->content)
			data->stack_a = ft_lstnew(nbr);
		else if(check_for_digit(argv[i]) && data->stack_a)
			ft_lstadd_back(&(data->stack_a), ft_lstnew(nbr));
		i++;
	}
	print_list(data->stack_a);
}

void init_data_from_string(char *nbr_list, t_data *data)
{
	int i;
	char **nbrs;
	int *atoied;
	if(!nbr_list)
		return ;
	nbrs = ft_split(nbr_list, ' ');
	i = 0;
	while(nbrs[i])
	{
		atoied = (int *)ft_calloc(1, sizeof(int));
		*atoied = ft_atoi(nbrs[i]);
		if(!data->stack_a->content)
		{
			free(data->stack_a);
			data->stack_a = ft_lstnew(atoied);	
		}
		else
			ft_lstadd_back(&data->stack_a, ft_lstnew(atoied));
		i++;
	}
	count_list_size(data);
	free_nbrs(nbrs);
	print_list(data->stack_a);
}

void init_data(int argc, char **argv, t_data *data)
{
	if(argc == 2)
		init_data_from_string(argv[1], &data);
	else if (argc > 2)
		init_data_from_arguments(argc, argv, &data);
}

// int main(void)
// {
// 	t_list *stack;
// 	stack = NULL;
// 	init_data("4 99 7 64 22 0 1 -3", stack);
// 	return(0);
// }

// int main(int argc, char **argv)
// {
// 	t_data data;
	
// 	init_stack(&data);
// 	init_data_from_arguments(argc, argv, &data);
// }