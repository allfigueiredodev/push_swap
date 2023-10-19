/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:10:37 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:23:58 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	downward_path(t_data data, t_dclist *list_b)
{
	int	total;

	total = dc_lstsize(list_b) - data.stack_b_max->index;
	return (total);
}

int	check_shortest_path(t_data data, t_dclist *list_b)
{
	if (downward_path(data, list_b) < data.stack_b_max->index)
		return (0);
	return (1);
}

void	sort_crescent(t_data *data, t_dclist **list)
{
	if (data->stack_b_min != *list)
	{
		while (data->stack_b_min != *list)
		{
			if (downward_moves(data,
					data->stack_b_min) <= upward_moves(data->stack_b_min))
			{
				while (*list != data->stack_b_min)
					rrx(list, 1);
			}
			else
			{
				while (*list != data->stack_b_min)
					rx(list, 1);
			}
		}
	}
}

void	sort_decrescent(t_data data, t_dclist **list_b)
{
	t_dclist	*head;

	fix_index(list_b);
	head = *list_b;
	if (!check_decrescent_order(*list_b))
	{
		if (!check_shortest_path(data, *list_b))
		{
			while (*list_b != data.stack_b_max)
				rrx(list_b, 2);
		}
		else
		{
			while (*list_b != data.stack_b_max)
				rx(list_b, 2);
		}
	}
}

int	sort(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	if (dc_lstsize(data->stack_a) == 2)
		sort_two(data);
	else if (dc_lstsize(data->stack_a) == 3)
		sort_three(&data->stack_a);
	else if (dc_lstsize(data->stack_a) == 4)
		sort_four(data, stack_a, stack_b);
	else if (dc_lstsize(data->stack_a) == 5)
		sort_five(data, stack_a, stack_b);
	else if (dc_lstsize(*stack_a) > 5)
		sort_big_stack(data, stack_a, stack_b);
	return (0);
}
