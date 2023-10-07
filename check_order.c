/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:11 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/06 21:26:54 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_order(t_dclist *list)
{
	int first_number;
	t_dclist *head;

	first_number = list->content;
	head = list;
	list = list->next;
	while(list != head)
	{
		if(list->content >= first_number)
			list = list->next;				
		else
			return(0);
	}
	return(1);
}
// int main(void)
// {
// 	t_dclist *node1;
// 	node1 = lst_new_node(455);
// 	lst_prev_next(&node1, lst_new_node(42));
// 	lst_prev_next(&node1, lst_new_node(44));
// 	lst_prev_next(&node1, lst_new_node(45));
// 	lst_prev_next(&node1, lst_new_node(46));
// 	lst_prev_next(&node1, lst_new_node(48));
// 	check_order(node1);	
// }