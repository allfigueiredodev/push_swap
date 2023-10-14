/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:14:39 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/14 01:56:16 by aperis-p         ###   ########.fr       */
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
		else if ( abs((*stack_b)->content - (*stack_a)->content) <
			abs((*stack_a)->content - (*stack_a)->target->content))
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

void sort_crescent(t_data data, t_dclist **list_a)
{
	(void)data;
	t_dclist *last;
	
	last = (*list_a)->prev;
	if(last->target == *list_a)
	{
		while(last->target == last->prev->target && !check_crescent_order(*list_a))
			rrx(list_a, 1);
		if(!check_crescent_order(*list_a))
			rrx(list_a, 1);
	}
}

void mergin_back(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_a(stack_b, stack_a);
	while(*stack_b)
	{
		sort_crescent(data, stack_a);
		if(*stack_b)
			push_a(stack_b, stack_a);
		// if(check_crescent_order(*stack_a))
		// {
		// 	push_a(stack_b,	stack_a);
		// 	sort_crescent(data,	stack_a);
		// }
		// else
		// {
		// 	while(*stack_b)
		// 		push_a(stack_b,	stack_a);
		// }
	}
	sort_crescent(data, stack_a);
}