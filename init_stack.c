/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:57:12 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/04 16:54:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_data *data)
{
	data->stack_a = (t_dclist *)ft_calloc(1, sizeof(t_dclist));
	// data->stack_b = (t_dclist *)ft_calloc(1, sizeof(t_dclist));
	data->total_nbrs = 0;
	// if(!data->stack_a || !data->stack_b)
	if(!data->stack_a)
	{
		if(data->stack_a)
			free(data->stack_a);
		// if(data->stack_b)
		// 	free(data->stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

int init_data_from_arguments(int argc, char **argv, t_data *data)
{
	int total_arguments;
	int i;
	int nbr;

	total_arguments = argc - 1;
	i = 0;
	while(i <= total_arguments)
	{

		nbr = ft_atol(argv[i]);
		if(nbr < INT_MIN || nbr > INT_MAX)
			return(0);
		if(check_for_digit(argv[i]) && !data->stack_a->content)
		{
			free(data->stack_a);
			data->stack_a = lst_new_node(nbr);
		}
		else if(check_for_digit(argv[i]) && data->stack_a)
			lst_prev_next(&(data->stack_a), lst_new_node(nbr));
		i++;
	}
	return(1);
}

int init_data_from_string(char *nbr_list, t_data *data)
{
	int i;
	char **nbrs;
	long atoied;
	if(!nbr_list)
		return(0);
	nbrs = ft_split(nbr_list, ' ');
	i = 0;
	while(nbrs[i])
	{
		atoied = ft_atol(nbrs[i]);
		if(atoied < INT_MIN || atoied > INT_MAX)
		{
			free_nbrs(nbrs);
			return(0);
		}
		if(!data->stack_a->content)
		{
			free(data->stack_a);
			data->stack_a = lst_new_node(atoied);	
		}
		else
			lst_prev_next(&data->stack_a, lst_new_node(atoied));
		i++;
	}
	free_nbrs(nbrs);
	return(1);
}

int init_data(int argc, char **argv, t_data *data)
{
	if(argc == 2)
	{
		if(!init_data_from_string(argv[1], data))
			return(0);
	}
	else if (argc > 2)
	{
		if(!init_data_from_arguments(argc, argv, data))
			return(0);
	}
	return(1);
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