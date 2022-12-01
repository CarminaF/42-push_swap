/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:46:57 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:39:24 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_target(t_stack **stack_a, int b_index, int target_index, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->current_position;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

void	get_current_position(t_stack **stack)
{
	t_stack	*ptr;
	int		current_pos;

	ptr = *stack;
	current_pos = 0;
	while (ptr)
	{
		ptr->current_position = current_pos;
		ptr = ptr->next;
		current_pos++;
	}
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	int		target_pos;

	temp_b = *stack_b;
	target_pos = 0;
	get_current_position(stack_a);
	get_current_position(stack_b);
	while (temp_b)
	{
		target_pos = get_target(stack_a, temp_b->index, INT_MAX, target_pos);
		temp_b->target_position = target_pos;
		temp_b = temp_b->next;
	}
}
