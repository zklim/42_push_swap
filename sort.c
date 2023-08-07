/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 22:44:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cost(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	*content;

	op->biggest = extract_number(stack_b->content);
	op->smallest = extract_number(stack_b->next->content);
	op->big_index = 0;
	if (op->biggest < op->smallest)
	{
		op->biggest = extract_number(stack_b->next->content);
		op->smallest = extract_number(stack_b->content);
		op->big_index = 1;
	}
	content = stack_a->content;
	if (content->number < op->smallest)
	{
		op->cheapest = op->big_index;
		content->rb = op->big_index;
		op->smallest = content->number;
	}
	else
		op->cheapest = 0;
	op->to_push = 0;
}

// void	cost_calculation(t_list *stack_a, t_list *stack_b, t_op *op)
// {
// 	int	i;

// 	i = 0;
// 	while (i < op->cheapest)
// 	{
		
// 		i++;
// 	}
// }

void	run_op(t_list **stack_a, t_list **stack_b, t_content *content)
{
	if (content->ra)
	{
		single_rotate(stack_a, "ra\n");
		content->ra--;
	}
	else if (content->rb)
	{
		single_rotate(stack_b, "rb\n");
		content->rb--;
	}
	else if (content->rr)
	{
		double_rotate(stack_a, stack_b, "rr\n");
		content->rr--;
	}
	else if (content->rra)
	{
		single_reverse_rotate(stack_a, "rra\n");
		content->rra--;
	}
	else if (content->rrb)
	{
		single_reverse_rotate(stack_a, "rrb\n");
		content->rrb--;
	}
	else if (content->rrr)
	{
		double_reverse_rotate(stack_a, stack_b, "rrr\n");
		content->rrr--;
	}
	else
	{
		push(stack_a, stack_b, "pb\n");
		return ;
	}
	run_op(stack_a, stack_b, content);
}

void	push_b(t_list **stack_a, t_list **stack_b, int to_push)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (to_push--)
		tmp = tmp->next;
	run_op(stack_a, stack_b, tmp->content);
}

void	optimised_push(t_list **stack_a, t_list **stack_b)
{
	t_op	op;

	init_cost(*stack_a, *stack_b, &op);
	while (size_of(*stack_a) != 3)
	{
		// cost_calculation(*stack_a, *stack_b, &op);
		push_b(stack_a, stack_b, op.to_push);
	}
}

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
		while (*stack_b)
		{
			search_position(*stack_a, (*stack_b)->content);
			push_back_a(stack_a, stack_b, (*stack_b)->content);
		}
	}
	set_head(stack_a, size);
}
