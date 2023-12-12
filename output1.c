/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:38:59 by frapp             #+#    #+#             */
/*   Updated: 2023/12/10 17:45:17 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_output(t_both *both)
{
	t_output	*cur;

	cur = both->output;
	while (cur)
	{
		ft_fprintf(1, "%s\n", cur->output);
		cur = cur->next;
	}
}

int	add_output(t_both *both, const char *str)
{
	t_output	*list;

	if (!both->output)
	{
		both->output = ft_calloc(1, sizeof(t_output));
		if (!both->output)
			cleanup_error(both, both->both2, 1);
		list = both->output;
	}
	else
	{
		list = both->output;
		while (list->next)
			list = list->next;
		list->next = ft_calloc(1, sizeof(t_output));
		if (!list->next)
			cleanup_error(both, both->both2, 1);
		list = list->next;
	}
	if (!list)
		return (0);
	ft_strcpy(list->output, str);
	return (1);
}

void	del_output(t_both *both, t_output *node)
{
	t_output	*current;

	current = both->output;
	while (current != node && current)
		current = current->next;
	if (current == NULL)
		return ;
	if (node->last != NULL)
		node->last->next = node->next;
	else
		both->output = node->next;
	if (node->next != NULL)
		node->next->last = node->last;
	free(node);
}

void	del_all_output(t_both *both)
{
	while (both->output)
	{
		del_output(both, both->output);
	}
	both->output = NULL;
}

void	optimise_output(t_both *both)
{
	int	diff;

	diff = 1;
	while (diff)
	{
		while (diff)
		{
			diff = shift_output(both);
		}
		diff = combine_outputs(both);
		diff += cut_down_output_pushes(both);
	}
}
