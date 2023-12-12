/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:30:16 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 06:41:05 by frapp            ###   ########.fr       */
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

static int	check_charset(char *arg, t_both *both)
{
	int		i;
	int		was_sign;
	int		count;
	int		nb_c;

	nb_c = 0;
	was_sign = 0;
	count = 0;
	i = -1;
	while (arg[++i])
	{
		if (!size_check(arg, i + 1))
			return (0);
		if (!ft_isdigit(arg[i]))
		{
			if (was_sign && !ft_iswhitespace(arg[i]))
				return (0);
			if (arg[i] != '+' && arg[i] != '-' && !ft_iswhitespace(arg[i]))
				return (0);
			if (nb_c)
			{
				both->sa = append_back(ft_atoi(arg), both);
				if (!(both->sa))
					return (-1);
				count++;
			}
			nb_c = 0;
			arg += (i);
			i = 0;
		}
		else
			nb_c++;
		was_sign = (arg[i] == '+' || arg[i] == '-');
	}
	if (nb_c)
	{
		both->sa = append_back(ft_atoi(arg), both);
		if (!(both->sa))
			return (0);
		count++;
	}
	if (was_sign)
		return (0);
	return (count);
}

// argc == 1 is invalid new line -> done
// any non space + - or number is invalid -> done
// empty strings are invalid -->done
// + or - followed by a non digit is invalid ->done
// numbers < INT_MIN or > INT_MAX are invalid -> done
// duplicate numbers are invalid -> done in utils 1 append back
// empty arugement string is invalid -> done

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
		if (check == -1)
			cleanup_error(both, both->both2, 1);
		if (!check)
			cleanup_error(both, both->both2, 1);
	}
	return (count);
}
