/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:04 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 07:37:42 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra_bonus(t_both *both)
{
	t_stack	*last;
	t_stack	*stack_a;

	stack_a = both->sa;
	if (!stack_a || !(stack_a->next))
		return ;
	stack_a->next->last = NULL;
	last = stack_a;
	while (last->next)
		last = last->next;
	last->next = stack_a;
	both->sa = stack_a->next;
	stack_a->last = last;
	stack_a->next = NULL;
}

void	rb_bonus(t_both *both)
{
	t_stack	*last;
	t_stack	*new_last;

	new_last = both->sb;
	if (!(new_last && both->sb->next))
		return ;
	both->sb->next->last = NULL;
	last = both->sb;
	while (last->next)
		last = last->next;
	last->next = new_last;
	both->sb = both->sb->next;
	new_last->last = last;
	new_last->next = NULL;
}

void	rr_bonus(t_both *both)
{
	ra_bonus(both);
	rb_bonus(both);
}
