/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:14:39 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/13 11:56:07 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int downward_path(t_data data, t_dclist *list_b)
{
	int total;

	total = dc_lstsize(list_b) - data.stack_b_max->index;
	return (total);
}

// int upward_path(t_data data, t_dclist *list_b)
// {
// 	int total;

// 	total = data.stack_b_max->index;
// 	return (total);
// }

int check_shortest_path(t_data data, t_dclist *list_b)
{
	if(downward_path(data, list_b) < data.stack_b_max->index)
		return(0);
	return(1);
}

void sort_decrescent(t_data data, t_dclist **list_b)
{
	t_dclist *head;

	fix_index(list_b);
	head = *list_b;
	if(!check_decrescent_order(*list_b))
	{
		if(!check_shortest_path(data, *list_b))
		{
			while(*list_b != data.stack_b_max)
				rrx(list_b, 2);	
		}
		else
		{
			while(*list_b != data.stack_b_max)
				rx(list_b, 2);
		}		
	}
}