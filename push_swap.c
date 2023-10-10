/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:03:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/09 19:56:57 by aperis-p         ###   ########.fr       */
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
	if(!check_crescent_order(data.stack_a))
		sort(&data, &data.stack_a, &data.stack_b);
	ft_printf("min: %d max: %d\n", data.stack_b_min->content, data.stack_b_max->content);
	free_data(&data);
	
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist(data.stack_b);
	// set_targets(&data.stack_a, &data.stack_b);
	// ft_printf("%d\n", data.stack_a->target->content);
	// ft_printf("%d\n", data.stack_a->next->target->content);
	// ft_printf("%d\n", data.stack_a->next->next->target->content);	
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// push_b(&data.stack_a, &data.stack_b);
	// print_dlist(data.stack_b);
	// set_min_max(&data);
	// ft_printf("min: %d\n", data.stack_b_min);
	// ft_printf("max: %d\n", data.stack_b_max);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// ft_printf("*****************\n");
	// push_b(&data.stack_a, &data.stack_b);
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// push_b(&data.stack_a, &data.stack_b);
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// push_b(&data.stack_a, &data.stack_b);
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// push_b(&data.stack_a, &data.stack_b);
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// swap_both(&data.stack_a, &data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// ft_printf("SWAP\n");
	// swap_both(&data.stack_a, &data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
	// ft_printf("SWAP\n");
	// swap_both(&data.stack_a, &data.stack_b);
	// ft_printf("*****************\n");
	// fix_index(&data.stack_a);
	// fix_index(&data.stack_b);
	// print_dlist(data.stack_a);
	// print_dlist_index(data.stack_a);
	// print_dlist(data.stack_b);
	// print_dlist_index(data.stack_b);
	// ft_printf("*****************\n");
}