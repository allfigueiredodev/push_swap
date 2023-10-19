/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:19 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:23:42 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (!check_crescent_order(data->stack_a))
		sx(&data->stack_a, 1);
}

void	sort_three(t_dclist **stack_a)
{
	t_dclist	*head;
	t_dclist	*greater_content;

	if (check_crescent_order(*stack_a))
		return ;
	head = *stack_a;
	greater_content = *stack_a;
	*stack_a = (*stack_a)->next;
	while (*stack_a != head)
	{
		if ((*stack_a)->content > greater_content->content)
			greater_content = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	if (*stack_a == greater_content)
		rx(stack_a, 1);
	else if ((*stack_a)->next == greater_content)
		rrx(stack_a, 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sx(stack_a, 1);
	fix_index(stack_a);
}

void	sort_four(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_b(stack_a, stack_b);
	sort_three(&data->stack_a);
	if ((*stack_a)->content > (*stack_b)->content)
		push_a(stack_b, stack_a);
	else if ((*stack_a)->next->content > (*stack_b)->content)
	{
		rx(stack_a, 1);
		push_a(stack_b, stack_a);
		rrx(stack_a, 1);
	}
	else if ((*stack_a)->prev->content > (*stack_b)->content)
	{
		rrx(stack_a, 1);
		push_a(stack_b, stack_a);
		rx(stack_a, 1);
		rx(stack_a, 1);
	}
	else
	{
		push_a(stack_b, stack_a);
		rx(stack_a, 1);
	}
}

void	sort_five(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist	*head;

	push_b(stack_a, stack_b);
	sort_four(data, stack_a, stack_b);
	if ((*stack_b)->content < (*stack_a)->content)
	{
		push_a(stack_b, stack_a);
		return ;
	}
	else if ((*stack_b)->content > (*stack_a)->prev->content)
	{
		push_a(stack_b, stack_a);
		rx(stack_a, 1);
		return ;
	}
	head = *stack_a;
	while ((*stack_b)->content > (*stack_a)->content)
		rx(stack_a, 1);
	push_a(stack_b, stack_a);
	while (*stack_a != head)
		rx(stack_a, 1);
}

void	sort_big_stack(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (dc_lstsize(*stack_a) > 3)
	{
		set_min_max_b(data);
		set_cost_direction(data, stack_a, stack_b);
		fill_b(stack_a, stack_b);
		if (check_early_sort(*stack_a, *stack_b))
		{
			mergin_back(data, stack_a, stack_b);
			return ;
		}
	}
	sort_three(stack_a);
	sort_decrescent(*data, stack_b);
	mergin_back(data, stack_a, stack_b);
}
