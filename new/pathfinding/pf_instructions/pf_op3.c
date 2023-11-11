/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_op3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:41 by frapp             #+#    #+#             */
/*   Updated: 2023/11/06 20:09:44 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pf.h"

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
	//if (print)
	//	global_count++;
	// 	ft_printf("rra\n");
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
	//if (print)
	//	global_count++;
	// 	ft_printf("rrb\n");
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
	returns += rrb(both, 0);
//	global_count++;
	//ft_printf("rrr\n");
	return (returns);
}