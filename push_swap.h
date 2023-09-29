/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/09/28 21:06:30 by aperis-p         ###   ########.fr       */
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

void 	init_data_from_string(char *nbr_list, t_data *data);
void 	init_data_from_arguments(int argc, char **argv, t_data *data);
void 	print_list(t_list *stack);
void 	init_stack(t_data *data);
int		dup_check(t_data data);
int 	scan_list(t_list *head, void *content);
void 	free_data(t_data *data);
void 	delete_content(void *content);
void	free_nbrs(char **nbrs);
void 	count_list_size(t_data *data);
int		check_for_digit(char *c);
void 	init_data(int argc, char **argv, t_data *data);

#endif