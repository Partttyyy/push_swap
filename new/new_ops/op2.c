/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:41:04 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 04:06:46 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	ra(t_both *both, int print)
// {
// 	t_stack	*last;
// 	t_stack	*stack_a;
// 	print++;
// 	print--;
// 	if (!both)
// 	{
// 		ft_printf("NO BOTH!!!\n");
// 		return (0);
// 	}
// 	stack_a = both->sa;
// 	if (!stack_a || !(stack_a->next))
// 		return (0);
// 	stack_a->next->last = NULL;
// 	last = stack_a;
// 	while (last->next)
// 		last = last->next;
// 	last->next = stack_a;
// 	both->sa = stack_a->next;
// 	stack_a->last = last;
// 	stack_a->next = NULL;
// //	if (print)
// 	//	global_count++;
// 	// 	ft_printf("ra\n");
// 	return (1);
// }

// int	rb(t_both *both, int print)
// {
// 	t_stack	*last;
// 	t_stack	*stack_b;
// 	print++;
// 	print--;
// 	if (!both)
// 	{
// 		ft_printf("NO BOTH!!!\n");
// 		return (0);
// 	}
// 	stack_b = both->sb;
// 	if (!stack_b || !(stack_b->next))
// 		return (0);
// 	stack_b->next->last = NULL;
// 	last = stack_b;
// 		while (last->next)
// 		last = last->next;
// 	last->next = stack_b;
// 	both->sb = stack_b->next;
// 	stack_b->last = last;
// 	stack_b->next = NULL;
// //	if (print)
// 	//	global_count++;
// 	// 	ft_printf("rb\n");
// 	return (1);
// }

// int	rr(t_both *both)
// {
// 	int	returns;

// 	if (!both)
// 	{
// 		ft_printf("NO BOTH!!!\n");
// 		return (0);
// 	}
// 	if (!((both->sa && both->sa->next) || (both->sb && both->sb->next)))
// 		return (0);
// 	returns = ra(both, 0);
// 	if (!returns)
// 	{
// 		return(rb(both, 1));
// 	}
// 	returns += rb(both, 0);
// 	//global_count++;
// 	ft_printf("rr\n");
// 	return (returns);
// }
