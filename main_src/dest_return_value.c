/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dest_return_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:42:57 by mlow              #+#    #+#             */
/*   Updated: 2024/02/06 15:43:21 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*dest_value(t_node *current, t_stack *other, t_data *data)
{
	long	size;
	long	closest_big;
	t_node	*location;
	t_node	*t;

	size = other->size + 1;
	closest_big = INT_MIN;
	t = other->top;
	while (--size)
	{
		if (current->content > t->content && closest_big < t->content)
		{
			closest_big = t->content;
			current->move_cost = current->tcost + t->tcost;
			location = t;
		}
		t = t->next;
	}
	if ((current)->move_cost == -1)
	{
		location = biggest_value(other, data);
		current->move_cost = current->tcost + location->tcost;
	}
	return (location);
}

t_node	*return_helper(t_node *current, t_stack *other, t_data *data)
{
	int		size;
	int		close_small;
	int		compare;
	t_node	*location;
	t_node	*t;

	size = other->size + 1;
	close_small = 0;
	compare = 0;
	t = other->top;
	while (--size)
	{
		if (current->content < t->content)
		{
			compare = t->content - current->content;
			if (close_small == 0 || close_small > compare)
			{
				close_small = compare;
				current->move_cost = current->tcost + t->tcost;
				location = t;
			}
		}
		t = t->next;
	}
	return (location);
}

t_node	*return_value(t_node *current, t_stack *other, t_data *data)
{
	t_node	*location;
	t_node	*t;

	location = return_helper(current, other, data);
	if ((current)->move_cost == -1)
	{
		location = small_return_value(other, data);
		current->move_cost = current->tcost + location->tcost;
	}
	return (location);
}
