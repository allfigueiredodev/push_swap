/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:03:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/14 00:35:59 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if(argc < 2)
		return (0);
	init_stack(&data);
	if(!init_data(argc, argv, &data) || !dup_check(data))
	{
		ft_putstr_fd("Error\n", 2);
		free_data(&data);
		return(0);
	}
	if(check_crescent_order(data.stack_a))
	{
		free_data(&data);
		return(0);
	}
	else
	{
		if(sort(&data, &data.stack_a, &data.stack_b))
		{
			free_data(&data);
			return(0);
		}
	}
	// sort_three(&data.stack_a);
	sort_decrescent(data, &data.stack_b);
	set_targets_to_push_back(data, &data.stack_a, &data.stack_b);
	mergin_back(data, &data.stack_a, &data.stack_b);
	ft_printf("\nstack_a\n");
	print_dlist(data.stack_a);
	ft_printf("\nstack_b\n");
	print_dlist(data.stack_b);
}