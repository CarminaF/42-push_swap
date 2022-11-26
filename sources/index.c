/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:53:36 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/15 21:17:27 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    get_highest_index(t_stack **stack)
{
    int     highest;
    t_stack *temp;

    temp = *stack;
    while (temp)
    {
        if (temp->index > highest)
            highest = temp->index;
        temp = temp->next;
    }
    return (highest);
}

int    get_lowest_index_position(t_stack **stack)
{
    int     lowest;
    int     position;
    t_stack *temp;

    get_current_position(stack);
    temp = *stack;
    while (temp)
    {
        if (temp->index < lowest)
        {
            lowest = temp->index;
            position = temp->current_position;
        }
        temp = temp->next;
    }
    return (position);
}

void    get_index(t_stack *stack_a, int stack_size)
{
    int     value;
    int     current_index;
    t_stack *highest;
    t_stack *ptr;

    current_index = stack_size + 1;
    while (--current_index> 0)
    {
        ptr = stack_a;
        value = INT_MIN;
        highest = NULL;
        while (ptr)
        {
            if (ptr->value == INT_MIN && ptr->index == -1)
                ptr->index = 1;
            if (ptr->value > value && ptr->index == -1)
            {
                value = ptr->value;
                highest = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr->next;
        }
        if(highest != NULL)
            highest->index = current_index;
    }
}