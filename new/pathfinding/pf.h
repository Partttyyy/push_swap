/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:09:05 by frapp             #+#    #+#             */
/*   Updated: 2023/11/06 20:20:51 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

typedef struct s_node
{
	int		total_dist;
	t_node	*others;
} t_node;

typedef struct s_pf
{
	t_node	*nodes;
	int		*all_digits;
	int		count;
	t_stack	*main_s;
	t_stack	*second_s;
} t_pf;