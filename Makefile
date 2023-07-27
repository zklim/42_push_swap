# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhlim <zhlim@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/25 16:30:48 by zhlim             #+#    #+#              #
#    Updated: 2023/07/27 15:02:22 by zhlim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= push_swap.c

OBJS			= $(patsubst %.c, %.o, $(SRCS))

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3

RM				= rm -f

INCLUDES		= -I. -Ilibft -Ilibft/ft_printf/include/

NAME			= push_swap

LIBFT			= libft/libft.a
LIBFTFLAGS		= -Llibft/ -lft
LIBPRINTF		= libft/ft_printf/libftprintf.a
LIBPRINTFFLAGS	= -Llibft/ft_printf -lftprintf

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ $(LIBFTFLAGS) $(LIBPRINTFFLAGS) -o $@

$(OBJS):		$(LIBFT) $(LIBPRINTF)

$(LIBFT):		
				make bonus -C libft/

$(LIBPRINTF):	
				make -C libft/ft_printf/

clean:		
				$(RM) $(OBJ)
				make clean -C libft/
				make clean -C libft/ft_printf/
				
fclean:			clean
				$(RM) $(NAME)
				make fclean -C libft/
				make fclean -C libft/ft_printf/

re:				fclean all

.PHONY:			all clean fclean re