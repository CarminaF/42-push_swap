/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:29 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:45:01 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*get_penultimate(t_stack *stack)
{
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

static void	do_rrx(t_stack **stack)
{
	t_stack	*penultimate;
	t_stack	*last;
	t_stack	*temp;

	last = get_bottom_of_stack(stack);
	penultimate = get_penultimate(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	penultimate->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	do_rrx(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	do_rrb(t_stack **stack_b)
{
	do_rrx(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rrx(stack_a);
	do_rrx(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
