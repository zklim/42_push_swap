/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:05:22 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 16:33:49 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_big_small(t_list *stack, t_op *op)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = stack;
	op->biggest = get_number(stack->content);
	op->big_index = i;
	while (stack)
	{
		if (get_number(stack->content) > op->biggest)
		{
			op->biggest = get_number(stack->content);
			op->big_index = i;
		}
		i++;
		stack = stack->next;
	}
	i = 0;
	op->smallest = get_number(tmp->content);
	while (tmp)
	{
		if (get_number(tmp->content) < op->smallest)
			op->smallest = get_number(tmp->content);
		tmp = tmp->next;
	}
}

void	get_cost_b2(t_content *content, t_list *stack_b)
{
	int			i;
	t_insert	ins;

	i = 0;
	ins.next_small_idx = -1;
	while (stack_b)
	{
		ins.current = get_number(stack_b->content);
		if (ins.current < content->number && 
			(ins.next_small_idx == -1 || ins.current > ins.next_small))
		{
			ins.next_small = ins.current;
			ins.next_small_idx = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	content->rb = ins.next_small_idx;
	content->cost = ins.next_small_idx;
}

int	get_cost_b(t_content *content, t_list *stack_b, t_op *op)
{
	get_big_small(stack_b, op);
	if (content->number < op->smallest)
	{
		content->rb = op->big_index;
		content->cost = op->big_index;
	}
	else
		get_cost_b2(content, stack_b);
	return (content->cost);
}

void	check_double(t_content *content, t_op *op)
{
	while (content->rb && content->ra)
	{
		content->rb--;
		content->ra--;
		content->rr++;
	}
	while (content->rrb && content->rra)
	{
		content->rrb--;
		content->rra--;
		content->rrr++;
	}
	op->cost_1 = content->rb + content->ra + content->rr
		+ content->rrb + content->rra + content->rrr;
}

void	calculate_cost(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	*content_a;

	while ((op->cost_1 < op->cheapest && stack_a) || op->i == 0)
	{
		content_a = stack_a->content;
		content_a->ra = op->i;
		content_a->rr = 0;
		if (op->i == 0)
			op->cheapest = get_cost_b(content_a, stack_b, op);
		else
		{
			op->cost_1 = get_cost_b(content_a, stack_b, op);
			check_double(content_a, op);
			if (op->cost_1 < op->cheapest || op->cheapest == -1)
			{
				op->cheapest = op->cost_1;
				op->to_push = op->i;
			}
		}
		op->i++;
		stack_a = stack_a->next;
	}
}
