/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:32:23 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/10 00:23:45 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int total_downward_moves(t_data data)
{
	int total;

	total = dc_lstsize(data.stack_b) - data.stack_b_max->index;
	return(total);
}

int total_upward_moves(t_data data)
{
	int total;
	
	total = data.stack_b_max->index;
	return(total);
}

int check_cheapest(t_data data,  t_dclist **stack_a, t_dclist **stack_b)
{
	(void)data;
	int total_moves = 0;
	t_dclist *head;
	
	head = *stack_a;
	set_targets(stack_a, stack_b);
	ft_printf("content: %d, target: %d \n", (*stack_a)->content, (*stack_a)->target->content);
	*stack_a = (*stack_a)->next;
	while(*stack_a != head)
	{
		// if((*stack_a)->content > data.stack_b_max->content || (*stack_a)->content < data.stack_b_min->content)
		// {
		// 	if(total_downward_moves(data) <= total_upward_moves(data))
		// 		total_moves = total_downward_moves(data) + 1;
		// 	else
		// 		total_moves = total_upward_moves(data) + 1;			
		// }
		ft_printf("content: %d, target: %d \n", (*stack_a)->content, (*stack_a)->target->content);
		*stack_a = (*stack_a)->next;
		// else
		// {
			
		// }
	}
	return (total_moves);
}

void sort(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	(void)data;
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	print_dlist(*stack_a);
	print_dlist(*stack_b);
	// set_min_max(data);
	check_cheapest(*data, stack_a, stack_b);
}

// int main(void)
// {
// 	t_data data;

// 	data.stack_a = lst_new_node(39);
// 	lst_prev_next(&data.stack_a, lst_new_node(43));
// 	lst_prev_next(&data.stack_a, lst_new_node(46));
// 	lst_prev_next(&data.stack_a, lst_new_node(88));
// 	lst_prev_next(&data.stack_a, lst_new_node(33));
// 	lst_prev_next(&data.stack_a, lst_new_node(6));
// 	lst_prev_next(&data.stack_a, lst_new_node(50));
// 	lst_prev_next(&data.stack_a, lst_new_node(53));
// 	lst_prev_next(&data.stack_a, lst_new_node(48));
// 	lst_prev_next(&data.stack_a, lst_new_node(99));
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	set_min_max(&data);
// 	ft_printf("min: %d\n", data.stack_b_min->content);
// 	ft_printf("max: %d\n", data.stack_b_max->content);
// 	print_dlist(data.stack_b);
// 	ft_printf("upward: %d\n", total_upward_moves(data));
// 	ft_printf("downward: %d\n", total_downward_moves(data));
// }