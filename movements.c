/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:51:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/05 21:51:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

void swap_single(t_dclist **list)
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
}

// ss : sa and sb at the same time.

void swap_both(t_dclist **list_a, t_dclist **list_b)
{
	swap_single(list_a);
	swap_single(list_b);
}

void push_b(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist *temp;

	if(!(*list_a))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	(*list_a)->prev = temp->prev;
	temp->prev->next = *list_a;
	temp->next = temp;
	temp->prev = temp;
	if(!dc_lstsize((*list_b)))
		*list_b = temp;
		// lst_prev_next(list_b, temp);
}

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

void shift_up_single(t_dclist **list)
{
	t_dclist *temp;

	temp = (*list)->next;
	*list = temp;
}

void shift_up_both(t_dclist **list_a, t_dclist **list_b)
{
	shift_up_single(list_a);
	shift_up_single(list_b);
}

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.

void shift_down_single(t_dclist **list)
{
	t_dclist *temp;
	
	temp = (*list)->prev;
	*list = temp;
}

void shift_down_both(t_dclist **list_a, t_dclist **list_b)
{
	shift_down_single(list_a);
	shift_down_single(list_b);
}