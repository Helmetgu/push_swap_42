/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:05:25 by mlow              #+#    #+#             */
/*   Updated: 2024/01/17 17:09:03 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack_a, t_data *data, int print)
{
	t_node	*n;
	int		counter;

	if (stack_a->size == 2)
		sa_sb(stack_a, data, 1);
	else if (stack_a->size == 3)
	{
		counter = stack_a->size + 1;
		while (--counter)
		{
			n = stack_a->top;
			if ((n->content) < (n->next->content) 
				&& (n->next->content) > n->next->next->content)
				rra_rrb(stack_a, data, 1);
			else if ((n->content > n->next->next->content)
				&& (n->content > n->next->content) 
				|| n->content > n->next->next->content)
				ra_rb(stack_a, data, 1);
			else if (n->next->content > n->next->next->content)
				rra_rrb(stack_a, data, 1);
			else if (n->content > n->next->content)
				sa_sb(stack_a, data, 1);
		}
	}
}

static void	sort_five_helper(t_stack *stack, t_data *data)
{
	int			median;
	t_node		*location;

	location = small_return_value(stack, data);
	median = find_median(stack, data);
	while (stack->top->content != stack->smallest)
	{
		if (location->position <= median)
			ra_rb(stack, data, 1);
		else if (location->position > median)
			rra_rrb(stack, data, 1);
	}
}
/*
11 2 3 4 22
ra
pb
pb
rra
sa
pa
pa
*/

void	sort_five(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int			median;
	t_node		*location;

	if (data->size == 5)
	{
		sort_five_helper(stack_a, data);
		pp(stack_a, stack_b, data);
	}
	sort_five_helper(stack_a, data);
	pp(stack_a, stack_b, data);
	sort_three(stack_a, data, 3);
	pp(stack_b, stack_a, data);
	pp(stack_b, stack_a, data);
}

void	sort_bthree(t_stack *stack_b, t_data *data, int print)
{
	t_node	*n;
	int		counter;

	if (stack_b->size == 3)
	{
		counter = stack_b->size + 1;
		while (--counter)
		{
			n = stack_b->top;
			if ((n->content) < (n->next->content) 
				&& (n->next->content) < n->next->next->content)
				ra_rb(stack_b, data, 1);
			else if ((n->content < n->next->next->content)
				&& (n->content < n->next->content) 
				|| n->content < n->next->next->content)
				rra_rrb(stack_b, data, 1);
			else if (n->next->content < n->next->next->content)
				ra_rb(stack_b, data, 1);
			else if (n->content < n->next->content)
				sa_sb(stack_b, data, 1);
		}
		update_pos(NULL, stack_b, data);
	}
}

void	sort_all(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int		median;
	int		size;
	t_node	*stack_location;

	if (data->size == 4 || data->size == 5)
		sort_five(stack_a, stack_b, data);
	else
	{
		biggest_five(stack_a, stack_b, data);
		sort_three(stack_a, data, 3);
		stack_location = biggest_value(stack_b, data);
		median = find_median(stack_b, data);
		if (stack_location->position <= median)
		{
			while (stack_b->top->content != stack_b->biggest)
				rra_rrb(stack_b, data, 1);
		}
		else if (stack_location->position > median)
		{
			while (stack_b->top->content != stack_b->biggest)
				ra_rb(stack_b, data, 1);
		}
		while (stack_b->size)
			pp(stack_b, stack_a, data);
	}
}
