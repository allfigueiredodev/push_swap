/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:03:02 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/27 19:27:04 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if(argc < 2)
		return (0);
	init_stack(&data);
	init_data(argv[1], &data);
	if(!dup_check(data))
	{
		printf("duplicated\n");
		free_data(&data);
		return(0);
	}
	free_data(&data);
}