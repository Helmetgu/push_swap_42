/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:25:19 by mlow              #+#    #+#             */
/*   Updated: 2024/01/27 11:30:12 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//issue is here?part1 -For YunXuan-
t_node	*find_lowest_cost(t_stack *stack, t_data *data)
{
	t_node	*current;
	t_node	*lowest;
	int		index;
	int		size;

	if (stack->size <= 1)
		return (stack->top);
	size = stack->size + 1;
	lowest = stack->top;
	current = stack->top;
	while (--size)
	{
		if (current->move_cost < lowest->move_cost
			&& current->content < stack->biggest3)
			lowest = current;
		current = current->next;
	}
	while (lowest->content >= stack->biggest3)
		lowest = lowest->next;
	return (lowest);
}
