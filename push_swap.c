/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/03 15:23:38 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_content	*content;

	while (stack)
	{
		content = stack->content;
		ft_printf("%d ", content->number);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (!validate_args(ac, av))
		return (1);
	stack_a = build_stack_a(ac, av);
	stack_b = NULL;
	check_dup(stack_a);
	print_stack(stack_a);
	size = extract_index((ft_lstlast(stack_a))->content);
	sort(&stack_a, &stack_b, size, 0);
	print_stack(stack_a);
	ft_lstclear(&stack_a, destroy_content);
	return (0);
}
