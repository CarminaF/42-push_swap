/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:54:20 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/25 11:44:45 by cfamilar         ###   ########.fr       */
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
    while (i < argc)
    {
        num = str_to_num(argv[i]);
		/*ft_putnbr_fd(num, 1);
		ft_putchar_fd('\n', 1);*/
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
    return (stack_a);
}