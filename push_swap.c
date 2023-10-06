/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:03:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/05 21:04:17 by aperis-p         ###   ########.fr       */
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
	print_dlist(data.stack_a);
	// sa(&data.stack_a);
	push_b(&data.stack_a, &data.stack_b);
	print_dlist(data.stack_a);
	print_dlist(data.stack_b);
	free_data(&data);
}