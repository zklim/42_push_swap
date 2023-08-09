/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:04:21 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 11:25:14 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cost(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	*content;

	op->biggest = get_number(stack_b->content);
	op->smallest = get_number(stack_b->next->content);
	op->big_index = 0;
	if (op->biggest < op->smallest)
	{
		op->biggest = get_number(stack_b->next->content);
		op->smallest = get_number(stack_b->content);
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

void	run_op(t_list **stack_a, t_list **stack_b, t_content *content, char c)
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
	else if (c == 'a')
	{
		push(stack_b, stack_a, "pa\n");
		return ;
	}
	else if (c == 'b')
	{
		push(stack_a, stack_b, "pb\n");
		return ;
	}
	else
		return ;
	run_op(stack_a, stack_b, content, c);
}

void	to_push(t_list **stack_a, t_list **stack_b, int index, char c)
{
	t_list	*tmp;

	if (c == 'a')
		tmp = *stack_b;
	else if (c == 'b')
		tmp = *stack_a;
	while (index--)
		tmp = tmp->next;
	run_op(stack_a, stack_b, tmp->content, c);
}

void	optimised_push(t_list **stack_a, t_list **stack_b)
{
	t_op	op;

	init_cost(*stack_a, *stack_b, &op);
	to_push(stack_a, stack_b, op.to_push, 'b');
	while (size_of(*stack_a) != 3)
	{
		op.size_b = size_of(*stack_b);
		calculate_cost(*stack_a, *stack_b, &op);
		to_push(stack_a, stack_b, op.to_push, 'b');
		print_stack(*stack_a);
		print_stack(*stack_b);
	}
}