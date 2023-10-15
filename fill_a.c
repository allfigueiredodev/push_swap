/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:14:39 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/15 08:13:57 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_nearest_above(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	(void)data;
	if((*stack_b)->content > (*stack_a)->content || !(*stack_a)->target)
	{
		if(!(*stack_a)->target)
			(*stack_a)->target = *stack_a;
		else if ((*stack_b)->content < (*stack_a)->target->content)
			(*stack_a)->target = *stack_b;
		else if (ft_abs((*stack_b)->content - (*stack_a)->content) <
			ft_abs((*stack_a)->content - (*stack_a)->target->content))
			(*stack_a)->target = *stack_b;
		else if ((*stack_a)->content > (*stack_a)->target->content)
			(*stack_a)->target = *stack_b;
	}
}

void set_targets_to_push_back(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *b_head;
	t_dclist *a_head;
	
	a_head = *stack_a;
	b_head = *stack_b;
	while(*stack_a != a_head->prev)
	{
		while(*stack_b != b_head->prev)
		{
			find_nearest_above(data, stack_a, stack_b);
			*stack_b = (*stack_b)->next;
		}
		find_nearest_above(data, stack_a, stack_b);
		*stack_b = b_head;
		*stack_a = (*stack_a)->next;
	} 
	*stack_b = b_head;
	while(*stack_b != b_head->prev)
	{
		find_nearest_above(data, stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
	find_nearest_above(data, stack_a, stack_b);
	*stack_b = b_head;
	*stack_a = a_head;
}

void mergin_back(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *last;

	last = (*stack_a)->prev;
	if(last->content > (*stack_b)->content)
	{
		rrx(stack_a, 1);
		push_a(stack_b, stack_a);
	}
	else
		push_a(stack_b, stack_a);
	while(*stack_b)
	{
		sort_crescent(data, stack_a, stack_b);
		if(*stack_b)
			push_a(stack_b, stack_a);
	}
	sort_crescent(data, stack_a, stack_b);
}