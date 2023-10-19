/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:32:23 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 16:40:41 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_cost_direction(t_data *data, t_dclist **stack_a, int is_new_edge)
{
	if (b_downward_moves(data, is_new_edge) <= b_upward_moves(data,
			is_new_edge))
	{
		(*stack_a)->cost = b_downward_moves(data, is_new_edge) + 1;
		(*stack_a)->target_direction = 0;
	}
	else
	{
		(*stack_a)->cost = b_upward_moves(data, is_new_edge) + 1;
		(*stack_a)->target_direction = 1;
	}
	if (a_downward_moves(data) <= a_upward_moves(data))
	{
		(*stack_a)->cost += a_downward_moves(data);
		(*stack_a)->stack_a_direction = 0;
	}
	else
	{
		(*stack_a)->cost += a_upward_moves(data);
		(*stack_a)->stack_a_direction = 1;
	}
}

void	set_cost_direction(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist	*head;

	head = *stack_a;
	set_targets(*data, stack_a, stack_b);
	fix_indexes(stack_a, stack_b);
	if ((*stack_a)->content > data->stack_b_max->content
		|| (*stack_a)->content < data->stack_b_min->content)
		check_cost_direction(data, stack_a, 1);
	else
		check_cost_direction(data, stack_a, 0);
	*stack_a = (*stack_a)->next;
	while (*stack_a != head)
	{
		if ((*stack_a)->content > data->stack_b_max->content
			|| (*stack_a)->content < data->stack_b_min->content)
			check_cost_direction(data, stack_a, 1);
		else
			check_cost_direction(data, stack_a, 0);
		*stack_a = (*stack_a)->next;
	}
}
