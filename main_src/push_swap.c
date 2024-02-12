/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:54:49 by mlow              #+#    #+#             */
/*   Updated: 2023/12/29 18:55:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	variables(t_data *data)
{
	data->temp_args = NULL;
	data->size = 0;
	data->array_c = NULL;
	data->require_sorting = false;
	data->total_moves = 0;
}

/*
Purpose of init_array is to check if its single $ARG or multiple. Then 
we first figure out the size of the char **argv, using the data->size. 
  Once we get the value of the data->size, we then malloc the value of 
  data->array_c using the data->size and then using atoi(atoL), convert the
  string into numbers(INT). We use atoi but with long so that we can 
  account for INT_MAX and INT_MIN.
 We need them to be in numbers for our later stacks.
*/
void	init_array(t_data *data, int argc, char **argv)
{
	long	nptr;
	int		index;
	int		index_int;

	index = 1;
	index_int = -1;
	if (argc == 2)
	{
		index = 0;
		while (argv[data->size])
			data->size++;
	}
	else if (argc > 2)
		data->size = argc - 1;
	data->array_c = (int *)malloc(sizeof(int) * data->size);
	if (!data->array_c)
		free_end_exit(1, data);
	while (++index_int < data->size)
	{
		nptr = ft_atol(argv[index]);
		if (nptr > INT_MAX || nptr < INT_MIN)
			free_end_exit(1, data);
		data->array_c[index_int] = nptr;
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	variables(&data);
	params_checker(&data, argc, argv);
	if (!data.require_sorting)
		free_end_exit(1, &data);
	start_node(&data, argc, argv);
	return (0);
}
