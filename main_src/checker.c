/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:41:37 by mlow              #+#    #+#             */
/*   Updated: 2024/01/02 19:43:07 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ./push_swap 4 99 55 | wc -l
void	multiple_number_str_checker(t_data *data, char **argv)
{
	int	index;
	int	array;

	array = 1;
	while (argv[array])
	{
		index = 0;
		while (argv[array][index])
		{
			if (index == 0 && argv[array][index] == '-')
				index++;
			if (!ft_isdigit(argv[array][index]))
				end_exit(1);
			index++;
		}
		array++;
	}
}

//OLD VERSION BEFORE FT_SPLIT
//$ARG "4 99 55" ./push_swap $ARG | wc -l
//REedit this, we are gonna start with ft_split first.
/*
void	arg_number_str_checker(t_data data, char *argv)
{
	int	index;

	index = 0;
	while (argv[index])
	{
		if ((index == 0 && argv[index] == '-') ||
			(argv[index] == '-' && ft_isdigit(argv[index + 1]))
			index++;
		if (!ft_isdigit(argv[index]) && argv[index] != ' ')
			end_exit("$ARG contains a non-number", 1);
		index++;
	}
}
*/
//new version AFTER FT_SPLIT
void	single_arg_str_checker(t_data *data, char **argv)
{
	int	index;
	int	array;

	array = 0;
	while (argv[array])
	{
		index = 0;
		while (argv[array][index])
		{
			if (index == 0 && argv[array][index] == '-')
				index++;
			if (!ft_isdigit(argv[array][index]))
				free_end_exit(1, data);
			index++;
		}
		array++;
	}
}

//why do we need a duplicate_checker?
// In case we have numbers but we cannot have Multiple
// numbers of the same value. Thus this checker will exit
// should it find a number similar to it.
/*
notes:
num_str = data->array_c "which contains all the value of nptr in int *"
size = data->size which is bascially the size of the arguments minus ./push_swap
*/
void	duplicate_checker(t_data *data, int *array_c)
{
	int	index;
	int	current;

	index = 0;
	while (index < data->size)
	{
		current = 0;
		while (current < index)
		{
			if (array_c[current] == array_c[index])
				free_end_exit(1, data);
			current++;
		}
		index++;
	}
}

/*
Idea is to check if it is sorted, if its sorted say: "4 5 6". No issue,
Return true so that it can free_end_exit cleanly.

Should it not be sorted e.g: "4 5 3 7", "ft_is_sorted" will find '3' and
stop checking, returning "FALSE" Which allows us to use the stack function.
*/
// while (array_c[index]) <- if value is '0' got error why?
bool	is_sorted_checker(t_data *data, int *array_c, int size)
{
	int	index;
	int	current;

	index = 0;
	while (index < data->size)
	{
		current = 0;
		while (current < index)
		{
			if (array_c[current] > array_c[index])
			{
				return (false);
			}
			current++;
		}
		index++;
	}
	return (true);
}

//this function chcks if its numbers and how many in argc.
//Should it be true, store the value inside "data->temp_args";
//Once you store the value of the data->temp_args or check multiple argv, we
// then throw them inside init_array & then check_duplicate AND THEN
// FINALLY? Check if the strings are storted or not with is_sorted.
/*


AS of 3th JAN 2024, valgrind has no issue when exiting from:
1) Duplication
2) String already sorted.


*/
void	params_checker(t_data *data, int argc, char **argv)
{
	int	array;

	array = -1;
	if (argc == 2)
	{
		data->temp_args = ft_split(argv[1], ' ');
		single_arg_str_checker(data, data->temp_args);
		init_array(data, argc, data->temp_args);
	}
	else if (argc > 2)
	{
		multiple_number_str_checker(data, argv);
		array = 0;
		init_array(data, argc, argv);
	}
	duplicate_checker(data, data->array_c);
	if (is_sorted_checker(data, data->array_c, data->size))
		free_end_exit(2, data);
	data->require_sorting = true;
}
