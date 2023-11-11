/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:45:21 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 20:36:50 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	global_count;

// place holder function
void shove_half_to_b(t_both *both)
{
	while (both->size_b < both->size_a - 1)
		pb(both);
}

// this needs improvments later on when other functions work
int	pair(t_both *both, int *sub_sizes_a, int *sub_sizes_b)
{
	int	size_a = both->size_a;
	int	size_b = both->size_b;
	int	i = 0;
	int	sub_count = 0;
	//if (both->size_b % 2)
	//	rotations++;
	smallup_ss(both);
	while (size_a > 1 && size_b > 1)
	{
		rr(both);
		rr(both);
		smallup_ss(both);
		size_a -= 2;
		size_b -= 2;
		sub_sizes_a[i] = 2;
		sub_sizes_b[i] = 2;
		i++;
		sub_count += 2;
	}
	while (size_a > 1)
	{
		size_a -= 2;
		ra(both, 1);
		ra(both, 1);
		smallup_sa(both, 1);
		sub_sizes_a[i] = 2;
		sub_count++;
		if (size_b)
		{
			size_b--;
			sub_sizes_b[i] = 1;
			sub_count++;
			rb(both, 1);
		}
		i++;
	}
	if (size_b > 1)
	{
		size_b -= 2;
		rb(both, 1);
		rb(both, 1);
		smallup_sb(both, 1);
		sub_sizes_b[i] = 2;
		if (size_a)
		{
			size_a--;
			sub_sizes_a[i] = 1;
			sub_count++;
			ra(both, 1);
		}
		i++;
		sub_count++;
	}
	if (size_a)
	{
		size_a--;
		sub_sizes_a[i] = 1;
		sub_count++;
		ra(both, 1);
	}
	if (size_b)
	{
		size_b--;
		sub_sizes_b[i] = 1;
		sub_count++;
		rb(both, 1);
	}
	return (sub_count);
}

int	merge_sub_to_a(t_both *both, int size_a, int size_b)
{
	int	new_sub_size = size_a + size_b;

	while (size_b)
	{
		if ((both->sa && both->sb) && (both->sa->index < both->sb->index) && size_a > 0)
		{
			ra(both, 1);
			//print_stacks(both);
			size_a--;
		}
		else
		{
			pa(both);
			//print_stacks(both);
			ra(both, 1);
			//print_stacks(both);
			size_b--;
		}
	}
	while (size_a--)
		ra(both, 1);
	return (new_sub_size);
}

int	merge_sub_to_b(t_both *both, int size_a, int size_b)
{
	int	new_sub_size = size_a + size_b;

	while (size_a)
	{
		if ((both->sa && both->sb) && (both->sb->index < both->sa->index) && size_b > 0)
		{
			rb(both, 1);
		//	print_stacks(both);
			size_b--;
		}
		else
		{
			pb(both);
			//print_stacks(both);
			rb(both, 1);
		//	print_stacks(both);
			size_a--;
		}
	}
	while (size_b--)
		rb(both, 1);
	return (new_sub_size);
}

int	check_total_sub_sizes(t_both *both, int *sub_s_a, int *sub_s_b)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (sub_s_a[i])
		sum += sub_s_a[i++];
	i = 0;
	while (sub_s_b[i])
		sum += sub_s_b[i++];
	if (both->total_size != sum)
		return (-(both->total_size - sum));
	return -(both->total_size - sum);
}

