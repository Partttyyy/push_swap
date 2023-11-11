/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:41 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 06:19:31 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_both *both, int print)
{
	t_stack	*last;
	print++;
	print--;
	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	if (!((both->sa) && (both->sa->next)))
		return (0);
	last = both->sa;
	while (last->next->next)
		last = last->next;
	last->next->next = both->sa;
	both->sa = last->next;
	last->next = NULL;
	both->sa->next->last = both->sa;
	both->sa->last = NULL;
	if (print)
	{//	global_count++;
	 	add_output(both, "rra");
	}
	return (1);
}

int	rrb(t_both *both, int print)
{
	t_stack	*last;

	print++;
	print--;


	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	if (!(both->sb) || !(both->sb->next))
		return (0);
	last = both->sb;
	while (last->next->next)
		last = last->next;
	last->next->next = both->sb;
	both->sb = last->next;
	last->next = NULL;
	both->sb->next->last = both->sb;
	both->sb->last = NULL;
	if (print)
	{
		global_count++;
		add_output(both, "rrb");
	}
	return (1);
}

int	rrr(t_both *both)
{
	int	returns;

	if (!both)
	{
		ft_printf("NO BOTH!!!\n");
		return (0);
	}
	if (!((both->sa && both->sa->next) || (both->sb && both->sb->next)))
		return (0);
	returns = rra(both, 0);
	if (!returns)
	{
		if (!rrb(both, 1))
			return (0);
		return (1);
	}
	returns += rrb(both, 0);
//	global_count++;
	if (returns == 2)
		add_output(both, "rrr");
	else
		add_output(both, "rra");
	return (returns);
}
