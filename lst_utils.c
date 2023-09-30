/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:33:49 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/29 22:00:17 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_dlist(t_dclist *stack)
{
	t_dclist *temp;
	temp = stack;
	stack = stack->next;
	ft_printf("%d ", temp->content);
	while(stack->next != temp)
	{
		ft_printf("%d ", stack->content);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	dc_lstsize(t_dclist *lst)
{
	int	total;
	t_dclist *temp;
	
	total = 0;
	temp = lst;
	lst = lst->next;
	if(lst == temp)
		return (0);
	while (lst != temp)
	{
		total++;
		lst = lst->next;
	}
	return (total);
}

t_dclist	*dc_lst_last(t_dclist *lst)
{
	t_dclist *temp;
	
	if (!lst)
		return (NULL);
	if (dc_lstsize(lst) == 1)
		return (lst);
	temp = lst;
	lst = lst->next;
	while (lst != temp)
		lst = lst->next;
	return (lst);
}

void	lst_prev_next(t_dclist **alst, t_dclist *new)
{
	t_dclist	*last;
	t_dclist	*head;

	head = *(alst);
	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			last = ft_lstlast(*(alst));
			new = last;
			last->next = head;
		}
	}
	print_list(*alst);
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
	return (&*node);
}

int main(void)
{
	int nbr = 5;

	print_dlist(lst_new_node(nbr));
}