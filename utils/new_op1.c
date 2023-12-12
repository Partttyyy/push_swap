/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:40:07 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 05:14:48 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	smallup_sa(t_both *both, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(both->sa && both->sa->next))
		return (0);
	if (both->sa->index < both->sa->next->index)
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

int	smallup_sb(t_both *both, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(both->sb && both->sb->next))
		return (0);
	if (both->sb->val < both->sb->next->val)
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
	return (1);
}

int	smallup_ss(t_both *both)
{
	int	returns;

	returns = smallup_sa(both, 0);
	if (!returns)
	{
		return (smallup_sb(both, 1));
	}
	returns += smallup_sb(both, 0);
	if (returns == 2)
		add_output(both, "ss");
	else
		add_output(both, "sa");
	return (returns);
}
