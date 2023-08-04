/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:52:26 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/04 16:49:38 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "libft/get_next_line/get_next_line.h"

void	run_checker(t_list **stack_a, t_list **stack_b);
void	check_command(char *line, t_list **stack_a, t_list **stack_b);

#endif