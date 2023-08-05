/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/05 18:29:13 by zhlim            ###   ########.fr       */
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

void	do_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size > 5)
		radix_sort(stack_a, stack_b, size);
	else if (size == 4 || size == 5)
		sort_4_5(stack_a, stack_b, size);
	else if (size <= 3)
		sort_3(stack_a);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		size;

	args = validate_args(ac, av);
	stack_a = build_stack_a(args);
	stack_b = NULL;
	check_dup(stack_a);
	size = extract_index((ft_lstlast(stack_a))->content) + 1;
	if (!check_sorted(stack_a))
		do_sort(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, destroy_content);
	return (0);
}
