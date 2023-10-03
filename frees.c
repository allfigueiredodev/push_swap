/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:29:31 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/03 18:01:31 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dc_lstclear(t_dclist **lst)
{
	t_dclist	*ptr;
	t_dclist	*temp;

	if (!*lst)
		return ;
	ptr = (*lst);
	*lst = (*lst)->next;
	while ((*lst)->index != 0)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = temp;
	}
	free(*lst);
	ptr = NULL;
}

void	free_nbrs(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		free(nbrs[i]);
		i++;
	}
	free(nbrs);
}

void free_data(t_data *data)
{
	dc_lstclear(&data->stack_a);
	// dc_lstclear(&data->stack_b);
}