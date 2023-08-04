/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:38:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/04 15:29:51 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_error_exit(char *str)
{
	write_error(str);
	exit(1);
}

void	free_error_exit(char *str, t_list *stack)
{
	write_error(str);
	ft_lstclear(&stack, destroy_content);
	exit(1);
}
