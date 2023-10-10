/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:51:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/09 21:40:11 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void swap_single(t_dclist **list, int flag)
{
    t_dclist *temp;

    if(dc_lstsize(*list) <= 1)
        return ;
    temp = (*list)->next;
    (*list)->next = temp->next;
    temp->next->prev = *list;
    temp->next = *list;
    temp->prev = (*list)->prev;
    (*list)->prev->next = temp;
    (*list)->prev = temp;
    *list = temp;
	fix_index(list);
	if(flag == 0)
		return ;
	else if(flag == 1)
		ft_printf("sa\n");
	else if(flag == 2)
		ft_printf("sb\n");
}

// ss : sa and sb at the same time.

void swap_both(t_dclist **list_a, t_dclist **list_b)
{
	swap_single(list_a, 0);
	swap_single(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("ss\n");
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

void push_a(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist *temp;
	int size;

	if(!(*list_b))
		return ;
	size = dc_lstsize((*list_b));
	temp = *list_b;
	*list_b = (*list_b)->next;
	(*list_b)->prev = temp->prev;
	temp->prev->next = *list_b;
	temp->next = temp;
	temp->prev = temp;
	if(!dc_lstsize((*list_a)))
	{
		free((*list_a));
		*list_a = temp;
	}
	else if(size == 1)
	{
		lst_add_head(list_a, temp);
		*list_b = NULL;
	}
	else
		lst_add_head(list_a, temp);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("pa\n");
}

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

void push_b(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist *temp;
	int size;

	if(!(*list_a))
		return ;
	size = dc_lstsize((*list_a));
	temp = *list_a;
	*list_a = (*list_a)->next;
	(*list_a)->prev = temp->prev;
	temp->prev->next = *list_a;
	temp->next = temp;
	temp->prev = temp;
	if(!dc_lstsize((*list_b)))
	{
		free((*list_b));
		*list_b = temp;
	}
	else if(size == 1)
	{
		lst_add_head(list_b, temp);
		*list_a = NULL;
	}
	else
		lst_add_head(list_b, temp);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("pb\n");
}

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

void shift_up_single(t_dclist **list, int flag)
{
	t_dclist *temp;

	temp = (*list)->next;
	*list = temp;
	fix_index(list);
	if(flag == 0)
		return ;
	else if(flag == 1)
		ft_printf("ra\n");
	else if(flag == 2)
		ft_printf("rb\n");
}

void shift_up_both(t_dclist **list_a, t_dclist **list_b)
{
	shift_up_single(list_a, 0);
	shift_up_single(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("rr\n");
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.

void shift_down_single(t_dclist **list, int flag)
{
	t_dclist *temp;
	
	temp = (*list)->prev;
	*list = temp;
	fix_index(list);
	if(flag == 0)
		return ;
	else if(flag == 1)
		ft_printf("rra\n");
	else if(flag == 2)
		ft_printf("rrb\n");
}

void shift_down_both(t_dclist **list_a, t_dclist **list_b)
{
	shift_down_single(list_a, 0);
	shift_down_single(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("rrr\n");
}