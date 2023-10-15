/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/15 05:29:04 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_down_both(t_dclist *cheapest, t_dclist **stack_a, t_dclist **stack_b)
{
	if(cheapest->target->index != 0 && cheapest->index != 0)
	{
		while(cheapest->target->index != 0 && cheapest->index != 0)
			rrr(stack_a, stack_b);		
	}
	if(cheapest->index != 0)
	{
		while(cheapest->index != 0)
			rrx(stack_a, 1);
	}
	if(cheapest->target->index != 0)
	{
		while(cheapest->target->index != 0)
			rrx(stack_b, 2);
	}
	push_b(stack_a, stack_b);
}

void rotate_up_both(t_dclist *cheapest, t_dclist **stack_a, t_dclist **stack_b)
{
	if(cheapest->target->index != 0 && cheapest->index != 0)
	{
		while(cheapest->target->index != 0 && cheapest->index != 0)
			rr(stack_a, stack_b);		
	}
	if(cheapest->index != 0)
	{
		while(cheapest->index != 0)
			rx(stack_a, 1);
	}
	if(cheapest->target->index != 0)
	{
		while(cheapest->target->index != 0)
			rx(stack_b, 2);
	}
	push_b(stack_a, stack_b);
}

void rotate_oposite_direction_a(t_dclist *cheapest, t_dclist **stack_a, t_dclist **stack_b)
{
	if(cheapest->target->index != 0 || cheapest->index != 0)
	{
		if(cheapest->index != 0)
		{
			while(cheapest->index != 0)
				rrx(stack_a, 1);
		}
		if(cheapest->target->index != 0)
		{
			while(cheapest->target->index != 0)
				rx(stack_b, 2);
		}
	}
	push_b(stack_a, stack_b);
}

void rotate_oposite_direction_b(t_dclist *cheapest, t_dclist **stack_a, t_dclist **stack_b)
{
	if(cheapest->target->index != 0 || cheapest->index != 0)
	{
		if(cheapest->index != 0)
		{
			while(cheapest->index != 0)
				rx(stack_a, 1);
		}
		if(cheapest->target->index != 0)
		{
			while(cheapest->target->index != 0)
				rrx(stack_b, 2);
		}
	}
	push_b(stack_a, stack_b);
}

void	fill_b(t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *cheapest; 
	
	cheapest = check_cheapest(*stack_a);
	if((*stack_a)->cost == 1)
	{
		push_b(stack_a, stack_b);
		return ;
	}
	else if(!cheapest->stack_a_direction && !cheapest->target_direction)
		rotate_down_both(cheapest, stack_a, stack_b);
	else if(cheapest->stack_a_direction && cheapest->target_direction)
		rotate_up_both(cheapest, stack_a, stack_b);
	else if(!cheapest->stack_a_direction && cheapest->target_direction)
		rotate_oposite_direction_a(cheapest, stack_a, stack_b);
	else if(cheapest->stack_a_direction && !cheapest->target_direction)
		rotate_oposite_direction_b(cheapest, stack_a, stack_b);
}