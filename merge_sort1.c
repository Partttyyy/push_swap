/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:24:25 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:44:47 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sss(t_both *both)
{
	smallup_ss(both);
	return (1);
}

void	pair(t_both *both, int s_a, int s_b, int dif)
{
	while (s_b - dif > 1 && ++both->a_i && ++both->b_i
		&& (sss(both) | rr(both) | rr(both)))
		dif += 2;
	if (s_a - dif > 0)
	{
		both->sub_sizes_a[(both->a_i)++] = s_a-- - dif;
		if (s_a - dif && (smallup_sa(both, 1) | ra(both, 1)))
		{
		}
		ra(both, 1);
	}
	if (s_b - dif > 0)
	{
		both->sub_sizes_b[both->b_i++] = s_b-- - dif;
		if (s_b - dif)
		{
			smallup_sb(both, 1);
			rb(both, 1);
		}
		rb(both, 1);
	}
	both->sub_sizes_a[both->a_i] = 0;
	both->sub_sizes_b[both->b_i] = 0;
	both->a_i = 0;
	both->b_i = 0;
}

bool	merge_sort(t_both *both, bool move_to_a)
{
	both->sub_sizes_a = ft_twoloc(both->total_size, sizeof(int));
	both->sub_sizes_b = ft_twoloc(both->total_size, sizeof(int));
	if (!both->sub_sizes_b || !both->sub_sizes_a)
		cleanup_error(both, both->both2, 1);
	pair(both, both->size_a, both->size_b, 0);
	while (both->size_a != both->total_size)
	{
		if (move_to_a)
			both->sub_sizes_a[both->a_i] += merge_sub_to_a(both,
					both->sub_sizes_a[both->a_i], both->sub_sizes_b, both->b_i);
		else
			both->sub_sizes_b[both->b_i] += merge_sub_to_b(both,
					both->sub_sizes_b[both->b_i], both->sub_sizes_a, both->a_i);
		both->a_i += move_to_a;
		move_to_a = !move_to_a;
		both->b_i += move_to_a;
		if (!both->sub_sizes_a[both->a_i])
			both->a_i = 0;
		if (!both->sub_sizes_b[both->b_i])
			both->b_i = 0;
	}
	return (true);
}