/*
TODO:
	does the stack always end up on stack a?
*/
void sort(t_both *both)
{
	int		sub_size;
	int		next_sub_count;
	int		cur_sub_count;
	bool	move_to_a = true;
	int		rest_count;

	int		*sub_sizes_a = ft_calloc(both->total_size, sizeof(int));
	int		*sub_sizes_b = ft_calloc(both->total_size, sizeof(int));

	sub_size = 2;
	next_sub_count = pair(both, sub_sizes_a, sub_sizes_b);
	
	int	sub_index = 0;
	int	new_sub_index = 0;
	int	new_sub_element_size;
	int	count = 0;
	// if (check_total_sub_sizes(both, sub_sizes_a, sub_sizes_b))
	// {
	// 	printf("WRONG SUB_SIZE COUNT: %d!\n", check_total_sub_sizes(both, sub_sizes_a, sub_sizes_b)); return ;
	// }
	// else
	// 	printf("sub size count ok\n");
	while (sub_sizes_a[0] < both->total_size && sub_sizes_b[0] < both->total_size)
	{
		//cur_sub_count = next_sub_count;
		//rest_count = (both->total_size - sub_size * cur_sub_count);
		// if (check_total_sub_sizes(both, sub_sizes_a, sub_sizes_b))
		// {
		// 	printf("WRONG SUB_SIZE COUNT: %d!\n", check_total_sub_sizes(both, sub_sizes_a, sub_sizes_b)); return ;
		// }
		// else
		// 	printf("sub size count ok\n");
		//if (count)
		//	new_sub_index++;
		count = 0;
		while (sub_sizes_a[sub_index] || sub_sizes_b[sub_index])
		{
			new_sub_element_size = sub_sizes_b[sub_index] + sub_sizes_a[sub_index];
			if (move_to_a)
			{
				merge_sub_to_a(both, sub_sizes_a[sub_index], sub_sizes_b[sub_index]);
				sub_sizes_a[sub_index] = 0;
				sub_sizes_b[sub_index++] = 0;
				sub_sizes_a[new_sub_index] = new_sub_element_size; // new
				move_to_a = false;
				count++;
			}
			else
			{
				merge_sub_to_b(both, sub_sizes_a[sub_index], sub_sizes_b[sub_index]);
				sub_sizes_a[sub_index] = 0;
				sub_sizes_b[sub_index++] = 0;
				sub_sizes_b[new_sub_index] = new_sub_element_size; // new
				move_to_a = true;
				count++;
			}
			if (count == 2) // new
			{
				new_sub_index++; // new
				count = 0;
			}
			//cur_sub_count -= 2; // need addidtional logic for cases where 1 or both subs are empty
			//next_sub_count++; // need addidtional logic for when both subs are empty
		}
		//sub_size *= 2;
		new_sub_index = 0; // new
		sub_index = 0; // new
	}
}

t_stack	*cpy_stack(t_stack *s)
{
	t_stack	*new_stack;
	t_stack	*temp;

	if (s)
		new_stack = ft_calloc(1, sizeof(t_stack));
	if (!new_stack)
		return (0);
	
	new_stack->index = s->index;
	while (s->next)
	{
		s = s->next;
		new_stack->next = ft_calloc(1, sizeof(t_stack));
		if (!new_stack->next)
		{
			//handle later
		}
		temp = new_stack;
		new_stack = new_stack->next;
		new_stack->last = temp;
		new_stack->index = s->index;
	}
	return (new_stack);
}


/*
idea:
	simulate the split starting with the perfect split
	if its not a 50/50 loosen requirements until the best is found
	
	for example start by only moving the largest value first to only the
	smalles in the end,
	on next iterations loose those requrements.

	range calculation?

	look over cpy_stack to make sure its good and write free stack function for this
*/
void	good_split(t_both *both)
{
	double	progress;
	double	ideal_positon;
	int		count;
	int		mid = both->total_size / 2;
	t_both	*clone_a;
	t_both	*clone_b;
	
	count = 1;
	while (clone_b < both->sa - 1)
	{
		progress = count / both->total_size;
		//find_next_bad_node(clone_a, range);
	}
}



int	main(int ac, char *av[])
{
	t_both both;
	
	init_both(&both);
	if (!input_validation(ac, av, &both))
	{
		ft_printf("Error\n");
		free_stacks(NULL, &both);
		return (0);
	}
	get_sorted_arr(&both);

	//print_stacks(&both);
	shove_half_to_b(&both);
	sort(&both);
	optimise_output(&both);
	print_output(&both);
	//print_stacks(&both);
	//if (check_vs_sorted_arr(&both))
	//{
	//	printf("not sorted\n");
	//}
	//else
	//	printf("no error\n");
	print_stacks(&both);
	//ft_printf("gloabal count: %d\n", global_count);
	return (0);
}
