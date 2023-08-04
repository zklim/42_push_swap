/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:52:10 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/04 18:07:41 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	args = validate_args(ac, av);
	stack_a = build_stack_a(args);
	stack_b = NULL;
	check_dup(stack_a);
	run_checker(&stack_a, &stack_b);
	if (stack_b || !check_sorted(stack_a))
		free_error_exit("KO\n", stack_a);
	ft_printf("OK\n");
	ft_lstclear(&stack_a, destroy_content);
}
