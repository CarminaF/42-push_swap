/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:36:37 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:46:09 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rx(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	*stack = (*stack)->next;
	head->next = NULL;
	add_to_bottom_of_stack(stack, head);
}

void	do_ra(t_stack **stack_a)
{
	do_rx(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	do_rb(t_stack **stack_b)
{
	do_rx(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_rx(stack_a);
	do_rx(stack_b);
	ft_putstr_fd("rr\n", 1);
}
