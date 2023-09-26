/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/26 14:50:11 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct s_data
{
	int total_nbrs;
	struct s_list *stack_a;
	struct s_list *stack_b;
}	t_data;

typedef struct s_doublylist
{
	int index;
	struct s_doublylist *next;
	struct s_doublylist *prev;
	
}	t_doublylist;

void 	init_data(char *nbr_list, t_list *stack);
void 	print_list(t_list *stack);
void 	init_stack(t_data *data);
int		dup_check(t_list *stack);
#endif