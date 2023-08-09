/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 15:24:10 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	set_head(t_list **stack_a, int size)
{
	if (smallest_pos(*stack_a, size))
	{
		while (!check_sorted(*stack_a))
			single_rotate(stack_a, "ra\n");
	}
	else
	{
		while (!check_sorted(*stack_a))
			single_reverse_rotate(stack_a, "rra\n");
	}
}

void	sort_advance(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 4)
	{
		push(stack_a, stack_b, "pb\n");
		sort_3(stack_a);
		search_position(*stack_a, (*stack_b)->content);
		push_back_a(stack_a, stack_b, (*stack_b)->content);
	}
	else
	{
		push(stack_a, stack_b, "pb\n");
		push(stack_a, stack_b, "pb\n");
		optimised_push(stack_a, stack_b);
		sort_3(stack_a);
		print_stack(*stack_a);
		print_stack(*stack_b);	
		while (*stack_b)
		{
			search_position(*stack_a, (*stack_b)->content);
			push_back_a(stack_a, stack_b, (*stack_b)->content);
		}
	}
	set_head(stack_a, size);
}
