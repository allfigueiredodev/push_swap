/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:55:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 19:26:10 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sx(t_dclist **list, int flag)
{
	t_dclist	*temp;

	if (dc_lstsize(*list) <= 1)
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
	if (flag == 0)
		return ;
	else if (flag == 1)
		ft_printf("sa\n");
	else if (flag == 2)
		ft_printf("sb\n");
}

void	ss(t_dclist **list_a, t_dclist **list_b)
{
	sx(list_a, 0);
	sx(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("ss\n");
}

void	push_a(t_dclist **list_b, t_dclist **list_a)
{
	t_dclist	*temp;
	int			size;

	if (!(*list_b))
		return ;
	size = dc_lstsize((*list_b));
	temp = *list_b;
	*list_b = (*list_b)->next;
	(*list_b)->prev = temp->prev;
	temp->prev->next = *list_b;
	temp->next = temp;
	temp->prev = temp;
	if (!dc_lstsize((*list_a)))
	{
		free((*list_a));
		*list_a = temp;
	}
	else if (size == 1)
	{
		lst_add_head(list_a, temp);
		*list_b = NULL;
	}
	else
		lst_add_head(list_a, temp);
	ft_printf("pa\n");
}

void	push_b(t_dclist **list_a, t_dclist **list_b)
{
	t_dclist	*temp;
	int			size;

	if (!(*list_a))
		return ;
	size = dc_lstsize((*list_a));
	temp = *list_a;
	*list_a = (*list_a)->next;
	(*list_a)->prev = temp->prev;
	temp->prev->next = *list_a;
	temp->next = temp;
	temp->prev = temp;
	if (!dc_lstsize((*list_b)))
	{
		free((*list_b));
		*list_b = temp;
	}
	else if (size == 1)
	{
		lst_add_head(list_b, temp);
		*list_a = NULL;
	}
	else
		lst_add_head(list_b, temp);
	ft_printf("pb\n");
}
