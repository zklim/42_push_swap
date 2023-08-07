/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:58:17 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/07 11:08:58 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	nbr;

	if (size_of(*stack_a) != 3)
		return ;
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

void	search_smallest(t_list *tmp, t_content *content)
{
	int			i;
	int			diff;
	t_content	*tmp_content;

	i = 0;
	content->diff = content->number - extract_number(tmp->content);
	content->pos = i;
	while (tmp)
	{
		diff = content->number - extract_number(tmp->content);
		if (content->diff <= diff)
		{
			content->pos = i;
			tmp_content = tmp->content;
			tmp_content->smallest = 1;
		}
		i++;
		tmp = tmp->next;
	}
}

void	search_position(t_list *stack, t_content *content)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (stack)
	{
		if (content->number < extract_number(stack->content))
		{
			content->pos = i;
			return ;
		}
		i++;
		stack = stack->next;
	}
	search_smallest(tmp, content);
}

void	push_back_a(t_list **stack_a, t_list **stack_b, t_content *content)
{
	int	size;

	size = size_of(*stack_a);
	if (content->pos > size / 2)
		while (size-- != content->pos)
			single_reverse_rotate(stack_a, "rra\n");
	else
		while (content->pos--)
			single_rotate(stack_a, "ra\n");
	push(stack_b, stack_a, "pa\n");
}

int	smallest_pos(t_list *stack_a, int size)
{
	t_content	*content;
	int			i;

	i = 0;
	while (stack_a)
	{
		content = stack_a->content;
		if (content->smallest)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	if (i < (size / 2) + 1)
		return (1);
	else
		return (0);
}