/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 18:17:46 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	loop_half(t_content *content, t_list *stack_b, int loops)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = content->number;
	while (i < loops)
	{
		b = extract_number(stack_b->content);
		content->diff = a - b;
		if (stack_b->next && content->diff > a - extract_number(stack_b->next->content))
			content->rb = i;
		stack_b = stack_b->next;
		i++;
	}
}

void	loop_second_half(t_content *content, t_list *stack_b, int size, int loops)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = content->number;
	while (i++ < loops)
		stack_b = stack_b->next;
	while (loops < size)
	{
		b = extract_number(stack_b->content);
		content->diff = a - b;
		if (stack_b->next && content->diff > a - extract_number(stack_b->next->content))
			content->rrb = i - 1;
		i--;
		loops++;
	}
}

void	loop_half_rev(t_content *content, t_list *stack_b, int loops)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = content->number;
	while (i < loops)
	{
		b = extract_number(stack_b->content);
		content->diff = a - b;
		if (stack_b->next && content->diff < a - extract_number(stack_b->next->content))
			content->rb = i;
		stack_b = stack_b->next;
		i++;
	}
}

void	loop_second_half_rev(t_content *content, t_list *stack_b, int size, int loops)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = content->number;
	while (i++ < loops)
		stack_b = stack_b->next;
	while (loops < size)
	{
		b = extract_number(stack_b->content);
		content->diff = a - b;
		if (stack_b->next && content->diff < a - extract_number(stack_b->next->content))
			content->rrb = i - 1;
		i--;
		loops++;
	}
}

void	set_double_cost(t_content *content, int ra)
{
	if (ra)
	{
		if (content->rb)
		{
			while (ra && content->rb)
			{
				content->rr++;
				content->rb--;
				ra--;
			}
		}
		content->ra = ra;
	}
}

int	cost_calculation(t_list *stack_a, t_list *stack_b, int size, int loops)
{
	t_content	*content;
	int			lowest_cost;
	int			i;
	int			to_push;

	i = 0;
	while (stack_a)
	{
		content = stack_a->content;
		loop_half(content, stack_b, loops);
		loop_second_half(content, stack_b, size, loops);
		if (content->diff < 0)
		{
			loop_half_rev(content, stack_b, loops);
			loop_second_half_rev(content, stack_b, size, loops);
		}
		if (content->rb >= content->rrb)
			content->cost = content->rb;
		else
			content->cost = content->rrb;
		set_double_cost(content, i);
		if (i == 0 || content->cost < lowest_cost)
		{
			lowest_cost = content->cost;
			to_push = i;
		}
		if (i > lowest_cost)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	return (to_push);
}

void	run_push(t_list **stack_a, t_list **stack_b, t_content *content)
{
	if (content->rr--)
		double_rotate(stack_a, stack_b, "rr\n");
	else if (content->ra--)
		single_rotate(stack_a, "ra\n");
	else if (content->rb--)
		single_rotate(stack_b, "rb\n");
	else if (content->rra--)
		single_reverse_rotate(stack_a, "rra\n");
	else if (content->rrb--)
		single_reverse_rotate(stack_b, "rrb\n");
	else if (content->rrr--)
		double_reverse_rotate(stack_a, stack_b, "rrr\n");
	else
	{
		push(stack_a, stack_b, "pb\n");
		return ;
	}
	run_push(stack_a, stack_b, content);
}

void	push_b(t_list **stack_a, t_list **stack_b, int to_push)
{
	t_list		*tmp;
	t_content	*content;

	tmp = *stack_a;
	while (to_push--)
		tmp = tmp->next;
	content = tmp->content;
	run_push(stack_a, stack_b, content);
}

void	optimised_push(t_list **stack_a, t_list **stack_b)
{
	int		size;
	int		loops;
	int		to_push;

	loops = 1;
	size = 2;
	while (size_of(*stack_a) != 3)
	{
		to_push = cost_calculation(*stack_a, *stack_b, size, loops);
		push_b(stack_a, stack_b, to_push);
		size = size_of(*stack_b);
		if (size % 2 == 0)
			loops = size / 2;
		else
			loops = (size / 2) + 1;
		print_stack(*stack_a);
		print_stack(*stack_b);
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
