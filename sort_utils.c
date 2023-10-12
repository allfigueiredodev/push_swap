/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:11 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/12 11:05:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dclist *check_cheapest(t_dclist **stack_a)
{
	t_dclist *head;
	t_dclist *cheapest;

	head = (*stack_a)->prev;
	cheapest = *stack_a;
	while(*stack_a != head)
	{
		// if(!cheapest)
		// 	cheapest = &(*stack_a);
		if((*stack_a)->cost == 1)
		{
			cheapest = *stack_a;
			return (cheapest);
		}
		else if((*stack_a)->cost < cheapest->cost)
			cheapest = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	return(cheapest);
}

void fix_indexes(t_dclist **stack_a, t_dclist **stack_b)
{
	fix_index(stack_a);
	fix_index(stack_b);
}

void fix_index(t_dclist **list)
{
	t_dclist *head;
	
	if(!(*list))
		return ;
	head = *list;
	(*list)->index = 0;
	*list = (*list)->next;
	while(*list != head)
	{
		(*list)->index = (*list)->prev->index + 1;
		*list = (*list)->next;
	}
}

int check_for_middle(t_dclist *list)
{
	int total;

	total = dc_lstsize(list) / 2;
	return (total);
}

void set_min_max(t_data *data)
{
	t_dclist *min;
	t_dclist *max;
	t_dclist *head;

	min = data->stack_b;
	max = data->stack_b;
	head = data->stack_b;
	if(data->stack_b->content < min->content)
		min = data->stack_b;
	else if(data->stack_b->content > max->content)
		max =  data->stack_b;
	data->stack_b = data->stack_b->next;
	while(data->stack_b != head)
	{
		if(data->stack_b->content < min->content)
			min = data->stack_b;
		else if(data->stack_b->content > max->content)
			max = data->stack_b;
		data->stack_b = data->stack_b->next;
	}
	data->stack_b_min = min;
	data->stack_b_max = max;
	data->stack_b = head;
}

void find_nearest(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	if(!(*stack_a)->target && (*stack_b)->content > (*stack_a)->content)
		(*stack_a)->target = (*stack_b);
	else if((*stack_b)->content > (*stack_a)->content
	&& (*stack_b)->content < (*stack_a)->target->content)
		(*stack_a)->target = (*stack_b);
	else
		(*stack_a)->target = data.stack_b_max;
}

void set_targets(t_data data, t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *b_head;
	t_dclist *a_head;
	
	a_head = *stack_a;
	b_head = *stack_b;
	while(*stack_a != a_head->prev)
	{
		while(*stack_b != b_head->prev)
		{
			find_nearest(data, stack_a, stack_b);
			*stack_b = (*stack_b)->next;
		}
		find_nearest(data, stack_a, stack_b);
		*stack_b = b_head;
		*stack_a = (*stack_a)->next;
	} 
	*stack_b = b_head;
	while(*stack_b != b_head->prev)
	{
		find_nearest(data, stack_a, stack_b);
		*stack_b = (*stack_b)->next;
	}
	find_nearest(data, stack_a, stack_b);
	(*stack_a)->target = data.stack_b_max;	
	*stack_b = b_head;
	*stack_a = a_head;	
}

// int main(void)
// {
// 	t_data data;
// 	t_dclist *head;
// 	t_dclist *result;

// 	data.stack_a = lst_new_node(1);
// 	lst_prev_next(&data.stack_a, lst_new_node(4));
// 	lst_prev_next(&data.stack_a, lst_new_node(99));
// 	lst_prev_next(&data.stack_a, lst_new_node(7));
// 	lst_prev_next(&data.stack_a, lst_new_node(64));
// 	lst_prev_next(&data.stack_a, lst_new_node(22));
// 	lst_prev_next(&data.stack_a, lst_new_node(0));
// 	lst_prev_next(&data.stack_a, lst_new_node(8));
// 	lst_prev_next(&data.stack_a, lst_new_node(-3));
// 	head = data.stack_a;
// 	data.stack_a->cost = 30;
// 	data.stack_a = data.stack_a->next;
// 	while(data.stack_a != head)
// 	{
// 		data.stack_a->cost = data.stack_a->prev->cost + 1;
// 		data.stack_a = data.stack_a->next;
// 	}
// 		data.stack_a->cost = 15;
// 	result = check_cheapest(&head);
// 	ft_printf("cost: %d\n", result->cost);
	
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	push_b(&data.stack_a, &data.stack_b);
// 	set_min_max(&data);
// 	print_dlist(data.stack_a);
// 	print_dlist(data.stack_b);
// 	set_targets(&data.stack_a, &data.stack_b);
// 	head = data.stack_a;
// 	ft_printf("content: %d, target: %d \n", data.stack_a->content, data.stack_a->target->content);
// 	data.stack_a = data.stack_a->next;
// 	while(head != data.stack_a)
// 	{
// 		ft_printf("content: %d, target: %d \n", data.stack_a->content, data.stack_a->target->content);
// 		data.stack_a = data.stack_a->next;
// 	}
// }