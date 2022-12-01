/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:37:01 by cfamilar          #+#    #+#             */
/*   Updated: 2022/12/01 14:52:47 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	int		i;
	long	num;
	t_stack	*stack_a;

	i = 1;
	num = 0;
	stack_a = NULL;
	while (i < argc)
	{
		num = str_to_num(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error();
		if (i == 1)
		{
			stack_a = init_node((int)num);
		}
		else
			add_to_bottom_of_stack(&stack_a, init_node((int)num));
		i++;
	}
	return (stack_a);
}
