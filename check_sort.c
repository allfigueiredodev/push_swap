/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:19:04 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/08 23:20:02 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_crescent_order(t_dclist *list)
{
	int first_number;
	t_dclist *head;

	first_number = list->content;
	head = list;
	list = list->next;
	while(list != head)
	{
		if(list->content >= first_number)
		{
			first_number = list->content;
			list = list->next;				
		}
		else
			return(0);
	}
	return(1);
}

int check_decrescent_order(t_dclist *list)
{
	int first_number;
	t_dclist *head;

	first_number = list->content;
	head = list;
	list = list->next;
	while(list != head)
	{
		if(list->content <= first_number)
		{
			first_number = list->content;
			list = list->next;				
		}
		else
			return(0);
	}
	return(1);
}

int check_early_sort(t_dclist *stack_a, t_dclist *stack_b)
{
	if(check_crescent_order(stack_a) && check_decrescent_order(stack_b))
		return(1);
	return(0);
}

// int main(void)
// {
// 	t_dclist *node1;
// 	node1 = lst_new_node(39);
// 	lst_prev_next(&node1, lst_new_node(43));
// 	lst_prev_next(&node1, lst_new_node(41));
// 	t_dclist *node2;
// 	node2 = lst_new_node(70);
// 	lst_prev_next(&node2, lst_new_node(68));
// 	lst_prev_next(&node2, lst_new_node(65));
// 	lst_prev_next(&node2, lst_new_node(64));
// 	lst_prev_next(&node2, lst_new_node(58));
// 	ft_printf("true? %d\n", check_early_sort(node1, node2));
// }