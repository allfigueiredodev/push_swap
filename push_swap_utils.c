/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:50:56 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/13 22:55:54 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_digit(char *c)
{
	if(*c == '+' || *c == '-')
	{
		c++;
		if(*c < '0' || *c > '9')
			return (0); 
	}
	else if(*c && *c >= '0' && *c <= '9')
	{
		while(*c)
		{
			if(*c < '0' || *c > '9')
				return (0);
			c++;
		}		
	}
	else
		return(0);
	return (1);
}

void count_list_size(t_data *data)
{
	int total;
	t_dclist *temp;

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
