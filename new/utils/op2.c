/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:04 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 06:18:51 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_both *both, int print)
{
	t_stack	*last;
	t_stack	*stack_a;
	print++;
	print--;
	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	stack_a = both->sa;
	if (!stack_a || !(stack_a->next))
		return (0);
	stack_a->next->last = NULL;
	last = stack_a;
	while (last->next)
		last = last->next;
	last->next = stack_a;
	both->sa = stack_a->next;
	stack_a->last = last;
	stack_a->next = NULL;
	if (print)
	{
		global_count++;
		add_output(both, "ra");
	}
	return (1);
}

int	rb(t_both *both, int print)
{
	t_stack	*last;
	t_stack	*new_last;
	print++;
	print--;
	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	new_last = both->sb;
	if (!(new_last && both->sb->next))
		return (0);
	both->sb->next->last = NULL;
	last = both->sb;
	while (last->next)
		last = last->next;
	last->next = new_last;
	both->sb = both->sb->next;
	new_last->last = last;
	new_last->next = NULL;
	if (print)
	{
		global_count++;
		add_output(both, "rb");
	}
	return (1);
}

int	rr(t_both *both)
{
	int	returns;

	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	if (!((both->sa && both->sa->next) || (both->sb && both->sb->next)))
		return (0);
	returns = ra(both, 0);
	if (!returns)
	{
		if (!rb(both, 1))
			return (0);
		return (1);
	}
	returns += rb(both, 0);
	global_count++;
	if (returns == 2)
		add_output(both, "rr");
	else
		add_output(both, "ra");
	return (returns);
}
