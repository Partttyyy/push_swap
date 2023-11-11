/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:29:48 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 06:28:03 by frapp            ###   ########.fr       */
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
	if(cur->last)
		stack = cur->last;
	else
		stack = cur->next;
	free (cur);
	while (stack && stack->last)
		stack =  stack->last;
	return (stack);
}

void	cleanup(t_both *both)
{
	// free outpput
	if (both->sorted_arr)
		free(both->sorted_arr);
	free_stacks(NULL, both);
}

void	*free_stacks(void *check, t_both *both)
{
	if (check)
		return (check);
	while (both->sa)
		both->sa = del_node(both->sa, (both->sa)->val);
	while (both->sb)
		both->sb = del_node(both->sb, (both->sb)->val);
	both->sa = NULL;
	both->sb = NULL;

	both->sorted_arr = NULL;
	return (NULL);
}

//returns the first node of the stack
// or NULL if malloc failed
t_stack	*append_back(t_stack *stack, int val, t_both *both)
{
	t_stack	*last;

	if (stack == both->sa)
		(both->size_a)++;
	else if(stack == both->sb)
		(both->size_b)++;
	else
		return (0);
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
		return (NULL);
	if (last)
		last->next = stack;
	stack->last = last;
	stack->val = val;
	stack->next = NULL;
	stack->is_fin = 0;
	while (stack->last)
		stack = stack->last;
	return (stack);
}

int	*sort_arr(int *arr, int len)
{
	int	i;
	int	temp;
	int	i2;
	
	i = 0;
	while (arr && i < (len))
	{
		i2 = i;
		while (++i2 < len)
		{
			if (arr[i2] < arr[i])
			{
				temp = arr[i2];
				arr[i2] = arr[i];
				arr[i] = temp;
			}
		}
		i++;
	}
	return (arr);
}

int	*get_sorted_arr(t_both *both)
{
	int		i;
	t_stack	*sa;
	t_stack	*start;

	both->sorted_arr = malloc(sizeof(int) * (both->size_a + both->size_b));
	//ft_printf("size a: %d size b: %d\n", both->size_a, both->size_b);
	if (!both->sorted_arr)
		return (free_stacks(both->sorted_arr, both));
	i = 0;
	sa = both->sa;
	start = sa;
	while (sa)
	{
		both->sorted_arr[i++] = sa->val;
		//ft_printf("%d\n", both->sorted_arr[i - 1]);
		sa = sa->next;
	}
	sort_arr(both->sorted_arr, (both->size_a + both->size_b));
	while (i--)
	{
		sa = start;
		while (sa && sa->val != both->sorted_arr[i])
			sa = sa->next;
		if (sa) // if should be not needed
			sa->index = i;
	}
	return (both->sorted_arr);
}

void	fill_indexes(t_both *both)
{
	int		i;
	t_stack	*node;

	both->total_size = both->size_a + both->size_b;
	i = 0;
	while (i < both->total_size)
	{
		node = both->sa;
		while (node->val != both->sorted_arr[i])
			node = node->next;
		node->index = i;
		i++;
	}
}

