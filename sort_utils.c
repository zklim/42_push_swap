/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:26:45 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 10:57:28 by zhlim            ###   ########.fr       */
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

int	size_of(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
