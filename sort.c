/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:22:56 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/05 18:43:09 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, int size)
{
	sort_positive(stack_a, stack_b, size, 0);
	if (has_negative(stack_a))
		sort_negative(stack_a, stack_b, size, 0);
}

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

void	search_and_push(t_list *tmp, t_content *content, t_list **stack_a,
		t_list **stack_b)
{
	while (tmp)
	{
		if (content->number < extract_number(tmp->content))
		{
			push(stack_b, stack_a, "pa\n");
			return ;
		}
		else
			single_rotate(stack_a, "ra\n");
		tmp = tmp->next;
	}
}

void	sort_4_5(t_list **stack_a, t_list **stack_b, int size)
{
	t_list		*tmp;
	t_content	*content;

	while (size != 3)
	{
		push(stack_a, stack_b, "pb\n");
		size--;
	}
	sort_3(stack_a);
	while (*stack_b)
	{
		tmp = *stack_a;
		content = (*stack_b)->content;
		search_and_push(tmp, content, stack_a, stack_b);
	}
	while (!check_sorted(*stack_a))
		single_rotate(stack_a, "ra\n");
}
