/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:08:52 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/23 18:31:19 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     stack_size;

    if (argc < 2)
        return (0);
    check(argc, argv);
    stack_b = NULL;
    stack_a = fill_stack(argc, argv);
    stack_size = get_stack_size(stack_a);
    get_index(stack_a, stack_size);
    if (!is_sorted(stack_a))
        push_swap(&stack_a, &stack_b, stack_size);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}