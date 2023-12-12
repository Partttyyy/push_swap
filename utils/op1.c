/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:40:07 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 05:53:00 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_both *both, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(both->sa && both->sa->next))
		return (0);
	if (both->sa->val < both->sa->next->val)
		return (0);
	first = both->sa;
	second = both->sa->next;
	first->next = second->next;
	if (second->next)
		second->next->last = first;
	second->next = first;
	second->last = NULL;
	first->last = second;
	both->sa = second;
	if (print)
		add_output(both, "sa");
	return (1);
}

int	sb(t_both *both, int print)
{
	int		val;
	t_stack	*first;
	t_stack	*second;

	val = 1;
	if (!(both->sb && both->sb->next))
		return (0);
	if (both->sb->val > both->sb->next->val)
		return (0);
	first = both->sb;
	second = both->sb->next;
	first->next = second->next;
	if (second->next)
		second->next->last = first;
	second->next = first;
	second->last = NULL;
	first->last = second;
	both->sb = second;
	if (print)
		add_output(both, "sb");
	return (val);
}
// int	ss(t_both *both)
// {
// 	int	returns;

// 	returns = sa(both, 0);
// 	returns += sb(both, 0);
// 	ft_printf("ss\n");
// 	return (returns);
// }

int	pa(t_both *both)
{
	t_stack	*old_sb;

	if (!both->sb)
		return (0);
	old_sb = both->sb;
	if (old_sb->next)
	{
		old_sb->next->last = NULL;
		both->sb = old_sb->next;
	}
	else
		both->sb = NULL;
	old_sb->next = both->sa;
	if (both->sa)
		both->sa->last = old_sb;
	both->sa = old_sb;
	(both->size_b)--;
	(both->size_a)++;
	add_output(both, "pa");
	return (1);
}

// has to change:
//	both->sa->next->last = NULL			done 1
//	both->sa = both->sa->next			done 2
//	old both->sa->next = old both->sb	done 3
//	old both->sb->last = old both->sa	done 4
//	both->sb = old both->sa				done 5
int	pb(t_both *both)
{
	t_stack	*old_sa;

	if (!both->sa)
		return (0);
	old_sa = both->sa;
	if (old_sa->next)
	{
		old_sa->next->last = NULL;
		both->sa = old_sa->next;
	}
	else
		both->sa = NULL;
	old_sa->next = both->sb;
	if (both->sb)
		both->sb->last = old_sa;
	both->sb = old_sa;
	(both->size_a)--;
	(both->size_b)++;
	add_output(both, "pb");
	return (1);
}
