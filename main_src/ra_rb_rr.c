/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:33:53 by mlow              #+#    #+#             */
/*   Updated: 2024/01/10 11:48:03 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//(rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.

void	ra_rb(t_stack *stack, t_data *data, int print)
{
	t_node	*new_top_stack;
	t_node	*node;
	int		counter;

	if (!(stack) || (!(stack)->top) || (!(stack)->size))
		return ;
	if (print != 3)
	{
		if (stack->name == 'a')
			ft_printf("ra\n");
		else if (stack->name == 'b')
			ft_printf("rb\n");
	}
	stack->top = stack->top->next;
	stack->bottom = stack->bottom->next;
	stack->top->prev = stack->bottom;
	stack->bottom->next = stack->top;
	update_pos(stack, NULL, data);
	if (print != 3)
		data->total_moves += 1;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	ft_printf("rr\n");
	ra_rb(stack_a, data, 3);
	ra_rb(stack_b, data, 3);
	data->total_moves += 1;
}
