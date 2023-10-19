/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:14:39 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 18:40:15 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_max_a(t_data *data)
{
	t_dclist	*min;
	t_dclist	*max;
	t_dclist	*head;

	min = data->stack_a;
	max = data->stack_a;
	head = data->stack_a;
	if (data->stack_a->content < min->content)
		min = data->stack_a;
	else if (data->stack_a->content > max->content)
		max = data->stack_a;
	data->stack_a = data->stack_a->next;
	while (data->stack_a != head)
	{
		if (data->stack_a->content < min->content)
			min = data->stack_a;
		else if (data->stack_a->content > max->content)
			max = data->stack_a;
		data->stack_a = data->stack_a->next;
	}
	data->stack_b_min = min;
	data->stack_b_max = max;
	data->stack_a = head;
}

t_dclist	*pick_closest_neighbour_below(t_dclist *stack_a, t_dclist *stack_b)
{
	t_dclist	*closest;
	t_dclist	*head;
	int			goal;

	goal = stack_b->content;
	head = stack_a;
	closest = NULL;
	stack_a = stack_a->next;
	while (stack_a != head)
	{
		if (stack_a->content > goal && !closest)
			closest = stack_a;
		else if (stack_a->content > goal && stack_a->content < closest->content)
			closest = stack_a;
		stack_a = stack_a->next;
	}
	if (stack_a->content > goal && !closest)
		closest = stack_a;
	else if (stack_a->content > goal && stack_a->content < closest->content)
		closest = stack_a;
	return (closest);
}

void	min_to_head(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	if (*stack_a == data->stack_b_min)
		push_a(stack_b, stack_a);
	else
	{
		if (downward_moves(data,
				data->stack_b_min) <= upward_moves(data->stack_b_min))
		{
			while (*stack_a != data->stack_b_min)
				rrx(stack_a, 1);
		}
		else
		{
			while (*stack_a != data->stack_b_min)
				rx(stack_a, 1);
		}
		push_a(stack_b, stack_a);
	}
}

void	target_to_head(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist	*closest;

	closest = pick_closest_neighbour_below(*stack_a, *stack_b);
	if (*stack_a == closest)
		push_a(stack_b, stack_a);
	else
	{
		if (downward_moves(data, closest) <= upward_moves(closest))
		{
			while (*stack_a != closest)
				rrx(stack_a, 1);
		}
		else
		{
			while (*stack_a != closest)
				rx(stack_a, 1);
		}
		push_a(stack_b, stack_a);
	}
}

void	mergin_back(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	set_min_max_a(data);
	while (*stack_b)
	{
		fix_index(stack_a);
		if ((*stack_b)->content > data->stack_b_max->content
			|| (*stack_b)->content < data->stack_b_min->content)
		{
			min_to_head(data, stack_a, stack_b);
		}
		else
			target_to_head(data, stack_a, stack_b);
		set_min_max_a(data);
	}
	sort_crescent(data, stack_a);
}
