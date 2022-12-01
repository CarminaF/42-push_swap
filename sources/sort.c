/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:53 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:50:54 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_tiny_sort(t_stack **stack_a)
{
	int	highest;

	highest = get_highest_index(stack_a);
	if ((*stack_a)->index == highest)
		do_ra(stack_a);
	else if ((*stack_a)->next->index == highest)
		do_rra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

void	pb_all_leave_three(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < stack_size && pushed < stack_size / 2 && stack_size > 6)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

void	smallest_to_top(t_stack **stack)
{
	int	position;
	int	stack_size;

	stack_size = get_stack_size(*stack);
	position = get_lowest_index_position(stack);
	if (position > stack_size / 2)
	{
		while (position < stack_size)
		{
			do_rra(stack);
			position++;
		}
	}
	else
	{
		while (position > 0)
		{
			do_ra(stack);
			position--;
		}
	}
}

void	do_large_sort(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	pb_all_leave_three(stack_a, stack_b, stack_size);
	do_tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
	{
		smallest_to_top(stack_a);
	}
}
