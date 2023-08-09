/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rev_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 19:33:30 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 01:41:47 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*reverse_list(t_list *stack)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = stack;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}

void	get_revcost_b2(t_content *content, t_list *stack_b)
{
	int	i;
	int	current;
	int	next_small;
	int	next_small_idx;

	i = 0;
	next_small_idx = -1;
	while (stack_b)
	{
		current = get_number(stack_b->content);
		if (current < content->number && 
			(next_small_idx == -1 || current > next_small))
		{
			next_small = current;
			next_small_idx = i;
		}
		i++;
		stack_b = stack_b->next;
	}
	content->rrb = next_small_idx;
	content->cost = next_small_idx;
}

int	get_revcost_b(t_content *content, t_list *stack_b, t_op *op)
{
	get_big_small_b(stack_b, op);
	if (content->number < op->smallest)
	{
		content->rrb = op->big_index;
		content->cost = op->big_index;
	}
	else
		get_revcost_b2(content, stack_b);
	return (content->cost);
}

void	do_nothing(t_content *content)
{
	return ;
}

void	calculate_rev_b(t_list *stack_a, t_list *stack_b, t_op *op)
{
	t_list		*rev_a;
	t_content	*content_a;

	rev_a = ft_lstmap(stack_a, do_nothing, destroy_content);
	rev_a = reverse_list(rev_a);
	op->i = 1;
	while (op->i < op->cheapest && rev_a)
	{
		content_a = rev_a->content;
		content_a->rra = op->i;
		content_a->rrr = 0;
		op->cost = get_revcost_b(content_a, stack_b, op);
		check_double(content_a, op);
		if (op->cost < op->cheapest)
		{
			op->cheapest = op->cost;
			op->to_push = op->i;
		}
		op->i++;
		rev_a = rev_a->next;
	}
}
