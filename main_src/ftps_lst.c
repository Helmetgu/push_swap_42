/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftps_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:00:11 by mlow              #+#    #+#             */
/*   Updated: 2024/01/06 15:07:55 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//replacing all the lst functions in libft
#include "../includes/push_swap.h"

void	ftbs_free_stack(t_stack *stack)
{
	t_node	*temp;
	int		current;

	current = -1;
	while (++current < stack->size)
	{
		if (!(stack)->top->next)
			break ;
		temp = (stack)->top->next;
		free((stack)->top);
		stack->top = temp;
	}
	stack = NULL;
}

void	ftps_lstadd_back(t_stack *stack, t_node *new)
{
	if (!stack->top)
	{
		stack->top = new;
		stack->bottom = stack->top;
		new->prev = new;
		new->next = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
		stack->top->prev = stack->bottom;
	}
}

int	ftps_lstsize(t_node *lst)
{
	int		count_node;
	t_node	*node;

	if (!(lst))
		return (0);
	ft_printf("=======================\n", count_node);
	ft_printf("starts ftps_lstsize\n");
	node = lst;
	count_node = 1;
	while (node->next != lst)
	{
		if (!node->next)
			break ;
		node = node->next;
		count_node++;
	}
	ft_printf("Total node counter = %d\n", count_node);
	ft_printf("=======================\n", count_node);
	return (count_node);
}
