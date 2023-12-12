/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:39:58 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:42:30 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// for debugging
void	print_stacks(t_both *both)
{
	t_stack	*node;

	node = both->sa;
	ft_printf("stack a:\n");
	while (node)
	{
		ft_printf("index %d: %d\n", node->index, node->val);
		node = node->next;
	}
	node = both->sb;
	ft_printf("stack b:\n");
	while (node)
	{
		ft_printf("index %d: %d\n", node->index, node->val);
		node = node->next;
	}
}

int	check_vs_sorted_arr(t_both *both)
{
	t_stack	*sa;
	int		return_val;
	int		error ;
	int		i;

	return_val = 0;
	error = 0;
	i = 0;
	sa = both->sa;
	while (sa)
	{
		if (sa->val != both->sorted_arr[i++])
			error++;
		sa = sa->next;
	}
	if (i != both->total_size)
		error++;
	return (error);
}

t_stack	*clone_stack(t_stack *stack)
{
	t_stack	*new_stack;
	t_stack	*new_stack_current;
	t_stack	*new_stack_last;

	new_stack = NULL;
	if (stack)
	{
		new_stack = malloc(sizeof(t_stack));
		if (!new_stack)
			return (0);
		*new_stack = *stack;
	}
	new_stack_current = new_stack;
	while (stack && stack->next)
	{
		stack = stack->next;
		new_stack_last = new_stack_current;
		new_stack_current->next = malloc(sizeof(t_stack));
		if (!new_stack_current)
			return (0);
		new_stack_current = new_stack_current->next;
		*new_stack_current = *stack;
		new_stack_current->last = new_stack_last;
	}
	return (new_stack);
}

int	clone_both(t_both *both, t_both *both_clone)
{
	*both_clone = *both;
	both_clone->output = NULL;
	both_clone->sa = clone_stack(both->sa);
	if (!both_clone->sa && both->sa)
		cleanup_error(both, both_clone, 1);
	both_clone->sb = clone_stack(both->sb);
	if (!both_clone->sb && both->sb)
		cleanup_error(both, both_clone, 1);
	return (1);
}

int	*ft_twoloc(size_t count, size_t size)
{
	int		*arr;
	int		i;
	int		bytes;

	bytes = count * size;
	arr = malloc(bytes * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < bytes)
		arr[i++] = 2;
	arr[i++] = 0;
	return ((void *)arr);
}
