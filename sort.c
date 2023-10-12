/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:32:23 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/12 11:31:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int b_downward_moves(t_data *data)
{
	int total;
	
	total = dc_lstsize(data->stack_b) - data->stack_b_max->index;
	return(total);
}

int b_upward_moves(t_data *data)
{
	int total;
	//WRONG data->stack_b_max->index,
	//just works when *stack_a is greater or less
	//than min and max from stack_b, needs also to verify
	//when *stack_a target is between min and max e.g 7 > 4; 
	total = data->stack_b_max->index;
	return(total);
}

int a_downward_moves(t_data *data)
{
	int total;
	
	total = dc_lstsize(data->stack_a) - data->stack_a->index;
	return(total);
}

int a_upward_moves(t_data *data)
{
	int total;
	
	total = data->stack_a->index;
	return(total);
}
//HERE, data is breaking ward functions because its serving a copy and not the reference
void set_cost(t_data *data,  t_dclist **stack_a, t_dclist **stack_b)
{
	t_dclist *head;
	
	head = *stack_a;
	set_targets(*data, stack_a, stack_b);
	fix_indexes(stack_a, stack_b);
	if((*stack_a)->content > data->stack_b_max->content || (*stack_a)->content < data->stack_b_min->content)
	{
		if(b_downward_moves(data) <= b_upward_moves(data))
		{
			(*stack_a)->cost = b_downward_moves(data) + 1;
			(*stack_a)->target_direction = 0;
		}
		else
		{
			(*stack_a)->cost = b_upward_moves(data) + 1;
			(*stack_a)->target_direction = 1;
		}
		if(a_downward_moves(data) <= a_upward_moves(data))
		{
			(*stack_a)->cost += a_downward_moves(data);
			(*stack_a)->stack_a_direction = 0;
		}
		else
		{
			(*stack_a)->cost += a_upward_moves(data);
			(*stack_a)->stack_a_direction = 1;
		}
	}
	else
	{
		if(b_downward_moves(data) <= b_upward_moves(data))
		{
			(*stack_a)->cost = b_downward_moves(data) + 1;
			(*stack_a)->target_direction = 0;
		}
		else
		{
			(*stack_a)->cost = b_upward_moves(data) + 1;
			(*stack_a)->target_direction = 1;
		}
		if(a_downward_moves(data) <= a_upward_moves(data))
		{
			(*stack_a)->cost += a_downward_moves(data);
			(*stack_a)->stack_a_direction = 0;
		}
		else
		{
			(*stack_a)->cost += a_upward_moves(data);
			(*stack_a)->stack_a_direction = 1;
		}			
	}
	*stack_a = (*stack_a)->next;
 	while(*stack_a != head && dc_lstsize(*stack_a) > 3)
	{
		if((*stack_a)->content > data->stack_b_max->content || (*stack_a)->content < data->stack_b_min->content)
		{
			if(b_downward_moves(data) <= b_upward_moves(data))
			{
				(*stack_a)->cost = b_downward_moves(data) + 1;
				(*stack_a)->target_direction = 0;
			}
			else
			{
				(*stack_a)->cost = b_upward_moves(data) + 1;
				(*stack_a)->target_direction = 1;
			}
			if(a_downward_moves(data) <= a_upward_moves(data))
			{
				(*stack_a)->cost += a_downward_moves(data);
				(*stack_a)->stack_a_direction = 0;
			}
			else
			{
				(*stack_a)->cost += a_upward_moves(data);
				(*stack_a)->stack_a_direction = 1;
			}
		}
		else
		{
			if(b_downward_moves(data) <= b_upward_moves(data))
			{
				(*stack_a)->cost = b_downward_moves(data) + 1;
				(*stack_a)->target_direction = 0;
			}
			else
			{
				(*stack_a)->cost = b_upward_moves(data) + 1;
				(*stack_a)->target_direction = 1;
			}
			if(a_downward_moves(data) <= a_upward_moves(data))
			{
				(*stack_a)->cost += a_downward_moves(data);
				(*stack_a)->stack_a_direction = 0;
			}
			else
			{
				(*stack_a)->cost += a_upward_moves(data);
				(*stack_a)->stack_a_direction = 1;
			}			
		}
		*stack_a = (*stack_a)->next;
	}
}

void sort(t_data *data, t_dclist **stack_a, t_dclist **stack_b)
{
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while(dc_lstsize(*stack_a) > 3)
	{
		set_min_max(data);
		set_cost(data, stack_a, stack_b);
		fill_b(stack_a, stack_b);
		if(check_early_sort(*stack_a, *stack_b))
			return ;
		// push_b(*stack_a);
		// fix_indexes(stack_a, stack_b);
		// set_targets(stack_a, stack_b);
	}
}

// int main(void)
// {
// 	t_data data;

// 	data.stack_a = lst_new_node(3);
// 	lst_prev_next(&data.stack_a, lst_new_node(2));
// 	lst_prev_next(&data.stack_a, lst_new_node(1));
// 	sort_three(&data.stack_a);
// 	print_dlist(data.stack_a);
	// lst_prev_next(&data.stack_a, lst_new_node(88));
	// lst_prev_next(&data.stack_a, lst_new_node(33));
	// lst_prev_next(&data.stack_a, lst_new_node(6));
	// lst_prev_next(&data.stack_a, lst_new_node(50));
	// lst_prev_next(&data.stack_a, lst_new_node(53));
	// lst_prev_next(&data.stack_a, lst_new_node(48));
	// lst_prev_next(&data.stack_a, lst_new_node(99));
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// set_min_max(&data);
	// ft_printf("min: %d\n", data.stack_b_min->content);
	// ft_printf("max: %d\n", data.stack_b_max->content);
	// print_dlist(data.stack_b);
	// ft_printf("upward: %d\n", b_upward_moves(data));
	// ft_printf("downward: %d\n", b_downward_moves(data));
// }