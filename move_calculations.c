/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:52:55 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 18:53:51 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_downward_moves(t_data *data, int is_new_edge)
{
	int	total;

	if (is_new_edge)
		total = dc_lstsize(data->stack_b) - data->stack_b_max->index;
	else
		total = dc_lstsize(data->stack_b) - data->stack_a->target->index;
	return (total);
}

int	b_upward_moves(t_data *data, int is_new_edge)
{
	int	total;

	if (is_new_edge)
		total = data->stack_b_max->index;
	else
		total = data->stack_a->target->index;
	return (total);
}

int	a_downward_moves(t_data *data)
{
	int	total;

	total = dc_lstsize(data->stack_a) - data->stack_a->index;
	return (total);
}

int	a_upward_moves(t_data *data)
{
	int	total;

	total = data->stack_a->index;
	return (total);
}
