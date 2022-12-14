/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   move.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cfamilar <cfamilar@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/01 14:04:55 by cfamilar		  #+#	#+#			 */
/*   Updated: 2022/12/01 14:33:46 by cfamilar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		do_rrr(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
	return ;
}

void	rr_both(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		do_rr(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
	return ;
}

void	rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		do_ra(stack_a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		do_rra(stack_a);
		(*cost_a)++;
	}
}

void	rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		do_rb(stack_b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		do_rrb(stack_b);
		(*cost_b)++;
	}
}

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rr_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		rrr_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
