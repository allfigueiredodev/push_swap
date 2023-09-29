/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:50:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/28 20:42:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_digit(char *c)
{
	while(*c == '+' || *c == '-')
		c++;
	if (*c >= '0' && *c <= '9')
		return (1);
	return (0);
}

void count_list_size(t_data *data)
{
	int total;
	t_list *temp;

	total = 0;
	temp = data->stack_a;
	while(temp)
	{
		total++;
		temp = temp->next;
	}
	data->total_nbrs = total;
}

void print_list(t_list *stack)
{
	t_list *temp;
	temp = stack;
	while(temp)
	{
		ft_printf("%d ", *(int *)temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}
