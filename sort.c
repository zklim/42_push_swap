/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 09:23:08 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	nbr;

	while (!check_sorted(*stack_a))
	{
		nbr = extract_number((*stack_a)->content);
		if (nbr > extract_number(ft_lstlast(*stack_a)->content))
			single_rotate(stack_a, "ra\n");
		else if (nbr > extract_number((*stack_a)->next->content))
			single_swap(stack_a, "sa\n");
		else
			single_rotate(stack_a, "ra\n");
	}
}

void	search_position(t_list *stack, t_content *content)
{
	int	diff;
	int	i;

	i = 0;
	content->diff = content->number;
	while (stack)
	{
		diff = content->number - extract_number(stack->content);
		if (diff > 0 && content->diff > diff)
		{
			content->diff = diff;
			content->pos = i;
		}
		i++;
		stack = stack->next;
	}
}

void	push_back_a(t_list **stack_a, t_list **stack_b, t_content *content)
{
	while (content->pos--)
		single_rotate(stack_a, "ra\n");
	push(stack_b, stack_a, "pa\n");
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
}
