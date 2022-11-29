/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:18:08 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/22 20:30:26 by cfamilar         ###   ########.fr       */
/*               ()                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rev_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
        
    while(*cost_a < 0 && *cost_b < 0)
    {
        do_rrr(stack_a, stack_b);
        (*cost_a)++;
        (*cost_b)++;
    }
    return ;
}
void    rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
        
    while(*cost_a > 0 && *cost_b > 0)
    {
        do_rr(stack_a, stack_b);
        (*cost_a)--;
        (*cost_b)--;
    }
    return ;
}

void    rotate_a(t_stack **stack_a, int *cost_a)
{
    while(*cost_a > 0)
    {
        do_ra(stack_a);
        (*cost_a)--;
    }
    while(*cost_a < 0)
    {
        do_rra(stack_a);
        (*cost_a)++;
    }
}

void    rotate_b(t_stack **stack_b, int *cost_b)
{
    while(*cost_b > 0)
    {
        do_rb(stack_b);
        (*cost_b)--;
    }
    while(*cost_b < 0)
    {
        do_rrb(stack_b);
        (*cost_b)++;
    }
}

void    do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
    if (cost_a > 0 && cost_b > 0)
        rotate_both(stack_a, stack_b, &cost_a, &cost_b);
    else if (cost_a < 0 && cost_b < 0)
        rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
    rotate_a(stack_a, &cost_a);
    rotate_b(stack_b, &cost_b);
    do_pa(stack_a, stack_b);
}

void    do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *temp_b;
    int cheapest;
    int cost_a;
    int cost_b;

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
    //print_stack (stack_a);
}

