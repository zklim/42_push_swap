/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/10 01:25:24 by zhlim            ###   ########.fr       */
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
	if (size <= 3)
		sort_3(stack_a);
	else
		sort_advance(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;
	int		size;
	int		to_free;

	to_free = 0;
	args = validate_args(ac, av, &to_free);
	stack_a = build_stack_a(args);
	if (to_free)
		free_args(args);
	stack_b = NULL;
	check_dup(stack_a);
	size = get_index((ft_lstlast(stack_a))->content) + 1;
	if (!check_sorted(stack_a))
		do_sort(&stack_a, &stack_b, size);
	ft_lstclear(&stack_a, destroy_content);
	return (0);
}
