/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:57:12 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/27 21:48:15 by aperis-p         ###   ########.fr       */
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

// void init_data_from_arguments(char **argv, t_data *data)
// {
// 	argv++;
// 	while(*argv)
// 	{
// 		data->stack_a
// 	}
// }

// int main(void)
// {
// 	t_list *stack;
// 	stack = NULL;
// 	init_data("4 99 7 64 22 0 1 -3", stack);
// 	return(0);
// }