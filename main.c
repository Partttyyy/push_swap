/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:45:21 by frapp             #+#    #+#             */
/*   Updated: 2023/12/15 07:49:15 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//write(1, "\n", 1);
int	main2(int ac, char *av[])
{
	t_both	both;
	t_both	both2;

	if (ac == 2 && !av[1][0])
		return (0);
	init_both(&both);
	init_both(&both2);
	both.both2 = &both2;
	both2.both2 = &both;
	input_validation(ac, av, &both);
	get_sorted_arr(&both);
	if (!check_vs_sorted_arr(&both))
		return (cleanup_normal(&both, &both2, 0), 0);
	clone_both(&both, &both2);
	check_small_stacks(&both);
	shove_half_to_b(&both);
	merge_sort(&both, true);
	if (!check_vs_sorted_arr(&both))
		cleanup_normal(&both, &both2, 1);
	shove_half_to_b(&both2);
	merge_sort(&both2, false);
	cleanup_normal(&both2, &both, 1);
	return (0);
}

//system("leaks push_swap");
int	main(int ac, char *av[])
{
	main2(ac, av);
	return (0);
}
