/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/01 18:10:30 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_content	*content;

	if (!validate_args(ac, av))
		return (1);
	stack_a = build_stack_a(ac, av);
	check_dup(stack_a);
	sort(&stack_a, &stack_b);
	content = stack_a->content;
	ft_printf("%d\n", content->number);
	ft_lstclear(&stack_a, destroy_content);
	return (0);
}
