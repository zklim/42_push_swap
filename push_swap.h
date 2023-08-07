/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:41:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 09:23:29 by zhlim            ###   ########.fr       */
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
}		t_content;

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
int		extract_index(t_content *content);
int		extract_number(t_content *content);
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

#endif