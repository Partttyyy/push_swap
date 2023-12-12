/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:30:46 by frapp             #+#    #+#             */
/*   Updated: 2023/12/10 18:17:40 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	run_instruction(char *instruction, t_both *both)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa_bonus(both);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb_bonus(both);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss_bonus(both);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa_bonus(both);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb_bonus(both);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra_bonus(both);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb_bonus(both);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr_bonus(both);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra_bonus(both);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb_bonus(both);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr_bonus(both);
	else
		return (false);
	return (true);
}

bool	check_char(int i, char *buffer)
{
	buffer[i + 1] = 0;
	if (i > 3 || !(((i == 0 && (buffer[i] == 's'
						|| buffer[i] == 'p'
						|| buffer[i] == 'r'))
				|| ((i == 3 || i == 2) && buffer[i] == '\n'))
			|| (i == 1 && (buffer[i] == 'a'
					|| buffer[i] == 'b'
					|| buffer[i] == 's'
					|| buffer[i] == 'r'))
			|| (i == 2 && (buffer[i] == '\n'
					|| buffer[i] == 'r'
					|| buffer[i] == 'a'
					|| buffer[i] == 'b'))))
	{
		ft_printf("KO\n");
		return (true);
	}
	return (false);
}

void	read_input(t_both *both)
{
	char	buffer[10];
	int		i;

	i = 0;
	while (1)
	{
		while (read(0, buffer + i, 1) > 0)
		{
			if (check_char(i++, buffer))
				cleanup_normal(both, both->both2, 0);
			if (run_instruction(buffer, both))
				i = 0;
		}
		if (i == 0)
		{
			if (check_vs_sorted_arr(both))
				ft_printf("KO\n");
			else
				ft_printf("OK\n");
			cleanup_normal(both, both->both2, 0);
		}
		ft_printf("KO\n");
		cleanup_normal(both, both->both2, 0);
	}
}

int	main(int ac, char *av[])
{
	t_both	both;
	t_both	both2;

	if (ac == 1)
		return (0);
	init_both(&both);
	init_both(&both2);
	both.both2 = &both2;
	both2.both2 = &both;
	input_validation(ac, av, &both);
	get_sorted_arr(&both);
	read_input(&both);
	return (0);
}
