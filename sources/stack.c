/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:54:20 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/29 23:06:36 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *fill_stack(int argc, char **argv)
{
    int     i;
    long    num;
    t_stack *stack_a;

    i = 1;
    num = 0;
    stack_a = NULL;
    //printf("Filling stack with values...\n");
    while (i < argc)
    {
        num = str_to_num(argv[i]);
        if (num < INT_MIN || num > INT_MAX)
            error();
        if (i == 1)
		{
            stack_a = init_node((int)num);
			//ft_putnbr_fd(stack_a->value, 1);
		}
        else
            add_to_bottom_of_stack(&stack_a, init_node((int)num));
        i++;
    }
    //print_stack(&stack_a);
    return (stack_a);
}