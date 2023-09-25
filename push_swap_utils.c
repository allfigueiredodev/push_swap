/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:50:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/25 19:57:55 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void print_list(t_list **stack)
{
	t_list **temp;
	temp = stack;
	while(*stack)
	{
		ft_printf("%d\n", *(int *)(*stack)->content);
		*stack = (*stack)->next;
	}
}
