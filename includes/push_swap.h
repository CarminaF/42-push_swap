/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:42:53 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:32:38 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../libraries/libft/libft.h"

typedef struct stack
{
	int				value;
	int				index;
	int				current_position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct stack	*next;
}	t_stack;

//void    print_stack(t_stack **stack);
int		get_stack_size(t_stack *stack);
int		get_abs(int num);
int		is_sorted(t_stack *stack_a);
int		get_highest_index(t_stack **stack);
int		get_lowest_index_position(t_stack **stack);
void	error(void);
void	check(int argc, char **argv);
void	do_sa(t_stack **stack_a);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
void	free_stack(t_stack *stack);
long	str_to_num(const char *str);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	add_to_bottom_of_stack(t_stack **stack, t_stack *new);
void	do_tiny_sort(t_stack **stack_a);
void	do_large_sort(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	calculate_cost(t_stack **stack_a, t_stack **stack_b);
void	get_index(t_stack *stack_a, int stack_size);
void	get_current_position(t_stack **stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
t_stack	*fill_stack(int argc, char **argv);
t_stack	*init_node(int value);
t_stack	*get_bottom_of_stack(t_stack **stack);
#endif
