/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:40:07 by frapp             #+#    #+#             */
/*   Updated: 2023/12/10 18:06:50 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa_bonus(t_both *both)
{
	t_stack	*first;
	t_stack	*second;

	if (!(both->sa && both->sa->next))
		return ;
	first = both->sa;
	second = both->sa->next;
	first->next = second->next;
	if (second->next)
		second->next->last = first;
	second->next = first;
	second->last = NULL;
	first->last = second;
	both->sa = second;
}

void	sb_bonus(t_both *both)
{
	int		val;
	t_stack	*first;
	t_stack	*second;

	val = 1;
	if (!(both->sb && both->sb->next))
		return ;
	first = both->sb;
	second = both->sb->next;
	first->next = second->next;
	if (second->next)
		second->next->last = first;
	second->next = first;
	second->last = NULL;
	first->last = second;
	both->sb = second;
}

void	ss_bonus(t_both *both)
{
	sa_bonus(both);
	sb_bonus(both);
}

void	pa_bonus(t_both *both)
{
	t_stack	*old_sb;

	if (!both->sb)
		return ;
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
}

// has to change:
//	both->sa->next->last = NULL			done 1
//	both->sa = both->sa->next			done 2
//	old both->sa->next = old both->sb	done 3
//	old both->sb->last = old both->sa	done 4
//	both->sb = old both->sa				done 5
void	pb_bonus(t_both *both)
{
	t_stack	*old_sa;

	if (!both->sa)
		return ;
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
}
