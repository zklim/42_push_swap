/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 12:05:57 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_b(t_list *stack_a, t_list *stack_b)
{
	t_content	*content_a;
	t_content	*content_b;
	int			diff;

	content_a = stack_a->content;
	content_b = stack_b->content;
	while (stack_b)
	{
		diff = content_a->number - content_b->number;
		if (stack_b->next)
		{
			content_b = stack_b->next->content;
			if (diff > content_a->number - content_b->number)
			{
				content_a->rb++;
				content_a->cost++;
			}
		}
		stack_b = stack_b->next;
	}
}

void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	t_content	*content;

	while (stack_a)
	{
		loop_b(stack_a, stack_b);
		stack_a = stack_a->next;
		content = stack_a->content;
		content->ra++;
		content->cost++;
	}

}

void	optimised_push(t_list **stack_a, t_list **stack_b)
{
	while (size_of(*stack_a) != 3)
	{
		calculate_cost(*stack_a, *stack_b);
	}
}

void	set_head(t_list **stack_a, int size)
{
	while (!check_sorted(*stack_a))
	{
		if (smallest_pos(*stack_a, size))
			single_rotate(stack_a, "ra\n");
		else
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
		while (*stack_b)
		{
			search_position(*stack_a, (*stack_b)->content);
			push_back_a(stack_a, stack_b, (*stack_b)->content);
		}
	}
	set_head(stack_a, size);
}
