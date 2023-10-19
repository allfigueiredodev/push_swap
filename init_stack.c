/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis-p <aperis-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:57:12 by aperis-p          #+#    #+#             */
/*   Updated: 2023/10/17 18:38:13 by aperis-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_data *data)
{
	data->stack_a = (t_dclist *)ft_calloc(1, sizeof(t_dclist));
	data->stack_b = (t_dclist *)ft_calloc(1, sizeof(t_dclist));
	data->total_nbrs = 0;
	if (!data->stack_a || !data->stack_b)
	{
		if (!data->stack_a)
		{
			if (data->stack_a)
				free(data->stack_a);
			if (data->stack_b)
				free(data->stack_b);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}		
	}
}

int	validate_digits(char **nbrs, long nbr, char *c)
{
	long	atoied;

	atoied = nbr;
	if (atoied < INT_MIN || atoied > INT_MAX || !check_for_digit(c))
	{
		free_nbrs(nbrs);
		return (0);
	}
	return (1);
}

int	init_data_from_arguments(int argc, char **argv, t_data *data)
{
	int		total_arguments;
	int		i;
	long	nbr;

	total_arguments = argc - 1;
	i = 1;
	while (i <= total_arguments)
	{
		nbr = ft_atol(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || !check_for_digit(argv[i]))
			return (0);
		if (dc_lstsize(data->stack_a) == 0)
		{
			free(data->stack_a);
			data->stack_a = lst_new_node(nbr);
		}
		else if (data->stack_a)
			lst_prev_next(&(data->stack_a), lst_new_node(nbr));
		i++;
	}
	return (1);
}

int	init_data_from_string(char *nbr_list, t_data *data)
{
	int		i;
	char	**nbrs;
	long	atoied;

	if (!ft_strlen(nbr_list))
		return (0);
	nbrs = ft_split(nbr_list, ' ');
	i = 0;
	while (nbrs[i])
	{
		atoied = ft_atol(nbrs[i]);
		if (!validate_digits(nbrs, atoied, nbrs[i]))
			return (0);
		if (dc_lstsize(data->stack_a) == 0)
		{
			free(data->stack_a);
			data->stack_a = lst_new_node(atoied);
		}
		else
			lst_prev_next(&data->stack_a, lst_new_node(atoied));
		i++;
	}
	free_nbrs(nbrs);
	return (1);
}

int	init_data(int argc, char **argv, t_data *data)
{
	if (argc == 2)
	{
		if (!init_data_from_string(argv[1], data))
			return (0);
	}
	else if (argc > 2)
	{
		if (!init_data_from_arguments(argc, argv, data))
			return (0);
	}
	return (1);
}
