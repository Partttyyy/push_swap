/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:56:15 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 00:45:55 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_output(t_both *both)
{
	t_output	*c;
	int			change;

	c = both->output;
	change = 0;
	while (c && c->next)
	{
		if (!ft_strcmp(c->output, "rr") && (!ft_strcmp(c->next->output, "ra")
				|| !ft_strcmp(c->next->output, "rb")))
		{
			ft_strcpy(c->output, c->next->output);
			ft_strcpy(c->next->output, "rr");
			change++;
		}
		if (!ft_strcmp(c->output, "rrr") && (!ft_strcmp(c->next->output, "rra")
				|| !ft_strcmp(c->next->output, "rrb")))
		{
			ft_strcpy(c->output, c->next->output);
			ft_strcpy(c->next->output, "rrr");
			change++;
		}
		c = c->next;
	}
	return (change);
}

void	combine_outputs2(t_both *both, t_output	*cu, int *diff, t_output *temp)
{
	if ((!ft_strcmp(cu->output, "ra") && !ft_strcmp(cu->next->output, "rb"))
		| (!ft_strcmp(cu->output, "rb") && !ft_strcmp(cu->next->output, "ra")))
	{
		ft_strlcpy(cu->output, "rr", 4);
		cu->next = temp->next;
		del_output(both, temp);
		(*diff)++;
	}
	if ((!ft_strcmp(cu->output, "rra") && !ft_strcmp(cu->next->output, "rrb"))
		|| (!ft_strcmp(cu->output, "rrb")
			&& !ft_strcmp(cu->next->output, "rra")))
	{
		cu->next = temp->next;
		del_output(both, temp);
		(*diff)++;
	}
	if ((!ft_strcmp(cu->output, "sa") && !ft_strcmp(cu->next->output, "sb"))
		|| (!ft_strcmp(cu->output, "sb")
			&& !ft_strcmp(cu->next->output, "sa")))
	{
		ft_strlcpy(cu->output, "ss", 4);
		cu->next = temp->next;
		del_output(both, temp);
		(*diff)++;
	}
}

int	combine_outputs(t_both *both)
{
	t_output	*cur;
	int			diff;
	t_output	*temp;

	diff = 0;
	cur = both->output;
	while (cur && cur->next)
	{
		temp = cur->next;
		combine_outputs2(both, cur, &diff, temp);
		cur = cur->next;
	}
	return (diff);
}

int	cut_down_output_pushes(t_both *both)
{
	t_output	*cur;
	t_output	*temp;
	int			diff;

	diff = 0;
	cur = both->output;
	while (cur && cur->next)
	{
		if ((!ft_strcmp(cur->output, "pa") && !ft_strcmp
				(cur->next->output, "pb")) || (!ft_strcmp
				(cur->output, "pa") && !ft_strcmp(cur->next->output, "pb")))
		{
			if (cur->last)
				temp = cur->last;
			else
				temp = cur->next->next;
			del_output(both, cur->next);
			del_output(both, cur);
			cur = temp;
			diff++;
		}
		else
			cur = cur->next;
	}
	return (diff);
}
