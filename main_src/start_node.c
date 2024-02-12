/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:28:39 by mlow              #+#    #+#             */
/*   Updated: 2024/01/04 14:28:55 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//refer to this website as to why i malloc this way:
//https://towardsdatascience.com/demystifying-linked-list-258dfb9f2176
void	*add_node(t_stack *stack_a, t_data *data)
{
	t_node	*newnode;
	int		index;
	int		position;

	index = -1;
	position = 1;
	while (++index < data->size)
	{
		newnode = (t_node *)malloc(sizeof(t_node));
		if (!newnode)
			free_both_exit(1, stack_a, NULL, data);
		newnode->content = data->array_c[index];
		newnode->next = NULL;
		newnode->position = position;
		ftps_lstadd_back(stack_a, newnode);
		position++;
	}
	newnode->next = stack_a->top;
}

void	**read_array_node(t_stack *a, t_stack *b, t_data *data, int argc)
{
	int		array;
	int		i;

	a->name = 'a';
	a->size = data->size;
	a->top = NULL;
	a->bottom = NULL;
	add_node(a, data);
	b->name = 'b';
	b->size = 0;
	b->top = NULL;
	b->bottom = NULL;
}

//	print_stack(&stack_a, &stack_b, data);
void	start_node(t_data *data, int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	read_array_node(&stack_a, &stack_b, data, argc);
	if (data->size <= 3)
		sort_three(&stack_a, data, 1);
	else
		sort_all(&stack_a, &stack_b, data);
	free_both_exit(2, &stack_a, &stack_b, data);
}
