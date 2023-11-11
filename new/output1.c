/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 05:38:59 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 07:34:34 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_output(t_both *both)
{
	t_output	*cur;

	cur = both->output;
	while (cur)
	{
		ft_printf("%s\n", cur->output);
		cur = cur->next;
	}
}

int	add_output(t_both *both, const char *str)
{
	t_output	*list;

	if (!both->output)
	{
		both->output = ft_calloc(1, sizeof(t_output));
		list = both->output;
	}
	else
	{
		list = both->output;
		while (list->next)
			list = list->next;
		list->next = ft_calloc(1, sizeof(t_output));
		list = list->next;
	}
	if (!list)
	{
		both->exit = 1;
		cleanup(both);
		return (0);
	}
	ft_strlcpy(list->output, str, 4);
	return (1);
}

void	del_output(t_both *both, t_output *to_delete)
{
	if (to_delete->last)
		to_delete->last->next = to_delete->next;
	if (to_delete->next)
		to_delete->next->last = to_delete->last;
	if (both->output == to_delete)
		both->output = to_delete->next;
	free(to_delete);
}

void	optimise_output(t_both *both)
{
	int	change;

	change = 1;
	while (change)
	{
		while (change)
		{
			change = shift_output(both);
		}
		change = cut_down_output1(both);
		change += cut_down_output2(both);
	}
}

int	shift_output(t_both *both)
{
	t_output	*c;
	char		*c_out;
	char		*n_out;
	int			change;

	c = both->output;
	change = 0;
	while (c && c->next)
	{
		c_out = c->output;
		n_out = c->next->output;
		if (!ft_strcmp(c_out, "rr") && (!ft_strcmp(n_out, "ra") || !ft_strcmp(n_out, "rb")))
		{
			ft_strlcpy(c->output, c->next->output, 4);
			ft_strlcpy(c->next->output, "rr", 4);
			change++;
		}
		if (!ft_strcmp(c_out, "rrr") && (!ft_strcmp(n_out, "rra") || !ft_strcmp(n_out, "rrb")))
		{
			ft_strlcpy(c->output, c->next->output, 4);
			ft_strlcpy(c->next->output, "rrr", 4);
			change++;
		}
		c = c->next;
	}
	return (change);
}

int	cut_down_output1(t_both *both)
{
	t_output	*cur;
	int			change;
	t_output	*temp;

	change = 0;
	cur = both->output;
	while (cur && cur->next)
	{
		if ((!ft_strcmp(cur->output, "sa") && !ft_strcmp(cur->next->output, "sb")) ||
		(!ft_strcmp(cur->output, "sb") && !ft_strcmp(cur->next->output, "sa")))
		{
			ft_strlcpy(cur->output, "ss", 4);
			temp = cur->next;
			cur->next = temp->next;
			del_output(both, temp);
			change++;
		}
		else if (((!ft_strcmp(cur->output, "ra")) && (!ft_strcmp(cur->next->output, "rb"))) ||
			((!ft_strcmp(cur->output, "rb")) && (!ft_strcmp(cur->next->output, "ra"))))
		{
			ft_strlcpy(cur->output, "rr", 4);
			temp = cur->next;
			cur->next = temp->next;
			del_output(both, temp);
			change++;
		}
		else if ((!ft_strcmp(cur->output, "rra") && !ft_strcmp(cur->next->output, "rrb")) ||
			(!ft_strcmp(cur->output, "rrb") && !ft_strcmp(cur->next->output, "rra")))
		{
			temp = cur->next;
			cur->next = temp->next;
			del_output(both, temp);
			change++;
		}
		cur = cur->next;
	}
	return (change);
}

int	cut_down_output2(t_both *both)
{
	t_output	*cur;
	t_output	*temp1;
	t_output	*temp2;
	int			change;

	change = 0;
	cur = both->output;
	while (cur && cur->next)
	{		
		if ((!ft_strcmp(cur->output, "pa") && !ft_strcmp(cur->next->output, "pb")) ||
		(!ft_strcmp(cur->output, "pa") && !ft_strcmp(cur->next->output, "pb")))
		{
			temp1 = cur;
			temp2 = cur->next;
			if (cur->last)
				cur = cur->last;
			else
				cur = cur->next->next;
			del_output(both, temp1);
			del_output(both, temp2);
			change++;
			continue ;
		}
		cur = cur->next;
	}
	return (change);
}
