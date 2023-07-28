/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/28 17:50:37 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (!validate_args(ac, av))
		return (1);
	stack_a = build_stack_a(ac, av);
	check_dup(stack_a);
	ft_lstclear(&stack_a, destroy_content);
	return (0);
}
