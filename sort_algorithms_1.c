/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:19 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/15 03:23:05 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_data *data)
{
	if(!check_crescent_order(data->stack_a))
		sx(&data->stack_a, 1);
	// return (1);
}

void sort_three(t_dclist **stack_a)
{
	t_dclist *head;
	t_dclist *greater_content;
	
	if(check_crescent_order(*stack_a))
		return ;
	head = *stack_a;
	greater_content = *stack_a;
	*stack_a = (*stack_a)->next;
	while(*stack_a != head)
	{
		if((*stack_a)->content > greater_content->content)
			greater_content = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	if(*stack_a == greater_content)
		rx(stack_a, 1);
	else if((*stack_a)->next == greater_content)
		rrx(stack_a, 1);
	if((*stack_a)->content > (*stack_a)->next->content)
		sx(stack_a, 1);	
	fix_index(stack_a);
}

void sort_four(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_b(stack_a, stack_b);
	set_min_max(data);
	sort_three(&data->stack_a);
	set_targets_to_push_back(*data, stack_a, stack_b);
	mergin_back(*data, stack_a, stack_b);
	sort_crescent(*data, &data->stack_a);
	if(check_crescent_order(*stack_a))
		return ;	
}

void sort_big_stack(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while(dc_lstsize(*stack_a) > 3)
	{
		set_min_max(data);
		set_cost_direction(data, stack_a, stack_b);
		fill_b(stack_a, stack_b);
		// ft_printf("\nstack_a\n");
		// print_dlist(data->stack_a);
		// ft_printf("\nstack_b\n");
		// print_dlist(data->stack_b);
		// if(check_early_sort(*stack_a, *stack_b))
		// 	return ;
	}
	sort_three(stack_a);
	sort_decrescent(*data, stack_b);
	// ft_printf("\nstack_a\n");
	// print_dlist(data->stack_a);
	// ft_printf("\nstack_b\n");
	// print_dlist(data->stack_b);
	// set_targets_to_push_back(*data, stack_a, stack_b);
	// mergin_back(*data, stack_a, stack_b);
}

int sort(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	if(dc_lstsize(data->stack_a) == 2)
		sort_two(data);
	else if(dc_lstsize(data->stack_a) == 3)
		sort_three(&data->stack_a);
	else if(dc_lstsize(data->stack_a) == 4)
		sort_four(data, stack_a, stack_b);
	else if(dc_lstsize(*stack_a) >= 5)
		sort_big_stack(data, stack_a, stack_b);
	return(0);
}