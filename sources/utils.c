/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:18:40 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/29 23:23:31 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_abs(int num)
{
    if (num < 0)
        return(num * -1);
    return (num);
}

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

// void	print_stack(t_stack **stack)
// {
// 	t_stack *temp;
	
// 	temp = *stack;
// 	if (!temp)
// 		printf("Stack empty\n.");
// 	while (temp)
// 	{
// 		printf("Value: %i, Index: %i, Target Position: %i\n", temp->value, temp->index, temp->target_position);
// 		temp = temp->next;
// 	}
// }
