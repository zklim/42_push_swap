/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_positive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:04:09 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/04 15:10:52 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	extract_number(t_content *content)
{
	return (content->number);
}

int	extract_index(t_content *content)
{
	return (content->index);
}

int	check_sorted(t_list *stack_a)
{
	int	a;
	int	b;

	while (stack_a)
	{
		if (stack_a->next)
		{
			a = extract_number(stack_a->content);
			b = extract_number(stack_a->next->content);
			if (a > b)
				return (0);
		}
		stack_a = stack_a->next;
	}
	return (1);
}

void	push_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		tmp = tmp->next;
		push(stack_b, stack_a, "pa\n");
	}
}

void	sort_positive(t_list **stack_a, t_list **stack_b, int size, int bit)
{
	t_list	*tmp;
	int		nbr;
	int		i;

	tmp = *stack_a;
	i = 0;
	if (check_sorted(*stack_a) || bit == 32)
		return ;
	while (tmp && i != size)
	{
		nbr = extract_number(tmp->content);
		tmp = tmp->next;
		if ((nbr & 1 << 31) == 0)
		{
			if ((nbr & 1 << bit) == 0)
				push(stack_a, stack_b, "pb\n");
			else
				single_rotate(stack_a, "ra\n");
		}
		else
			single_rotate(stack_a, "ra\n");
		i++;
	}
	push_back(stack_a, stack_b);
	sort_positive(stack_a, stack_b, size, ++bit);
}
