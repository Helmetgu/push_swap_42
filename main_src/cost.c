/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:30:21 by mlow              #+#    #+#             */
/*   Updated: 2024/01/27 11:30:24 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	r_cost(t_stack *stack, t_data *data)
{
	int		median;
	int		position_till_one;
	int		size;
	t_node	*current;

	if (!(stack) || !(stack)->size || !(stack)->top)
		return ;
	current = stack->top;
	size = stack->size + 1;
	median = find_median(stack, data);
	while (--size)
	{
		current->cost = 0;
		current->cost_rr = 0;
		if (current->position != 1)
		{
			if (current->position <= (median))
				current->cost = current->position - 1;
			else if (current->position > (median))
				current->cost_rr = stack->size - (current->position - 1);
		}
		current->tcost = current->cost + current->cost_rr;
		current = current->next;
	}
}

void	total_cost(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int		size;
	t_node	*current;

	size = (stack_a->size) + 1;
	r_cost(stack_a, data);
	r_cost(stack_b, data);
	current = stack_a->top;
	while (--size)
	{
		current->move_cost = -1;
		current->target = dest_value(current, stack_b, data);
		current = current->next;
	}
	algo_rotation(stack_a, stack_b, data);
	pp(stack_a, stack_b, data);
}
