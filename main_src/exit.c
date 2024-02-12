/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:19:35 by mlow              #+#    #+#             */
/*   Updated: 2024/01/02 16:20:40 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	end_exit(int exit_code)
{
	if (exit_code != 2)
		ft_printf("Error\n");
	exit(exit_code);
}

void	free_end_exit(int exit_code, t_data *data)
{
	int	array;

	array = -1;
	if (data->temp_args)
	{
		while (data->temp_args[++array])
			free(data->temp_args[array]);
		free(data->temp_args);
		data->temp_args = NULL;
	}
	if (data->array_c)
	{
		free(data->array_c);
		data->array_c = NULL;
	}
	end_exit(exit_code);
}

void	free_node_exit(int exit_code, t_stack *stack)
{
	int	array;
	int	size;

	array = -1;
	if (stack && exit_code == 2)
		ftbs_free_stack(stack);
}

void	free_both_exit(int exit_code, t_stack *a, t_stack *b, t_data *data)
{
	if (a)
		free_node_exit(2, a);
	if (b)
		free_node_exit(2, b);
	free_end_exit(exit_code, data);
}
