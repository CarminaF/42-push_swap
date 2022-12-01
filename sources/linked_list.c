/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:26:08 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:02:20 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof (t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->current_position = -1;
	new->target_position = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_stack	*get_bottom_of_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp)
		while (temp->next)
			temp = temp->next;
	return (temp);
}

void	add_to_bottom_of_stack(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = get_bottom_of_stack(stack);
	temp->next = new;
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
