/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:29:01 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_list(t_dclist *current_checked, t_dclist *next_from_current)
{
	while (next_from_current != current_checked)
	{
		if (current_checked->content == next_from_current->content)
			return (0);
		next_from_current = next_from_current->next;
	}
	return (1);
}

int	dup_check(t_data data)
{
	t_dclist	*head;
	t_dclist	*next_from_current;
	t_dclist	*current_checked;

	head = data.stack_a;
	current_checked = data.stack_a;
	next_from_current = data.stack_a->next;
	while (next_from_current != head)
	{
		if (!scan_list(current_checked, next_from_current))
			return (0);
		next_from_current = next_from_current->next;
		current_checked = current_checked->next;
	}
	return (1);
}
