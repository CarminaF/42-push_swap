/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfamilar <cfamilar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:11:50 by cfamilar          #+#    #+#             */
/*   Updated: 2022/11/17 15:17:01 by cfamilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_number(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        if ((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1])
            j++;
        while(argv[i][j])
        {
            if(!ft_isdigit((int)argv[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int has_duplicates(int argc, char **argv)
{
    int i;
    int j;
    int num_len;

    i = 0;
    num_len = 0;
    while (i < argc - 1)
    {
        j = i + 1;
        while (j < argc)
        {
            if ((int)ft_strlen(argv[i]) >= (int)ft_strlen(argv[j]))
                num_len = (int)ft_strlen(argv[i]);
            else
                num_len = (int)ft_strlen(argv[j]);
            if (ft_strncmp(argv[i], argv[j], num_len) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int number_of_zeros(int argc, char **argv)
{
    int i;
    int j;
    int zeros;

    i = 1;
    zeros = 0;
    while(i < argc)
    {
        j = 0;
        if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        while (argv[i][j] && argv[i][j] =='0')
            j++;
        if (argv[i][j] == '\0')
            zeros++;
        i++;
    }
    return (zeros);
}
void    check(int argc, char **argv)
{
    if(!is_number(argc, argv))
        error();
    if(number_of_zeros(argc,argv) > 1)
        error();
    if(has_duplicates(argc, argv))
        error();
}

int    is_sorted(t_stack **stack_a)
{
    t_stack *temp;
    int     stack_size;

    temp = *stack_a;
    stack_size = get_stack_size(temp);
    if (stack_size == 0 || stack_size == 1)
        return (1);
    while(temp->next)
    {
        if(temp->value > temp->next->value)
            return (0);
        temp = temp->next;
    }
    return (1);
}