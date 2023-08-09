/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:38:04 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 17:17:03 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_big_small_a(t_list *stack, t_op *op)
{
	t_list		*tmp;
	int			i;

	i = 0;
	tmp = stack;
	op->smallest = get_number(stack->content);
	op->small_index = i;
	while (stack)
	{
		if (get_number(stack->content) < op->smallest)
		{
			op->smallest = get_number(stack->content);
			op->small_index = i;
		}
		i++;
		stack = stack->next;
	}
	i = 0;
	op->biggest = get_number(tmp->content);
	while (tmp)
	{
		if (get_number(tmp->content) > op->biggest)
			op->biggest = get_number(tmp->content);
		tmp = tmp->next;
	}
}

void	get_cost_a2(t_content *content, t_list *stack_a)
{
	int	i;
	int	current;
	int	next_big;
	int	next_big_idx;

	i = 0;
	next_big_idx = -1;
	while (stack_a)
	{
		current = get_number(stack_a->content);
		if (current > content->number && 
			(next_big_idx == -1 || current < next_big))
		{
			next_big = current;
			next_big_idx = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	content->ra = next_big_idx;
	content->cost = next_big_idx;
}

int	get_cost_a(t_content *content, t_list *stack_a, t_op *op)
{
	get_big_small_a(stack_a, op);
	if (content->number > op->biggest)
	{
		content->ra = op->small_index;
		content->cost = op->small_index;
	}
	else
		get_cost_a2(content, stack_a);
	return (content->cost);
}

void	calculate_cost_a(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_content	*content_b;

	while ((op->i < op->cheapest && stack_b) || op->i == 0)
	{
		content_b = stack_b->content;
		content_b->rb = op->i;
		content_b->rr = 0;
		if (op->i == 0)
			op->cheapest = get_cost_a(content_b, stack_a, op);
		else
		{
			op->cost_1 = get_cost_a(content_b, stack_a, op);
			check_double(content_b, op);
			if (op->cost_1 < op->cheapest)
			{
				op->cheapest = op->cost_1;
				op->to_push = op->i;
			}
		}
		op->i++;
		stack_b = stack_b->next;
	}
}
