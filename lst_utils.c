/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:33:49 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/11 18:40:08 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_dlist(t_dclist *stack)
{
	t_dclist *head;

	if(!stack)
		return ;
	head = stack;
	stack = stack->next;
	if(stack == head)
	{
		ft_printf("%d, \n", head->content);
		return ;
	}
	ft_printf("%d, \n", head->content);
	while(stack->next != head)
	{
		ft_printf("%d, \n", stack->content);
		stack = stack->next;
	}
	ft_printf("%d, \n", stack->content);
}

void print_dlist_index(t_dclist *stack)
{
	t_dclist *head;

	if(!stack)
		return ;
	head = stack;
	stack = stack->next;
	if(stack == head)
	{
		ft_printf("%d, \n", head->index);
		return ;
	}
	ft_printf("%d, ", head->index);
	while(stack->next != head)
	{
		ft_printf("%d, ", stack->index);
		stack = stack->next;
	}
	ft_printf("%d, \n", stack->index);
}

int	dc_lstsize(t_dclist *lst)
{
	int	total;
	t_dclist *head;
	
	total = 0;
	if(!lst)
		return(total);
	head = lst;
	lst = lst->next;
	if(lst == head)
		return (1);
	else if(!lst || !lst->next)
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
	t_dclist *head;
	
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
		if (!(*alst)->content)
			*alst = new;
		else if(head->next == head)
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
	t_dclist *last;
	t_dclist *head;

	if(!(new))
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

// int main(void)
// {
// 	t_dclist *node1;
// 	// t_dclist node2;
// 	// t_dclist node3;
// 	// node1 = (t_dclist *)ft_calloc(1, sizeof(t_dclist));
// 	// if(!node1)
// 	// 	return(0);
// 	// node1.index = 0;
// 	// node2.index = 1;
// 	// node3.index = 2;
// 	// node1.next = &node2;
// 	// node1.prev = &node3;
// 	// node2.next = &node3;
// 	// node2.prev = &node1;
// 	// node3.next = &node1;
// 	// node3.prev = &node2;	
// 	// print_dlist(&node1);
// 	// ft_printf("%d\n", dc_lstsize(&node1));
// 	// dc_lst_last(&node1);
// 	node1 = lst_new_node(42);
// 	// lst_prev_next(&node1, lst_new_node(42));
// 	lst_prev_next(&node1, lst_new_node(43));
// 	lst_prev_next(&node1, lst_new_node(44));
// 	lst_prev_next(&node1, lst_new_node(45));
// 	lst_prev_next(&node1, lst_new_node(46));
// 	lst_prev_next(&node1, lst_new_node(47));
// 	lst_prev_next(&node1, lst_new_node(48));
// 	lst_prev_next(&node1, lst_new_node(49));
// 	lst_prev_next(&node1, lst_new_node(50));
// 	// node1 = lst_new_node(43);
// 	// node1 = lst_new_node(44);
// 	print_dlist(node1);
// 	// ft_printf("content: %d\n", node1->content);
	
// 	// ft_printf("content: %d\n", node1->next->content);
// 	// ft_printf("content: %d\n", node1->prev->content);
// 	// lst_prev_next(&node1, lst_new_node(42));
// 	// lst_prev_next(&node1, lst_new_node(43));
// 	// lst_prev_next(&node1, lst_new_node(44));
// 	// lst_prev_next(&node1, lst_new_node(45));
// 	// lst_prev_next(&node1, lst_new_node(46));	
// }