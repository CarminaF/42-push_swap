/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:00:41 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/25 11:37:04 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    do_push(t_stack **source, t_stack **dest)
{
    t_stack *temp;

    if (*source == NULL)
        return ;
    temp = (*source)->next;
    (*source)->next = *dest;
    *dest = *source;
    *source = temp;
}

void    do_pa(t_stack **stack_a, t_stack **stack_b)
{
    do_push(stack_b, stack_a);
    ft_putstr_fd("pa\n", 1);
}

void    do_pb(t_stack **stack_a, t_stack **stack_b)
{
    do_push(stack_a, stack_b);
    ft_putstr_fd("pb\n", 1);
}

