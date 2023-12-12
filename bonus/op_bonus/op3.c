/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:41 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 07:36:59 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rra_bonus(t_both *both)
{
	t_stack	*last;

	if (!((both->sa) && (both->sa->next)))
		return ;
	last = both->sa;
	while (last->next->next)
		last = last->next;
	last->next->next = both->sa;
	both->sa = last->next;
	last->next = NULL;
	both->sa->next->last = both->sa;
	both->sa->last = NULL;
}

void	rrb_bonus(t_both *both)
{
	t_stack	*last;

	if (!(both->sb) || !(both->sb->next))
		return ;
	last = both->sb;
	while (last->next->next)
		last = last->next;
	last->next->next = both->sb;
	both->sb = last->next;
	last->next = NULL;
	both->sb->next->last = both->sb;
	both->sb->last = NULL;
}

void	rrr_bonus(t_both *both)
{
	rra_bonus(both);
	rrb_bonus(both);
}
