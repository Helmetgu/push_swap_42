/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:20:42 by mlow              #+#    #+#             */
/*   Updated: 2024/01/10 18:10:51 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
------------------------------------------
	temp = (*stacka)->next;

	1)stacka->next = temp->next
	   (4)	   (7)		(5);

	2)temp->next = stacka
	   (7)   (5)	(4);
	   
	3)stacka = temp;
	   (4)	    (7);
------------------------------------------
*/
static void	sa_sb_helper(t_stack *stack, t_data *data, int print)
{
	if (print != 3)
	{
		if (stack->name == 'a')
			ft_printf("sa\n");
		else if (stack->name == 'b')
			ft_printf("sb\n");
		data->total_moves += 1;
	}
}

//swap first 2 elements at top of stacka
//Do nothing if there is only one or no elements.
//sa_sb_helper(stack, data, 3);
void	sa_sb(t_stack *stack, t_data *data, int print)
{
	t_node	*node;
	t_node	*temp;
	int		counter;

	if (!stack || (!(stack)->top) || (!(stack)->size))
		return ;
	sa_sb_helper(stack, data, print);
	temp = (stack)->top->next;
	(stack)->top->next = temp->next;
	temp->next = (stack)->top;
	(stack)->top = temp;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	(stack)->bottom->next = (stack)->top;
	if (stack->name == 'a')
		update_pos(stack, NULL, data);
	else if (stack->name == 'b')
		update_pos(NULL, stack, data);
	update_prev_ss(stack, data);
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	ft_printf("ss");
	sa_sb(stack_a, data, 3);
	sa_sb(stack_b, data, 3);
	data->total_moves += 1;
}
