/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:30:16 by frapp             #+#    #+#             */
/*   Updated: 2023/12/12 23:40:40 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	size_check(char *arg, int len)
{
	if (len < 10)
		return (1);
	if (len > 11)
		return (0);
	if ((*arg != '-' && *arg != '+') && len > 10)
		return (0);
	if (*arg == '-')
	{
		arg++;
		if (ft_strncmp(arg, "2147483648", 10) <= 0)
			return (1);
		return (0);
	}
	if (*arg == '+')
		arg++;
	if (ft_strncmp(arg, "2147483647", 10) <= 0)
		return (1);
	return (0);
}

int	left_overs(t_both *both, char *arg, int nb_c)
{
	int	count;

	count = 0;
	if (nb_c)
	{
		both->sa = append_back(ft_atoi(arg), both);
		if (!(both->sa))
			return (0);
		count++;
	}
	return (count);
}

static int	loop(struct s_charset *d, char **arg, t_both *both)
{
	while ((*arg)[++d->i])
	{
		if (!size_check((*arg), d->i + 1))
			return (-1);
		if (!ft_isdigit((*arg)[d->i]))
		{
			if ((d->sign && !ft_space((*arg)[d->i])) || ((*arg)[d->i]
					!= '+' && (*arg)[d->i] != '-' && !ft_space((*arg)[d->i])))
				return (-1);
			if (d->nb_c)
			{
				both->sa = append_back(ft_atoi((*arg)), both);
				if (!(both->sa))
					return (-1);
				d->count++;
			}
			d->nb_c = 0;
			(*arg) += (d->i);
			d->i = 0;
		}
		else
			d->nb_c++;
		d->sign = ((*arg)[d->i] == '+' || (*arg)[d->i] == '-');
	}
	return (0);
}

static int	check_charset(char *arg, t_both *both)
{
	struct s_charset	d;

	d.nb_c = 0;
	d.sign = 0;
	d.count = 0;
	d.i = -1;
	if (loop(&d, &arg, both) == -1)
		return (-1);
	if (d.nb_c)
	{
		both->sa = append_back(ft_atoi(arg), both);
		if (!(both->sa))
			return (-1);
		d.count++;
	}
	if (d.sign)
		return (-1);
	return (d.count);
}

int	input_validation(int argc, char *argv[], t_both *both)
{
	int		count;
	int		check;
	int		i;

	both->argc = argc - 1;
	both->sa = NULL;
	both->sb = NULL;
	both->size_a = 0;
	both->size_b = 0;
	count = 0;
	if (argc < 2)
		return (0);
	i = 0;
	while (++i < argc)
	{
		check = check_charset(argv[i], both);
		count += check;
		if (check < 0)
			cleanup_error(both, both->both2, 1);
	}
	return (count);
}
