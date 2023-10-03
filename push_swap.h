/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/03 18:31:01 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "./libft/libft.h"

typedef struct s_data
{
	int total_nbrs;
	struct s_dclist *stack_a;
	struct s_dclist *stack_b;
}	t_data;

typedef struct s_dclist
{
	int index;
	int content;
	struct s_dclist *next;
	struct s_dclist *prev;
	
}	t_dclist;

int 		init_data_from_string(char *nbr_list, t_data *data);
int 		init_data_from_arguments(int argc, char **argv, t_data *data);
void 		print_list(t_list *stack);
void 		init_stack(t_data *data);
int			dup_check(t_data data);
int 		scan_list(t_dclist *head, int content);
void 		free_data(t_data *data);
void		free_nbrs(char **nbrs);
void 		count_list_size(t_data *data);
int			check_for_digit(char *c);
int 		init_data(int argc, char **argv, t_data *data);
void		print_dlist(t_dclist *stack);
int			dc_lstsize(t_dclist *lst);
t_dclist	*dc_lst_last(t_dclist *lst);
void		lst_prev_next(t_dclist **alst, t_dclist *new);
t_dclist	*lst_new_node(int content);
void		dc_lstclear(t_dclist **lst);
void		sa(t_data *data);

#endif