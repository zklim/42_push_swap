/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:40:20 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/27 16:55:27 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content   *build_content(char *num, int index)
{
    t_content   *content;
    
    content = (t_content *)malloc(sizeof(t_content));
    if (!content)
        return (NULL);
    content->number = ft_atoi(num);
    content->index = index;
    return (content);
}

t_list    *build_stack_a(int ac, char **av)
{
    t_list      *stack_a;
    t_content   *content;

    int         i;

    i = 1;
    while(i < ac)
    {
        content = build_content(av[i], i);
        if (i == 1)
            stack_a = ft_lstnew(content);
        else
            ft_lstadd_back(&stack_a, ft_lstnew(content));
        i++;
    }
    return (stack_a);
}

int main(int ac, char **av)
{
    t_list      *stack_a;
    
    if (ac < 2)
    {
        ft_printf("Error\nNo arguments given.\n");
        return 1;
    }
    stack_a = build_stack_a(ac, av);
    return 0;
}