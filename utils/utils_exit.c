/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:20:12 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 09:34:44 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	leak_check(void)
{
//	system("leaks push_swap");
	exit(0);
}

void	cleanup_error(t_both *both1, t_both *both2, bool print)
{
	if (both1->sorted_arr)
		free(both1->sorted_arr);
	both1->sorted_arr = NULL;
	both2->sorted_arr = NULL;
	del_all_output(both1);
	del_all_output(both2);
	free_stacks(NULL, both1);
	free_stacks(NULL, both2);
	if (print)
		ft_fprintf(2, "Error\n");
	leak_check();
}

void	cleanup_normal(t_both *both1, t_both *both2, bool print)
{
	if (print)
	{
		//optimise_output(&both1);
		print_output(both1);
	}
	if (both1->sorted_arr)
		free(both1->sorted_arr);
	both1->sorted_arr = NULL;
	both2->sorted_arr = NULL;
	del_all_output(both1);
	del_all_output(both2);
	free_stacks(NULL, both1);
	free_stacks(NULL, both2);

	leak_check();
}

void	*free_stacks(void *check, t_both *both)
{
	if (check)
		return (check);
	
	while (both->sa)
		both->sa = del_node(both->sa, (both->sa)->val);
	while (both->sb)
		both->sb = del_node(both->sb, (both->sb)->val);
	both->sa = NULL;
	both->sb = NULL;
	return (NULL);
}
