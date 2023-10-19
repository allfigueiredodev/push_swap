/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:51:25 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 18:57:10 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_dclist **list, int flag)
{
	t_dclist	*temp;

	temp = (*list)->next;
	*list = temp;
	fix_index(list);
	if (flag == 0)
		return ;
	else if (flag == 1)
		ft_printf("ra\n");
	else if (flag == 2)
		ft_printf("rb\n");
}

void	rr(t_dclist **list_a, t_dclist **list_b)
{
	rx(list_a, 0);
	rx(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("rr\n");
}

void	rrx(t_dclist **list, int flag)
{
	t_dclist	*temp;

	temp = (*list)->prev;
	*list = temp;
	fix_index(list);
	if (flag == 0)
		return ;
	else if (flag == 1)
		ft_printf("rra\n");
	else if (flag == 2)
		ft_printf("rrb\n");
}

void	rrr(t_dclist **list_a, t_dclist **list_b)
{
	rrx(list_a, 0);
	rrx(list_b, 0);
	fix_index(list_a);
	fix_index(list_b);
	ft_printf("rrr\n");
}
