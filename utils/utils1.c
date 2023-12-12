/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:29:48 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:42:08 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// frees takes a any node of a stack. frees the node with val
// returns the head
void	*del_node(t_stack *stack, int val)
{
	t_stack	*cur;

	cur = stack;
	while (cur->last)
		stack = stack->last;
	while (cur->val != val)
		cur = cur->next;
	if (cur->last)
		(cur->last)->next = cur->next;
	if (cur->next)
		(cur->next)->last = cur->last;
	if (cur->last)
		stack = cur->last;
	else
		stack = cur->next;
	free (cur);
	while (stack && stack->last)
		stack = stack->last;
	return (stack);
}

t_stack	*append_back(int val, t_both *both)
{
	t_stack	*last;
	t_stack	*stack;

	(both->size_a)++;
	stack = both->sa;
	(both->total_size)++;
	last = stack;
	while (stack)
	{
		if (stack->val == val)
			return (free_stacks(NULL, both));
		last = stack;
		stack = stack->next;
	}
	stack = ft_calloc(1, sizeof(t_stack));
	if (!free_stacks(stack, both))
		cleanup_error(both, both->both2, 1);
	if (last)
		last->next = stack;
	stack->last = last;
	stack->val = val;
	stack->next = NULL;
	while (stack->last)
		stack = stack->last;
	return (stack);
}
