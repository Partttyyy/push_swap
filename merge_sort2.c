/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:24:40 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 04:25:37 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	merge_sub_to_a(t_both *both, int to_rotate_a, int *sub_sizes_b, int sub_b_i)
{
	int	new_sub_gain;

	new_sub_gain = sub_sizes_b[sub_b_i];
	while (sub_sizes_b[sub_b_i])
	{
		if (!both->sa || (both->sb && (both->sb->index
					< both->sa->index || !to_rotate_a)))
		{
			(sub_sizes_b[sub_b_i])--;
			pa(both);
			ra(both, 1);
		}
		else if (to_rotate_a > 0)
		{
			to_rotate_a--;
			ra(both, 1);
		}
	}
	while (to_rotate_a-- > 0)
		ra(both, 1);
	sub_sizes_b[sub_b_i] = 1;
	left_shift_array(sub_sizes_b + sub_b_i);
	return (new_sub_gain);
}

int	merge_sub_to_b(t_both *both, int to_rotate_b, int *sub_sizes_a, int sub_a_i)
{
	int	new_sub_gain;

	new_sub_gain = sub_sizes_a[sub_a_i];
	while (sub_sizes_a[sub_a_i])
	{
		if (!both->sb || (both->sa && (both->sb->index
					> both->sa->index || !to_rotate_b)))
		{
			pb(both);
			rb(both, 1);
			(sub_sizes_a[sub_a_i])--;
		}
		else if (to_rotate_b > 0)
		{
			rb(both, 1);
			to_rotate_b--;
		}
	}
	while (to_rotate_b-- > 0)
		rb(both, 1);
	sub_sizes_a[sub_a_i] = 1;
	left_shift_array(sub_sizes_a + sub_a_i);
	return (new_sub_gain);
}

void	shove_half_to_b(t_both *both)
{
	while (both->size_b < both->size_a - 1)
		pb(both);
}
