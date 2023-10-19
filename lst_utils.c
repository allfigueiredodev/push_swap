/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:33:49 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 17:50:45 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dc_lstsize(t_dclist *lst)
{
	int			total;
	t_dclist	*head;

	total = 0;
	if (!lst)
		return (total);
	head = lst;
	lst = lst->next;
	if (lst == head)
		return (1);
	else if (!lst || !lst->next)
		return (total);
	while (lst != head)
	{
		total++;
		lst = lst->next;
	}
	total++;
	lst = head;
	return (total);
}

t_dclist	*dc_lst_last(t_dclist *lst)
{
	t_dclist	*head;

	if (!lst)
		return (NULL);
	if (dc_lstsize(lst) == 1)
		return (lst);
	head = lst;
	lst = lst->next;
	while (lst->next != head)
		lst = lst->next;
	return (lst);
}

void	lst_prev_next(t_dclist **alst, t_dclist *new)
{
	t_dclist	*head;

	head = *(alst);
	if (alst)
	{
		if (dc_lstsize(*alst) == 0)
			*alst = new;
		else if (head->next == head)
		{
			new->prev = dc_lst_last(*(alst));
			new->next = head;
			head->next = new;
			head->prev = new;
			new->index = new->prev->index + 1;
		}
		else
		{
			new->prev = dc_lst_last(*(alst));
			new->prev->next = new;
			new->next = head;
			head->prev = new;
			new->index = new->prev->index + 1;
		}
	}
}

void	lst_add_head(t_dclist **alst, t_dclist *new)
{
	t_dclist	*last;
	t_dclist	*head;

	if (!(new))
		return ;
	last = (*alst)->prev;
	head = *alst;
	*alst = new;
	(*alst)->prev = last;
	(*alst)->next = head;
	last->next = *alst;
	head->prev = *alst;
}

t_dclist	*lst_new_node(int content)
{
	t_dclist	*node;

	node = (t_dclist *)malloc(sizeof(t_dclist));
	if (!node)
		return (NULL);
	node->content = content;
	node->prev = node;
	node->next = node;
	node->index = 0;
	node->target = NULL;
	return (&*node);
}
