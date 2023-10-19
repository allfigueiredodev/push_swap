/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:25:48 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:28:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_indexes(t_dclist **stack_a, t_dclist **stack_b)
{
	fix_index(stack_a);
	fix_index(stack_b);
}

void	fix_index(t_dclist **list)
{
	t_dclist	*head;

	if (!(*list))
		return ;
	head = *list;
	(*list)->index = 0;
	*list = (*list)->next;
	while (*list != head)
	{
		(*list)->index = (*list)->prev->index + 1;
		*list = (*list)->next;
	}
}
