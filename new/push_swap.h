/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frapp <frapp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 05:38:36 by frapp             #+#    #+#             */
/*   Updated: 2023/11/08 07:03:21 by frapp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

extern int	global_count;

#include "./libft/libft.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct s_stack	t_stack;
typedef struct s_both	t_both;
typedef struct s_ouput	t_output;

struct	s_stack
{
	int		val;
	t_stack	*next;
	t_stack	*last;
	int		is_fin;
	int		index;
};

typedef struct s_ouput
{
	char		output[4];
	t_output	*last;
	t_output	*next;
} t_output;


struct	s_both
{
	int			argc;
	t_stack		*sa;
	t_stack		*sb;
	int			size_a;
	int			size_b;
	int			total_size;
	int			a_min;
	int			a_min_index;
	int			b_max;
	int			*sorted_arr;
	int			*sub_sort_arr;
	int			*unsorted_arr;
	int			current_iter;
	t_output	*output;
	int			exit;
};

// instructions
int	sa(t_both *both, int print);
int	sb(t_both *both, int print);
//int	ss(t_both *both);
int	pa(t_both *both);
int	pb(t_both *both);
int	ra(t_both *both, int print);
int	rb(t_both *both, int print);
int	rr(t_both *both);
int	rra(t_both *both, int print);
int	rrb(t_both *both, int print);
int	rrr(t_both *both);

// my rules
int	a_small(t_both *both);
int	good_ss(t_both *both);
int	check_potential_pb_ss(t_both *both, int pivot);
int	good_a_small(t_both *both);
int check_potential_pa_ss(t_both *both, int pivot);

// sort utils
int	is_sorted (t_stack *sa, t_stack *sb, int l_a, int l_b);
int	pivot_in_stack(t_stack *s, int pivot, int cmp);
int	update_size_a(t_both *both);
int	set_fin_nodes(t_both *both);

// main
int		main(int argc, char *argv[]);
int		main_loop(t_both *both);

// utils
void	*del_node(t_stack *stack, int val);
void	*free_stacks(void *check, t_both *both);
t_stack	*append_back(t_stack *stack, int val, t_both *both);
int		input_validation(int argc, char *argv[], t_both *both);
int		*sort_arr(int *arr, int len);
int		*get_sorted_arr(t_both *both);
void	fill_indexes(t_both *both);
void	cleanup(t_both *both);

// utils2; debugging + testing
void	print_stacks(t_both *both);
int		check_missing_val(t_both *both);
int		check_vs_sorted_arr(t_both *both);
void	init_both(t_both *both);

// output
int		add_output(t_both *both, const char *str);
void	del_output(t_both *both, t_output *to_delete);

void	print_output(t_both *both);

void	optimise_output(t_both *both);
int		cut_down_output1(t_both *both);
int		shift_output(t_both *both);
int		cut_down_output2(t_both *both);

// custom instructions for merge
int		smallup_sa(t_both *both, int print);
int		smallup_sb(t_both *both, int print);
int		smallup_ss(t_both *both);

// debug
void	log_error(char *type, char *msg);

#endif
