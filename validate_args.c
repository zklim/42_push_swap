/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:33:10 by zhlim             #+#    #+#             */
/*   Updated: 2023/08/03 15:35:27 by zhlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_list *stack)
{
	t_list	*top;
	t_list	*loop;

	top = stack;
	while (stack)
	{
		loop = top;
		while (loop)
		{
			if (extract_index(loop->content) == extract_index(stack->content))
			{
				loop = loop->next;
				if (!loop)
					break ;
			}
			else if (extract_number(loop->content)
				== extract_number(stack->content))
				free_error_exit("Error\nDuplicate number found\n", top);
			loop = loop->next;
		}
		stack = stack->next;
	}
}

void	check_int(char *number)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	if (number[i] == '-' || number[i] == '+')
	{
		sign = -1;
		i++;
	}
	while (number[i] == '0')
		i++;
	while (number[i] >= '0' && number[i] <= '9')
	{
		nbr = (nbr * 10) + (number[i] - '0');
		i++;
	}
	if (number[i] != '\0' || (nbr * sign) < -2147483648 || (nbr
			* sign) > 2147483647)
		print_error_exit("Error\nNumber format not accepted\n");
}

int	validate_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		check_int(av[i]);
		i++;
	}
	return (1);
}
