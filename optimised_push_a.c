/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_push_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:04:21 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/09 17:20:43 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimised_push_a(t_list **stack_a, t_list **stack_b)
{
	t_op	op;

	while (size_of(*stack_b))
	{
		init_op(&op);
		calculate_cost_a(*stack_a, *stack_b, &op);
		to_push(stack_a, stack_b, op.to_push, 'a');
	}
}
