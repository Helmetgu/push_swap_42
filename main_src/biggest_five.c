/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:48:07 by mlow              #+#    #+#             */
/*   Updated: 2024/02/06 18:48:33 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	biggest_five(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	biggest_value(stack_a, data);
	biggest_second(stack_a, data);
	biggest_third(stack_a, data);
	while (stack_b->size < 3)
	{
		while (stack_a->top->content >= stack_a->biggest3)
		{
			ra_rb(stack_a, data, 1);
		}
		pp(stack_a, stack_b, data);
	}
	sort_bthree(stack_b, data, 1);
	while (stack_a->size > 3)
	{
		update_pos(stack_a, NULL, data);
		update_pos(NULL, stack_b, data);
		total_cost(stack_a, stack_b, data);
	}
}

void	*biggest_second(t_stack *stack, t_data *data)
{
	int		size;
	long	diff;
	long	current_num;
	t_node	*temp;

	temp = stack->top;
	size = stack->size + 1;
	current_num = 0;
	while (--size)
	{
		if (temp->content != stack->biggest)
		{
			diff = stack->biggest - temp->content;
			if (current_num == 0 || diff < current_num)
			{
				current_num = diff;
				stack->biggest2 = temp->content;
			}
		}
		temp = temp->next;
	}
}

void	*biggest_third(t_stack *stack, t_data *data)
{
	int		size;
	long	diff;
	long	current_num;
	t_node	*temp;

	temp = stack->top;
	size = stack->size + 1;
	current_num = 0;
	while (--size)
	{
		if (temp->content < stack->biggest2)
		{
			diff = stack->biggest2 - temp->content;
			if (current_num == 0 || diff < current_num)
			{
				current_num = diff;
				stack->biggest3 = temp->content;
			}
		}
		temp = temp->next;
	}
}
