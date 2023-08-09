/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:41:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 11:15:30 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/include/ft_printf.h"
# include "libft/libft.h"

typedef struct s_content
{
	int	index;
	int	number;
	int	pos;
	int	diff;
	int	smallest;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int rrr;
	int	cost;
	int	push_b;
}		t_content;

typedef struct s_op
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp_a;
	t_list	*tmp_b;
	int	to_push;
	int	biggest;
	int	smallest;
	int	big_index;
	int	i;
	int	cost_1;
	int	cost_2;
	int	size_a;
	int	size_b;
	int	cheapest;
}		t_op;

typedef struct s_insert
{
	int	current;
	int	next_small;
	int	next_small_idx;
}		t_insert;

char	**validate_args(int ac, char **av);
void	destroy_content(void *content);
t_list	*build_stack_a(char **args);
void	print_error_exit(char *str);
void	free_error_exit(char *str, t_list *stack);
void	check_dup(t_list *stack);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	single_swap(t_list **stack, char *str);
void	double_swap(t_list **stack_a, t_list **stack_b, char *str);
void	single_rotate(t_list **stack, char *str);
void	double_rotate(t_list **stack_a, t_list **stack_b, char *str);
void	single_reverse_rotate(t_list **stack, char *str);
void	double_reverse_rotate(t_list **stack_a, t_list **stack_b, char *str);
void	push(t_list **stack_pop, t_list **stack_push, char *str);
int		get_index(t_content *content);
int		get_number(t_content *content);
void	sort_negative(t_list **stack_a, t_list **stack_b, int size, int bit);
void	sort_positive(t_list **stack_a, t_list **stack_b, int size, int bit);
int		has_negative(t_list **stack_a);
void	push_back(t_list **stack_a, t_list **stack_b);
int		check_sorted(t_list *stack_a);
void	free_args(char **args);
void	free_exit(t_list *stack);
void	print_stack(t_list *stack);
void	sort_advance(t_list **stack_a, t_list **stack_b, int size);
void	sort_3(t_list **stack_a);
int		size_of(t_list *stack);
void	search_smallest(t_list *tmp, t_content *content);
void	search_position(t_list *stack, t_content *content);
void	push_back_a(t_list **stack_a, t_list **stack_b, t_content *content);
int		smallest_pos(t_list *stack_a, int size);
void	calculate_cost(t_list *stack_a, t_list *stack_b, t_op *op);
void	optimised_push(t_list **stack_a, t_list **stack_b);

#endif