/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/12 20:57:13 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_down_both(t_dclist **stack_a, t_dclist **stack_b)
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

void rotate_up_both(t_dclist **stack_a, t_dclist **stack_b)
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

void rotate_oposite_direction_a(t_dclist **stack_a, t_dclist **stack_b)
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

void rotate_oposite_direction_b(t_dclist **stack_a, t_dclist **stack_b)
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

void	fill_b(t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *cheapest; 
	
	cheapest = check_cheapest(stack_a);
	if((*stack_a)->cost == 1)
	{
		push_b(stack_a, stack_b);
		return ;
	}
	else if(!(*stack_a)->stack_a_direction && !(*stack_a)->target_direction)
		rotate_down_both(stack_a, stack_b);
	else if((*stack_a)->stack_a_direction && (*stack_a)->target_direction)
		rotate_up_both(stack_a, stack_b);
	else if(!(*stack_a)->stack_a_direction && (*stack_a)->target_direction)
		rotate_oposite_direction_a(stack_a, stack_b);
	else if((*stack_a)->stack_a_direction && !(*stack_a)->target_direction)
		rotate_oposite_direction_b(stack_a, stack_b);
	// ft_printf("\nstack_a\n");
	// print_dlist(*stack_a);
	// ft_printf("\nstack_b\n");
	// print_dlist(*stack_b);
}