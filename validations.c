/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/26 14:19:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int scan_list(t_list *stack, void *content)
{
	while(stack)
	{
		if(*(int *)stack->content == *(int *)content)
			return 0;
		stack = stack->next;
	}
	return(1);
}

int dup_check(t_list *stack)
{
	t_list *head;
	t_list *temp;
		
	temp = head;
	while(stack)
	{
		if(!scan_list(head, stack->content))
			return(0);
		if(!head)
		{
			head = ft_lstnew(stack->content);
		}
		else
		{
			ft_lstadd_back(&*head, ft_lstnew(stack->content));
		}
		stack = stack->next;
	}	
	return(1);
}