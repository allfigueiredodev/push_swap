/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/12 11:29:56 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 

void fill_b(t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *cheapest; 
	
	cheapest = check_cheapest(stack_a);
	if((*stack_a)->cost == 1)
	{
		push_b(stack_a, stack_b);
		return ;
	}
	else if(!(*stack_a)->stack_a_direction && !(*stack_a)->target_direction)
	{
		while((*stack_a)->target->index != 0 || (*stack_a)->index != 0)
			rrr(stack_a, stack_b);
		if((*stack_a)->stack_a_direction != 0)
		{
			while((*stack_a)->index != 0)
				rrx(stack_a, 1);
		}
		else if((*stack_a)->target->index != 0)
		{
			while((*stack_a)->target->index != 0)
				rrx(stack_b, 2);
		}
		push_b(stack_a, stack_b);
	}
	else if((*stack_a)->stack_a_direction && (*stack_a)->target_direction)
	{
		while((*stack_a)->target->index != 0 || (*stack_a)->index != 0)
			rr(stack_a, stack_b);
		if((*stack_a)->index != 0)
		{
			while((*stack_a)->index != 0)
				rx(stack_a, 1);
		}
		else if((*stack_a)->target->index != 0)
		{
			while((*stack_a)->target->index != 0)
				rx(stack_b, 2);
		}
		push_b(stack_a, stack_b);
	}
	else if(!(*stack_a)->stack_a_direction && (*stack_a)->target_direction)
	{
		if((*stack_a)->target->index != 0 || (*stack_a)->index != 0)
		{
			if((*stack_a)->index != 0)
			{
				while((*stack_a)->index != 0)
					rrx(stack_a, 1);
			}
			else if((*stack_a)->target->index != 0)
			{
				while((*stack_a)->target->index != 0)
					rx(stack_b, 2);
			}
		}
		push_b(stack_a, stack_b);
	}
	else if((*stack_a)->stack_a_direction && !(*stack_a)->target_direction)
	{
		if((*stack_a)->target->index != 0 || (*stack_a)->index != 0)
		{
			if((*stack_a)->index != 0)
			{
				while((*stack_a)->index != 0)
					rx(stack_a, 1);
			}
			else if((*stack_a)->target->index != 0)
			{
				while((*stack_a)->target->index != 0)
					rrx(stack_b, 2);
			}
		}
		push_b(stack_a, stack_b);
	}
}