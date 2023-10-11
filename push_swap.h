/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:09:30 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/11 11:14:58 by aperis-p         ###   ########.fr       */
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
	struct s_dclist *stack_b_min;
	struct s_dclist *stack_b_max;
}	t_data;

typedef struct s_dclist
{
	int index;
	int content;
	int cost;
	int stack_a_direction;
	int target_direction;
	struct s_dclist *target;
	struct s_dclist *next;
	struct s_dclist *prev;	
}	t_dclist;

int 		init_data_from_string(char *nbr_list, t_data *data);
int 		init_data_from_arguments(int argc, char **argv, t_data *data);
void 		print_list(t_list *stack);
void 		init_stack(t_data *data);
int			dup_check(t_data data);
int 		scan_list(t_dclist *head, t_dclist *current);
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
void		swap(t_dclist **list);
void		shift_up_single(t_dclist **list, int flag);
void		shift_up_both(t_dclist **list_a, t_dclist **list_b);
void		shift_down_single(t_dclist **list, int flag);
void		shift_down_both(t_dclist **list_a, t_dclist **list_b);
void		push_b(t_dclist **list_a, t_dclist **list_b);
void		push_a(t_dclist **list_b, t_dclist **list_a);
void		lst_add_head(t_dclist **alst, t_dclist *new);
void		fix_index(t_dclist **list);
void		print_dlist_index(t_dclist *stack);
void		swap_single(t_dclist **list, int flag);
void		swap_both(t_dclist **list_a, t_dclist **list_b);
int			check_for_middle(t_dclist *list);
void		set_min_max(t_data *data);
void		set_targets(t_dclist **stack_a, t_dclist **stack_b);
int			check_crescent_order(t_dclist *list);
int			check_decrescent_order(t_dclist *list);
int			sort(t_data *data, t_dclist **stack_a, t_dclist **stack_b);
int			b_downward_moves(t_data data);
int			b_upward_moves(t_data data);
int			set_cost(t_data data,  t_dclist **stack_a, t_dclist **stack_b);
void		fix_indexes(t_dclist **stack_a, t_dclist **stack_b);
void		sort_three(t_dclist **stack_a);
int			check_early_sort(t_dclist *stack_a, t_dclist *stack_b);

#endif