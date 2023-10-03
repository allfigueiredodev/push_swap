/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/03 18:49:19 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int scan_list(t_dclist *head, int content)
{
	while(head)
	{
		if(head->content)
			if(head->content == content)
				return 0;
		head = head->next;
	}
	return(1);
}

int dup_check(t_data data)
{
	t_dclist *head;	
	
	while(data.stack_a)
	{
		head = data.stack_a->next;
		while (head)
		{
			if(data.stack_a && !scan_list(head, data.stack_a->content))
				return(0);
			head = head->next;
		}
		data.stack_a = data.stack_a->next;
	}
	return(1);
}