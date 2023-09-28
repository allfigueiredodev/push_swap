/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:50:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/27 21:56:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void count_list_size(t_data *data)
{
	int total;
	t_list *temp;

	total = 0;
	temp = data->stack_a;
	while(temp)
	{
		total++;
		temp = temp->next;
	}
	data->total_nbrs = total;
}

void print_list(t_list *stack)
{
	t_list *temp;
	temp = stack;
	while(temp)
	{
		ft_printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}
