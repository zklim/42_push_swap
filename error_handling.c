/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/01 12:46:45 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_error_exit(char *str)
{
    ft_printf("%s", str);
    exit(1);
}

void    free_error_exit(char *str, t_list *stack)
{
    ft_printf("%s", str);
    ft_lstclear(&stack, destroy_content);
    exit(1);
}