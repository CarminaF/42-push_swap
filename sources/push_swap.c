/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:00:56 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/17 15:28:02 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    if (stack_size == 2)
        do_sa(stack_a);
    else if (stack_size == 3)
        do_tiny_sort(stack_a);
    else if (stack_size > 3)
        do_large_sort(stack_a, stack_b, stack_size);
    return;
}