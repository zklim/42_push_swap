/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:04:09 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/03 12:11:13 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int extract_number(t_content *content)
{
    return (content->number);
}

int extract_index(t_content *content)
{
    return (content->index);
}

void    sort(t_list **stack_a, t_list **stack_b)
{
    int a;
    int b;
    
    a = extract_number((*stack_a)->content);
    b = extract_number((*stack_a)->next->content);P
    if ((a & 1) == 0)
    {
        push(stack_a, stack_b, "pb\n");
    }
}