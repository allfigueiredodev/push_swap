/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:34:50 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/26 22:48:58 by aperis-p         ###   ########.fr       */
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

int dup_check(t_data *data)
{
	t_list *head;
	t_list *temp;
		
	head = (t_list *)ft_calloc(1, sizeof(t_list));
	while(data->stack_a)
	{
		if(!head->content)
		{
			head = ft_lstnew(data->stack_a->content);
			temp = head;
			data->stack_a = data->stack_a->next;
		}
		else
		{
			ft_lstadd_back(&head, ft_lstnew(data->stack_a->content));
			data->stack_a = data->stack_a->next;
		}
		if(data->stack_a && !scan_list(head, data->stack_a->content))
		{
			ft_lstclear(&temp, delete_content);
			free(temp);
			return(0);
		}
	}
	ft_lstclear(&temp, delete_content);
	free(temp);
	return(1);
}