/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/28 21:35:09 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int scan_list(t_list *head, void *content)
{
	while(head)
	{
		if(head->content != NULL)
			if(*(int *)head->content == *(int *)content)
				return 0;
		head = head->next;
	}
	return(1);
}

int dup_check(t_data data)
{
	t_list *head;	
	
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