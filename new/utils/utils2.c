/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:39:58 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 05:46:09 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>
void	print_stacks(t_both *both)
{
	t_stack	*node;

	node = both->sa;
	printf ("stack a:\n");
	while (node)
	{
		printf("index %d: %d\n", node->index, node->val);
		node = node->next;
	}
	node = both->sb;
	printf ("stack b:\n");
	while (node)
	{
		printf("index %d: %d\n", node->index, node->val);
		node = node->next;
	}
}

int	check_missing_val(t_both *both)
{
	t_stack	*node;
	int found = 0;
	int	error = 0;

	for (int i = 0; i < both->argc; i++)
	{
		node = both->sa;
		found = 0;
		while (node && !found)
		{
			if (node->val == both->sorted_arr[i])
				found = 1;
			node = node->next;
		}
		node = both->sb;
		while (node && !found)
		{
			if (node->val == both->sorted_arr[i])
				found = 1;
			node = node->next;
		}
		if (!found)
		{
			ft_printf("VAL NOT FOUND: %d!\n", both->sorted_arr[i]);
			error++;
		}
	}
	if (!error)
		ft_printf("no value missing\n");
	return (error);
}

int	check_vs_sorted_arr(t_both *both)
{
	t_stack	*sa;
	int	return_val = 0;
	int error = 0;
	int	unique_errors = 0;

	sa = both->sa;

	int i = 0;
	while (sa)
	{
		if (sa->val != both->sorted_arr[i++])
			error++;
		sa = sa->next;
	}
	if (i != both->total_size)
		error++;
	// for (int i = 0; i < both->argc; i++)
	// {
	// 	// if (both->sorted_arr[i] != sa->val)
	// 	// {
	// 	// 	if (!error && sa->last)
	// 	// 	{
	// 	// 		ft_printf("index before ERROR: ar.index %d: %d; list: %d\n", i, both->sorted_arr[i - 1], sa->last->val);
	// 	// 	}
	// 	// 	if (!error && !sa->last)
	// 	// 	{
	// 	// 		ft_printf("ERROR at first node\n");
	// 	// 		ft_printf ("error ar.index %d: %d; list: %d\n", i, both->sorted_arr[i], sa->val);
	// 	// 	}
	// 	// 	return_val++;
	// 	// 	if (!error)
	// 	// 		unique_errors++;
	// 	// 	error++;
	// 	// }
	// 	// else
	// 	// {
	// 	// 	if (error)
	// 	// 		ft_printf("vals after error: ar.index %d: %d; list: %d\n", i, both->sorted_arr[i], sa->val);
	// 	// 	error = 0;
	// 	// }
	// 	sa = sa->next;
	// }
	// if (!return_val)
	// 	ft_printf("No errors :)\n");
	// if (return_val)
	// 	ft_printf("total wrong %d\ntotal unique errors: %d\n", return_val, unique_errors);
	return (error);
}

void	init_both(t_both *both)
{
	both->sa = NULL;
	both->sb = NULL;
	both->size_a = 0;
	both->size_b = 0;
	both->total_size = 0;
	both->sorted_arr = NULL;
	both->exit = 0;
	both->output = NULL;
}
