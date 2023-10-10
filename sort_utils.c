/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:11 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/10 15:39:42 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void set_targets(t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *b_head;
	t_dclist *a_head;

	a_head = *stack_a;
	b_head = *stack_b;
	while((*stack_a) != a_head->prev)
	{
		while(*stack_b != b_head->prev)
		{
			if(!(*stack_a)->target && (*stack_b)->content > (*stack_a)->content)
				(*stack_a)->target = (*stack_b);
			else if((*stack_b)->content > (*stack_a)->content
			&& (*stack_b)->content < (*stack_a)->target->content)
				(*stack_a)->target = (*stack_b);
			*stack_b = (*stack_b)->next;
		}
		if(!(*stack_a)->target && (*stack_b)->content > (*stack_a)->content)
			(*stack_a)->target = (*stack_b);
		else if((*stack_b)->content > (*stack_a)->content
		&& (*stack_b)->content < (*stack_a)->target->content)
			(*stack_a)->target = (*stack_b);
		*stack_b = b_head;
		*stack_a = (*stack_a)->next;
	} 
	*stack_b = b_head;
	while(*stack_b != b_head->prev)
	{
		if(!(*stack_a)->target && (*stack_b)->content > (*stack_a)->content)
			(*stack_a)->target = (*stack_b);
		else if((*stack_b)->content > (*stack_a)->content
		&& (*stack_b)->content < (*stack_a)->target->content)
			(*stack_a)->target = (*stack_b);
		*stack_b = (*stack_b)->next;
	}
	if(!(*stack_a)->target && (*stack_b)->content > (*stack_a)->content)
		(*stack_a)->target = (*stack_b);
	else if((*stack_b)->content > (*stack_a)->content
	&& (*stack_b)->content < (*stack_a)->target->content)
		(*stack_a)->target = (*stack_b);
	*stack_b = b_head;
	*stack_a = a_head;	
}

// int main(void)
// {
// 	t_data data;
// 	t_dclist *head;

// 	data.stack_b = NULL;
// 	data.stack_a = lst_new_node(1);
// 	lst_prev_next(&data.stack_a, lst_new_node(4));
// 	lst_prev_next(&data.stack_a, lst_new_node(99));
// 	lst_prev_next(&data.stack_a, lst_new_node(7));
// 	lst_prev_next(&data.stack_a, lst_new_node(64));
// 	lst_prev_next(&data.stack_a, lst_new_node(22));
// 	lst_prev_next(&data.stack_a, lst_new_node(0));
// 	lst_prev_next(&data.stack_a, lst_new_node(8));
// 	lst_prev_next(&data.stack_a, lst_new_node(-3));
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