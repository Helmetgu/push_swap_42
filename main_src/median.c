/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:39:07 by mlow              #+#    #+#             */
/*   Updated: 2024/01/28 12:39:40 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_median(t_stack *stack, t_data *data)
{
	int		size;
	int		median;
	t_node	*current;

	current = stack->top;
	median = 0;
	size = stack->size;
	if (size % 2 == 0)
		median = size / 2;
	else
		median = (size + 1) / 2;
	return (median);
}
