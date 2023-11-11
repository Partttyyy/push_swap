/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pathfinding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:57:54 by frapp             #+#    #+#             */
/*   Updated: 2023/11/06 20:22:30 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf.h"

int	factorial(int count)
{
	if (count == 0)
		return (1);
	return (count * factorial(count - 1));
}

t_pf	intit_pf(t_both *both, int count, t_stack *stack)
{
	int		*all_digits;
	t_pf	*pf;

	pf = malloc(sizeof(t_pf));
	pf->count = count;
	pf->all_digits = malloc(sizeof(int) * count);
	pf->nodes = ft_calloc(factorial(count) , sizeof(t_node));
	pf->main_s = stack;
	if (stack == both->sa)
		pf->second_s = both->sb;
	else if (stack == both->sb)
		pf->
}

// caller has to handle count; if count is too big it takes forever
// or if count is bigger than stack size its gonna seg fault
void	main_finding(t_both *both, t_stack *stack, int count)
{
	t_pf	*pf;

	pf = intit_pf(both, count);
}
