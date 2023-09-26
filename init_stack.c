/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:57:12 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/26 15:07:01 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_data *data)
{
	data = (t_data *)malloc(sizeof(t_data*));
	data->stack_a = (t_list *)malloc(sizeof(t_list));
	data->stack_b = (t_list *)malloc(sizeof(t_list));
	data->total_nbrs = 0;
}

void init_data(char *nbr_list, t_list *stack)
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
		atoied = (int *)malloc(sizeof(int));
		*atoied = ft_atoi(nbrs[i]);
		if(!stack)
			stack = ft_lstnew(atoied);
		else
			ft_lstadd_back(&stack, ft_lstnew(atoied));
		i++;
	}
	print_list(stack);
}

// int main(void)
// {
// 	t_list *stack;
// 	stack = NULL;
// 	init_data("4 99 7 64 22 0 1 -3", stack);
// 	return(0);
// }