/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:37:10 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:53:44 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_swap(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_sa(t_stack **stack_a)
{
	do_swap(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack **stack_b)
{
	do_swap(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	do_swap(*stack_a);
	do_swap(*stack_b);
	ft_putstr_fd("ss\n", 1);
}
