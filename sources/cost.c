/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:56 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:55:19 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		stack_size_a;
	int		stack_size_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	stack_size_a = get_stack_size(temp_a);
	stack_size_b = get_stack_size(temp_b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->current_position;
		if (temp_b->current_position > stack_size_b / 2)
			temp_b->cost_b = (stack_size_b - temp_b->current_position) * -1;
		temp_b->cost_a = temp_b->target_position;
		if (temp_b->target_position > stack_size_a / 2)
			temp_b->cost_a = (stack_size_a - temp_b->target_position) * -1;
		temp_b = temp_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp_b = *stack_b;
	cheapest = INT_MAX;
	while (temp_b)
	{
		if ((get_abs(temp_b->cost_a) + get_abs(temp_b->cost_a)) < cheapest)
		{
			cheapest = get_abs(temp_b->cost_a) + get_abs(temp_b->cost_b);
			cost_a = temp_b->cost_a;
			cost_b = temp_b->cost_b;
		}
		temp_b = temp_b->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
