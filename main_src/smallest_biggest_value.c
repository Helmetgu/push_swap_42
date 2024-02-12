/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallest_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:42:56 by mlow              #+#    #+#             */
/*   Updated: 2024/01/26 15:09:37 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Find the smallest value in that stack
t_node	*small_return_value(t_stack *stack, t_data *data)
{
	int		size;
	t_node	*location;
	t_node	*t;

	location = stack->top;
	stack->smallest = stack->top->content;
	size = stack->size + 1;
	t = stack->top;
	while (--size)
	{
		if (stack->smallest > t->content)
		{
			location = t;
			stack->smallest = t->content;
		}
		t = t->next;
	}
	return (location);
}

//finds the biggest value for stack
t_node	*biggest_value(t_stack *stack, t_data *data)
{
	int		size;
	t_node	*temp;
	t_node	*location;

	temp = stack->top;
	location = temp;
	stack->biggest = temp->content;
	size = stack->size;
	while (size)
	{
		if (stack->biggest < temp->content)
		{
			location = temp;
			stack->biggest = temp->content;
		}
		temp = temp->next;
		size--;
	}
	stack->biggest = location->content;
	return (location);
}
