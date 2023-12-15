/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 05:38:36 by frapp             #+#    #+#             */
/*   Updated: 2023/12/14 22:08:39 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <stdbool.h>

typedef struct s_stack	t_stack;
typedef struct s_both	t_both;
typedef struct s_ouput	t_output;

struct	s_stack
{
	int		val;
	t_stack	*next;
	t_stack	*last;
	int		index;
};

struct	s_charset
{
	int		i;
	bool	sign;
	int		count;
	int		nb_c;
};

typedef struct s_ouput
{
	char		output[5];
	t_output	*last;
	t_output	*next;
}	t_output;

struct	s_both
{
	int			argc;
	t_stack		*sa;
	t_stack		*sb;
	int			size_a;
	int			size_b;
	int			total_size;
	int			a_i;
	int			b_i;
	int			*sorted_arr;
	int			*sub_sizes_a;
	int			*sub_sizes_b;
	t_both		*both2;
	t_output	*output;
	bool		sorted;
};

int		input_validation(int argc, char *argv[], t_both *both);

// main sort
bool	merge_sort(t_both *both, bool move_to_a);
int		merge_sub_to_a(t_both *both,
			int to_rotate_a, int *sub_sizes_b, int sub_b_i);
int		merge_sub_to_b(t_both *both,
			int to_rotate_b, int *sub_sizes_a, int sub_a_i);
void	pair(t_both *both, int s_a, int s_b, int diff);

// utils_sorting
void	shove_half_to_b(t_both *both);
void	left_shift_array(int *arr);

// small_sort
bool	check_small_stacks(t_both *both);

// output
int		add_output(t_both *both, const char *str);
void	del_output(t_both *both, t_output *to_delete);
int		cut_down_output_pushes(t_both *both);
void	print_output(t_both *both);

void	optimise_output(t_both *both);
int		shift_output(t_both *both);
int		cut_down_output_pushes(t_both *both);
int		combine_outputs(t_both *both);

// utils1
void	*del_node(t_stack *stack, int val);
t_stack	*append_back(int val, t_both *both);

// utils2
void	print_stacks(t_both *both);
int		check_vs_sorted_arr(t_both *both);
t_stack	*clone_stack(t_stack *stack);
int		clone_both(t_both *both, t_both *both_clone);
int		*ft_twoloc(size_t count, size_t size);

// utils_exit
void	*free_stacks(void *check, t_both *both);
void	cleanup_error(t_both *both1, t_both *both2, bool print);
void	cleanup_normal(t_both *both1, t_both *both2, bool print);
void	del_all_output(t_both *both);

// utils_init
int		*sort_arr(int *arr, int len);
int		*get_sorted_arr(t_both *both);
void	fill_indexes(t_both *both);
void	init_both(t_both *both);

// custom instructions for merge
int		smallup_sa(t_both *both, int print);
int		smallup_sb(t_both *both, int print);
int		smallup_ss(t_both *both);
int		smlup_ss(t_both *both);

// instructions
int		sa(t_both *both, int print);
int		sb(t_both *both, int print);
//int	ss(t_both *both);
int		pa(t_both *both);
int		pb(t_both *both);
int		ra(t_both *both, int print);
int		rb(t_both *both, int print);
int		rr(t_both *both);
int		rra(t_both *both, int print);
int		rrb(t_both *both, int print);
int		rrr(t_both *both);

#endif
