/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:28:58 by mlow              #+#    #+#             */
/*   Updated: 2024/01/31 18:33:33 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//this ft handles the rotation and that node's moving_cost
void	*algo_stacka_top(t_stack *a, t_stack *b, t_data *data, t_node *node_t)
{
	while (a->top != node_t)
	{
		if (node_t->cost > 0 && node_t->target->cost > 0)
		{
			rr(a, b, data);
			node_t->target->cost -= 1;
		}
		else if (node_t->cost_rr > 0 && node_t->target->cost_rr > 0)
		{
			rrr(a, b, data);
			node_t->target->cost_rr -= 1;
		}
		else if (node_t->cost > 0)
		{
			ra_rb(a, data, 1);
			node_t->cost -= 1;
		}
		else if (node_t->cost_rr > 0)
		{
			rra_rrb(a, data, 1);
			node_t->cost_rr -= 1;
		}
	}
}

//Handles the roation for target(stack_b) of stack_a to be top->stack 
void	algo_rotation(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node	*node_target;

	node_target = find_lowest_cost(stack_a, data);
	algo_stacka_top(stack_a, stack_b, data, node_target);
	while (stack_b->top != node_target->target)
	{
		if (node_target->target->cost > 0)
			ra_rb(stack_b, data, 1);
		else if (node_target->target->cost_rr > 0)
			rra_rrb(stack_b, data, 1);
	}
}
