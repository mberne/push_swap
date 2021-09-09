/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:42:59 by mberne            #+#    #+#             */
/*   Updated: 2021/09/09 13:47:01 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef enum e_operation
{
	SWAP,
	PUSH,
	ROTATE,
	REVERSE_ROTATE
}	t_operation;

typedef enum e_stack_name
{
	A,
	B,
	BOTH
}	t_stack_name;

typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

typedef struct s_struct
{
	t_stack	a;
	t_stack	b;
}	t_struct;

int		main(int ac, char **av);
void	ft_exit(t_struct *s);
void	create_list(t_struct *s, int ac, char **av);
void	check_duplicate(t_struct *s);
int		is_ordered(t_stack s);

void	swap(t_struct *s, t_stack_name name);
void	push(t_struct *s, t_stack_name name);
void	rotate(t_struct *s, t_stack_name name);
void	reverse_rotate(t_struct *s, t_stack_name name);
void	print_operation(t_stack_name name, t_operation operation);

#endif