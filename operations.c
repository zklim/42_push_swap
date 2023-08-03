/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:51:37 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/03 15:24:16 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	t_list		*tmp;
	t_content	*content;
	int			i;

	i = 0;
	tmp = stack;
	while (1)
	{
		if (i == 2)
			break ;
		if (!tmp && i < 2)
			ft_printf("stack less than 1\n");
		return ;
		i++;
		tmp = tmp->next;
	}
	content = stack->content;
	stack->content = stack->next->content;
	stack->next->content = content;
}

void	push(t_list **stack_pop, t_list **stack_push, char *str)
{
	t_list	*tmp;

	if (!*stack_pop)
		return ;
	tmp = *stack_pop;
	*stack_pop = (*stack_pop)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_push, tmp);
	ft_printf(str);
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	tmp = *stack;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack, last);
}

void	double_reverse_rotate(t_list **stack_a, t_list **stack_b, char *str)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf(str);
}
