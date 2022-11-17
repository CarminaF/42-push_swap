/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:54:20 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/17 13:36:20 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	str_to_num(const char *str) //ft_atoi but returns a long
{
	int		i;
	int		op;
	long	res;

	i = 0;
	op = 1;
	res = 0;
	if (*str == 0)
		return (0);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			op = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * op);
}

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
		ft_putnbr_fd(num, 1);
		ft_putchar_fd('\n', 1);
        if (num < INT_MIN || num > INT_MAX)
            error();
        if (i == 1)
            stack_a = init_node((int)num);
        else
            add_to_bottom_of_stack(&stack_a, init_node((int)num));
        i++;
    }
    return (stack_a);
}