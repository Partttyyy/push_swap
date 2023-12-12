/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:28:39 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:41:53 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_both(t_both *both)
{
	both->sa = NULL;
	both->sb = NULL;
	both->size_a = 0;
	both->size_b = 0;
	both->total_size = 0;
	both->sorted_arr = NULL;
	both->output = NULL;
	both->a_i = 0;
	both->b_i = 0;
	both->sub_sizes_a = NULL;
	both->sub_sizes_b = NULL;
	both->both2 = NULL;
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
	if (!both->sorted_arr)
		cleanup_error(both, both->both2, 1);
	i = 0;
	sa = both->sa;
	start = sa;
	while (sa)
	{
		both->sorted_arr[i++] = sa->val;
		sa = sa->next;
	}
	sort_arr(both->sorted_arr, (both->size_a + both->size_b));
	while (i--)
	{
		sa = start;
		while (sa && sa->val != both->sorted_arr[i])
			sa = sa->next;
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
