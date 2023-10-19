/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:59:15 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 18:00:30 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	downward_moves(t_data *data, t_dclist *node)
{
	int	total;

	total = dc_lstsize(data->stack_a) - node->index;
	return (total);
}

int	upward_moves(t_dclist *node)
{
	int	total;

	total = node->index;
	return (total);
}
