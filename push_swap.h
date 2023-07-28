/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:41:00 by zhlim             #+#    #+#             */
/*   Updated: 2023/07/28 18:00:39 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/include/ft_printf.h"
# include "libft/libft.h"

typedef struct s_content
{
	int	index;
	int	number;
}		t_content;

int		validate_args(int ac, char **av);
void	destroy_content(void *content);
t_list	*build_stack_a(int ac, char **av);
void	print_error_exit(char *str);
void    free_error_exit(char *str, t_list *stack);
void	check_dup(t_list *stack);

#endif