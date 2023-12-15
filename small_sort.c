/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:35:09 by frapp             #+#    #+#             */
/*   Updated: 2023/12/12 19:46:51 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sa_total(t_both *both, t_stack *sa, int n, int nn)
{
	t_stack	*first;
	t_stack	*second;

	if (sa->index > nn && (n < nn && n < sa->index))
		ra(both, 1);
	else if ((nn < n && nn < sa->index) && sa->index < n)
		rra(both, 1);
	else if (sa->index < nn && sa->index < n && n > nn)
	{
		first = sa;
		second = sa->next;
		first->next = second->next;
		if (second->next)
			second->next->last = first;
		second->next = first;
		second->last = NULL;
		first->last = second;
		both->sa = second;
		add_output(both, "sa");
		ra(both, 1);
	}
	else if (smallup_sa(both, 1))
		three_sa_total(both, both->sa, both->sa->next->index,
			both->sa->next->next->index);
	both->sorted = true;
}

void	sven_sa_total(t_both *both)
{
	int	sub_sizes_b[7];

	sub_sizes_b[0] = 0;
	sub_sizes_b[1] = 0;
	sub_sizes_b[2] = 0;
	while (both->size_a > 3)
	{
		if (both->size_b < 2)
			sub_sizes_b[0]++;
		else
			sub_sizes_b[1]++;
		pb(both);
	}
	smallup_ss(both);
	three_sa_total(both, both->sa, both->sa->next->index,
		both->sa->next->next->index);
	merge_sub_to_a(both, both->size_a, sub_sizes_b, 0);
	if (both->size_b)
	{
		smallup_ss(both);
		merge_sub_to_a(both, both->size_a, sub_sizes_b, 0);
	}
	both->sorted = true;
}

bool	check_small_stacks(t_both *both)
{
	both->sorted = false;
	if (!check_vs_sorted_arr(both))
		both->sorted = true;
	else if (both->size_a == 2)
	{
		smallup_ss(both);
		both->sorted = true;
	}
	else if (both->size_a == 3)
	{
		three_sa_total(both, both->sa, both->sa->next->index,
			both->sa->next->next->index);
	}
	else if (both->size_a <= 7)
		sven_sa_total(both);
	if (both->sorted)
		cleanup_normal(both, both->both2, 1);
	return (both->sorted);
}
