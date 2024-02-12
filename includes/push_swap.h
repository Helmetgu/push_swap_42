/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:36:58 by mlow              #+#    #+#             */
/*   Updated: 2024/01/02 15:55:07 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../other_srcs/libft_project/libft.h"
# include "../other_srcs/printf_project/libftprintf.h"
# include "../other_srcs/get_next_line_project/get_next_line_bonus.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int					content;
	int					position;
	int					cost;
	int					cost_rr;
	int					tcost;
	int					move_cost;
	struct s_node		*next;
	struct s_node		*prev;
	struct s_node		*target;
}				t_node;

typedef struct s_stack
{
	char	name; 
	int		size;
	int		smallest;
	int		biggest;
	int		biggest2;
	int		biggest3;
	t_node	*top;
	t_node	*bottom;
}				t_stack;

//strut
typedef struct s_data {
	bool	require_sorting;
	bool	duplicate;
	char	**temp_args;
	int		*array_c;
	int		size;
	int		total_moves;
	t_node	*node;
}				t_data;

//exit.c
void	end_exit(int exit_code);
void	free_end_exit(int exit_code, t_data *data);
void	free_node_exit(int exit_code, t_stack *stack);
void	free_both_exit(int exit_code, t_stack *a, t_stack *b, t_data *data);

//ftps_lst.c
void	ftbs_free_stack(t_stack *stack);
t_node	*ftps_lstlast(t_stack *lst);
void	ftps_lstadd_back(t_stack *stack, t_node *new);
int		ftps_lstsize(t_node *lst);

//checker.c;
void	multiple_number_str_checker(t_data *data, char **argv);
void	single_arg_str_checker(t_data *data, char **argv);
void	duplicate_checker(t_data *data, int *array_c);
bool	is_sorted(t_data *data, int *array_c, int size);
void	params_checker(t_data *data, int argc, char **argv);

//push_swap.c
void	variables(t_data *data);
void	init_array(t_data *data, int argc, char **argv);

//ft_atol.c
long	ft_atol(const char *nptr);

//sort.c
t_node	**create_list_node(t_node **list, t_data *data);
void	*add_node(t_stack *stack_a, t_data *data);
void	second_variables(t_stack *stack);
void	**read_array_node(t_stack *a, t_stack *b, t_data *data, int argc);
void	start_node(t_data *data, int argc, char **argv);

//pos.c
void	update_pos(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	update_prev_ss(t_stack *stack, t_data *data);
void	update_prev_pp(t_stack *stack_a, t_data *data);
void	update_prev_push(t_stack *stack_a, t_stack *stack_b, t_data *data);

//sa_sb_ss.c
void	sa_sb(t_stack *stack, t_data *data, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, t_data *data);

//pa_pb.c
void	pp_helper(t_stack *stack_1, t_stack *stack_2, t_data *data);
void	pp(t_stack *stack_a, t_stack *stack_b, t_data *data);

//ra_rb_rr.c
void	ra_rb(t_stack *stack, t_data *data, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, t_data *data);

//rra_rrb_rrr.c
void	rra_rrb(t_stack *stack, t_data *data, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_data *data);

//print_stack.c
void	print_ss(t_stack *this, t_node *stack, t_data *data);
void	print_pp(t_stack *this, t_node *stack, t_data *data);
void	print_ab(t_stack *stack, t_data *data);
void	print_stack(t_stack *stacka, t_stack *stackb, t_data *data);

//biggest_five.c
void	biggest_five(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	*biggest_second(t_stack *stack, t_data *data);
void	*biggest_third(t_stack *stack, t_data *data);
void	*biggest_fourth(t_stack *stack, t_data *data);
void	*biggest_fifth(t_stack *stack, t_data *data);

//smallest_value or biggest_value
void	smallest_value(t_stack *stack, t_data *data);
t_node	*biggest_value(t_stack *stack_b, t_data *data);
t_node	*small_return_value(t_stack *stack, t_data *data);

//dest_return_value.c
t_node	*dest_value(t_node *current_stack, t_stack *stack_t, t_data *data);
t_node	*return_helper(t_node *current, t_stack *other, t_data *data);
t_node	*return_value(t_node *current, t_stack *other, t_data *data);

//sort.c
void	sort_three(t_stack *stack_a, t_data *data, int print);
void	sort_bthree(t_stack *stack_b, t_data *data, int print);
void	sort_five(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	sort_all(t_stack *stack_a, t_stack *stack_b, t_data *data);

//rotation_cost.c
void	r_cost(t_stack *stack, t_data *data);
void	total_cost(t_stack *stack_a, t_stack *stack_b, t_data *data);

//move_cost.c
t_node	*find_lowest_cost(t_stack *stack, t_data *data);

//median.c
int		find_median(t_stack *stack, t_data *data);

//algo_rotation,c
void	*algo_stacka_top(t_stack *a, t_stack *b, t_data *data, t_node *node_t);
void	return_cost(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	algo_rotation(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	final_rotation(t_stack *stack_b, t_stack *stack_a, t_data *data);

//exit_utils.c
//void	end_exit();
#endif
/*
#include <unistd.h> // for fork() / execve() / access()
#include <stdio.h> // for printf()
#include <stdlib.h> // exit()
#include <fcntl.h> //open()
#include <sys/wait.h> // wait() / waitpid()
#include <sys/types.h> //for wait() / fork() / pid_t() / wait() / waitpid() 
#include <errno.h> // for perror()
#include <stdbool.h> // for bool
*/
