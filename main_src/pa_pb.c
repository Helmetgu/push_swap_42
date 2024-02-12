/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:30:18 by mlow              #+#    #+#             */
/*   Updated: 2024/01/10 11:33:44 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pp_helper(t_stack *stack_1, t_stack *stack_2, t_data *data)
{
	t_node	*node;
	t_node	*temp;
	t_node	*tempa;
	t_node	*tempb;

	temp = (stack_1)->top->next;
	tempa = (stack_1)->top;
	tempb = (stack_2)->top;
	(stack_2)->top = tempa;
	(stack_2)->top->next = tempb;
	stack_1->size -= 1;
	stack_2->size += 1;
	if (stack_2->size == 1)
		(stack_2)->top->next = (stack_2)->top;
	(stack_1)->top = temp;
	if (stack_1)
		(stack_1)->top->next = temp->next;
}

//stack_1 pushed to stack_2 (e.g stacka ->stackb);
void	pp(t_stack *stack_1, t_stack *stack_2, t_data *data)
{
	int		counter;

	if (!stack_1 || (!(stack_1)->top) || (!(stack_1)->size))
		return ;
	ft_printf("p%c\n", stack_2->name);
	pp_helper(stack_1, stack_2, data);
	if (stack_1->name == 'a')
	{
		update_pos(stack_1, stack_2, data);
		update_prev_push(stack_1, stack_2, data);
	}
	else
	{
		update_pos(stack_2, stack_1, data);
		update_prev_push(stack_2, stack_1, data);
	}
	data->total_moves += 1;
}
