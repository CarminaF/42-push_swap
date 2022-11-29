/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:02:05 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/29 21:12:50 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *get_penultimate(t_stack *stack)
{
    while (stack->next->next)
        stack = stack->next;
    return (stack);
}

static void    do_rrx(t_stack **stack)
{
    t_stack *penultimate;
    t_stack *last;
    t_stack *temp;

    last = get_bottom_of_stack(stack);
    /*ft_putstr_fd("bottom of stack value: ", 1);
    ft_putnbr_fd(last->value, 1);
    ft_putchar_fd('\n', 1);*/
    penultimate = get_penultimate(*stack);
    temp = *stack;
    *stack = last;
    (*stack)->next = temp;
    penultimate->next = NULL;
}

void    do_rra(t_stack **stack_a)
{
    do_rrx(stack_a);
    ft_putstr_fd("rra\n", 1);
}

void    do_rrb(t_stack **stack_b)
{
    do_rrx(stack_b);
    ft_putstr_fd("rrb\n", 1);
}

void    do_rrr(t_stack **stack_a, t_stack **stack_b)
{
    do_rrx(stack_a);
    do_rrx(stack_b);
    ft_putstr_fd("rrr\n", 1);
}