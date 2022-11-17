/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:49:42 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/15 19:12:24 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    free_stack(t_stack *stack)
{
    t_stack *temp;

    temp = NULL;
    while(stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}