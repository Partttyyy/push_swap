/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:25:23 by frapp             #+#    #+#             */
/*   Updated: 2023/12/08 04:25:33 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	left_shift_array(int *arr)
{
	int	i;

	i = 0;
	if (arr == NULL || arr[0] == 0)
	{
		return ;
	}
	while (arr[i] != 0 && arr[i + 1] != 0)
	{
		arr[i] = arr[i + 1];
		i++;
	}
	arr[i] = 0;
}
