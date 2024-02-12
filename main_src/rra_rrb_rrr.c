/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:39:23 by mlow              #+#    #+#             */
/*   Updated: 2024/01/10 11:42:32 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//(reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one.
void	rra_rrb(t_stack *stack, t_data *data, int print)
{
	t_node	*new_top_stack;
	t_node	*temp_top;
	t_node	*temp_bottom;
	t_node	*node;
	int		counter;

	if (!(stack) || (!(stack)->top) || (!(stack)->size))
		return ;
	if (print != 3)
	{
		if (stack->name == 'a')
			ft_printf("rra\n");
		else if (stack->name == 'b')
			ft_printf("rrb\n");
	}
	stack->top = stack->bottom;
	stack->bottom = stack->bottom->prev;
	update_pos(stack, NULL, data);
	if (print != 3)
		data->total_moves += 1;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	ft_printf("rrr\n");
	rra_rrb(stack_a, data, 3);
	rra_rrb(stack_b, data, 3);
	data->total_moves += 1;
}
