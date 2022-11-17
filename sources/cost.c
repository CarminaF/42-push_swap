/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:28:56 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/16 20:26:43 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
    int     stack_size_a;
    int     stack_size_b;
    t_stack *temp_a;
    t_stack *temp_b;

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