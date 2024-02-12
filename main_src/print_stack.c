/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:04:40 by mlow              #+#    #+#             */
/*   Updated: 2024/01/21 15:05:23 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_ss(t_stack *this, t_node *stack, t_data *data)
{
	ft_printf("\n-----------------------------------\n");
	ft_printf("---------------print_ss------------\n");
	if (this->name == 'a')
		ft_printf("--------printing stack_a-----------\n");
	else if (this->name == 'b')
		ft_printf("--------printing stack_b-----------\n");
	ft_printf("-----------------------------------\n");
	ft_printf("\n");
	ft_printf("\t\tPrev-> [%d]\n", stack->prev->content);
	ft_printf("current-> [%d]\n", stack->content);
	ft_printf("\t\tNext-> [%d]\n", stack->next->content);
	ft_printf("-----------------------------------\n");
	ft_printf("\t\tPrev-> [%d]\n", stack->next->prev->content);
	ft_printf("current-> [%d]\n", stack->next->content);
	ft_printf("\t\tNext-> [%d]\n", stack->next->next->content);
	ft_printf("-----------------------------------\n");
	ft_printf("\t\tPrev-> [%d]\n", stack->next->next->prev->content);
	ft_printf("current-> [%d]\n", stack->next->next->content);
	ft_printf("\t\tNext-> [%d]\n", stack->next->next->next->content);
	ft_printf("-----------------------------------\n");
	ft_printf(">>>>Prev checking from stack[%d]<<<<\n", stack->content);
	ft_printf("Previous-> [%d]\n", stack->prev->content);
	ft_printf("\t\tCurrent-> [%d]\n", stack->prev->next->content);
	ft_printf("\n");
}

void	print_pp(t_stack *this, t_node *stack, t_data *data)
{
	int		position;
	t_node	*node;
	t_node	*previous;

	ft_printf("\n-----------------------------------\n");
	ft_printf("---------------print_pp------------\n");
	if (this->name == 'a')
		ft_printf("--------printing stack_a-----------\n");
	else if (this->name == 'b')
		ft_printf("--------printing stack_b-----------\n");
	ft_printf("-----------------------------------\n");
	position = this->size;
	node = stack;
	previous = stack->prev;
	while (position)
	{
		ft_printf("\t\tPrev-> [%d]\n", node->prev->content);
		ft_printf("current-> [%d]\n", node->content);
		ft_printf("\t\tNext-> [%d]\n", node->next->content);
		ft_printf("-----------------------------------\n");
		node = node->next;
		position--;
	}
}

void	print_ab(t_stack *stack, t_data *data)
{
	t_node	*node;
	int		counter;

	node = stack->top;
	counter = stack->size;
	while (counter--)
	{
		ft_printf("stack_%c position %d", stack->name, node->position);
		ft_printf("= [%d]\n", node->content);
		ft_printf("\t\tPrev-> [%d]\n", node->prev->content);
		ft_printf("current-> [%d]\n", node->content);
		ft_printf("\t\tNext-> [%d]\n", node->next->content);
		ft_printf("-----------------------------------\n");
		if (node->next == (stack)->top || !node->next)
			break ;
		node = node->next;
	}
	if (node->next)
		node = node->next;
}

void	print_stack(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node	*node;
	int		counter;

	ft_printf("\n----stacka----\n");
	if ((stack_a)->size > 0)
		print_ab(stack_a, data);
	ft_printf("----stackb----\n");
	if ((stack_b)->size > 0)
		print_ab(stack_b, data);
	ft_printf("\nTotal commands made: %d\n\t-end-\n", data->total_moves);
}
