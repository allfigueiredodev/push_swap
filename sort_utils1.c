/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:11 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:28:16 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist	*check_cheapest(t_dclist *stack_a)
{
	t_dclist	*head;
	t_dclist	*cheapest;

	head = stack_a->prev;
	cheapest = stack_a;
	while (stack_a != head)
	{
		if (stack_a->cost == 1)
		{
			cheapest = stack_a;
			return (cheapest);
		}
		else if (stack_a->cost < cheapest->cost)
			cheapest = stack_a;
		stack_a = stack_a->next;
	}
	if (stack_a->cost < cheapest->cost)
		cheapest = stack_a;
	return (cheapest);
}

void	set_min_max_b(t_data *data)
{
	t_dclist	*min;
	t_dclist	*max;
	t_dclist	*head;

	min = data->stack_b;
	max = data->stack_b;
	head = data->stack_b;
	if (data->stack_b->content < min->content)
		min = data->stack_b;
	else if (data->stack_b->content > max->content)
		max = data->stack_b;
	data->stack_b = data->stack_b->next;
	while (data->stack_b != head)
	{
		if (data->stack_b->content < min->content)
			min = data->stack_b;
		else if (data->stack_b->content > max->content)
			max = data->stack_b;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b_min = min;
	data->stack_b_max = max;
	data->stack_b = head;
}

t_dclist	*pick_closest_neighbour_above(t_dclist *stack_a, t_dclist *stack_b)
{
	t_dclist	*closest;
	t_dclist	*head;
	int			goal;

	goal = stack_a->content;
	head = stack_b;
	closest = NULL;
	stack_b = stack_b->next;
	while (stack_b != head)
	{
		if (stack_b->content < goal && !closest)
			closest = stack_b;
		else if (stack_b->content < goal && stack_b->content > closest->content)
			closest = stack_b;
		stack_b = stack_b->next;
	}
	if (stack_b->content < goal && !closest)
		closest = stack_b;
	else if (stack_b->content < goal && stack_b->content > closest->content)
		closest = stack_b;
	return (closest);
}

void	find_nearest(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	(*stack_a)->target = NULL;
	if (!(*stack_a)->target && ((*stack_a)->content > data.stack_b_max->content
			|| (*stack_a)->content < data.stack_b_min->content))
		(*stack_a)->target = data.stack_b_max;
	else if (!(*stack_a)->target
		&& (*stack_a)->content < data.stack_b_max->content
		&& (*stack_a)->content > data.stack_b_min->content)
		(*stack_a)->target = pick_closest_neighbour_above(*stack_a, *stack_b);
}

void	set_targets(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist	*b_head;
	t_dclist	*a_head;

	a_head = *stack_a;
	b_head = *stack_b;
	while (*stack_a != a_head->prev)
	{
		find_nearest(data, stack_a, stack_b);
		*stack_a = (*stack_a)->next;
	}
	find_nearest(data, stack_a, stack_b);
	*stack_b = b_head;
	*stack_a = a_head;
}
