/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_negative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:11:05 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/04 15:14:41 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_negative(t_list **stack_a, t_list **stack_b, int size, int bit)
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
		if ((nbr & 1 << 31) == 1 << 31)
		{
			if ((nbr & 1 << (31 - bit)) == 0)
				push(stack_a, stack_b, "pb\n");
			else
				single_rotate(stack_a, "ra\n");
		}
		else
			single_rotate(stack_a, "ra\n");
		i++;
	}
	push_back(stack_a, stack_b);
	sort_negative(stack_a, stack_b, size, ++bit);
}

int	check_negative(t_list **stack_a)
{
	t_list	*tmp;
	int		nbr;

	tmp = *stack_a;
	while (tmp)
	{
		nbr = extract_number(tmp->content);
		tmp = tmp->next;
		if (nbr < 0)
			return (1);
	}
	return (0);
}
