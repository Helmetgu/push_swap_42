/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:58:54 by mlow              #+#    #+#             */
/*   Updated: 2024/01/08 15:59:20 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	update_pos(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node	*current;
	int		position;

	if (stack_a && stack_a->name == 'a')
	{
		current = stack_a->top;
		position = 1;
		while (position <= stack_a->size)
		{
			current->position = position;
			position++;
			current = current->next;
		}
	}
	if (stack_b && stack_b->name == 'b')
	{
		current = stack_b->top;
		position = 1;
		while (position <= stack_b->size)
		{
			current->position = position;
			position++;
			current = current->next;
		}
	}
}

void	update_prev_ss(t_stack *stack, t_data *data)
{
	t_node	*previous;
	t_node	*current;

	if (stack)
	{
		previous = stack->bottom;
		current = stack->top;
		current->prev = previous;
		current->next->prev = current;
		current->next->next->prev = current->next;
		previous->next = current;
	}
}

void	update_prev_pp(t_stack *stack, t_data *data)
{
	t_node	*previous;
	t_node	*current;
	t_node	*temp;

	if (stack->size > 0)
	{
		temp = stack->top->next;
		current = stack->top;
		if (stack->size == 1)
			stack->bottom = current;
		else if (stack->size == 2)
			stack->bottom->prev = current;
		previous = stack->bottom;
		current->prev = previous;
		previous->next = current;
		previous = current;
		current = current->next;
		temp->prev = stack->top;
	}
}

void	update_prev_push(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (stack_a->name != 'a' || stack_b->name != 'b')
	{
		ft_printf("\nNAMES ARE WRONG IN HERE DUDE, ERROR EXIT!!\n");
		exit(1);
	}
	update_prev_pp(stack_a, data);
	update_prev_pp(stack_b, data);
}
