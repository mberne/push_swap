/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:42:59 by mberne            #+#    #+#             */
/*   Updated: 2021/09/27 16:15:03 by mberne           ###   ########lyon.fr   */
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

typedef struct s_elem
{
	int	value;
	int	index;
}	t_elem;

typedef struct s_stack
{
	t_elem	*array;
	int		size;
}	t_stack;

typedef struct s_struct
{
	t_stack	a;
	t_stack	b;
}	t_struct;

int			main(int ac, char **av);
int			read_answer(t_struct *s);
void		make_instruction(t_struct *s, char *instruction);

void		create_list(t_struct *s, int ac, char **av);
void		check_duplicate(t_struct *s);
void		create_index(t_struct *s);

void		swap(t_struct *s, t_stack_name name);
void		push(t_stack_name name, t_stack *send, t_stack *receive);
void		rotate(t_struct *s, t_stack_name name);
void		reverse_rotate(t_struct *s, t_stack_name name);
void		print_operation(t_stack_name name, t_operation operation);

void		swap_checker(t_struct *s, t_stack_name name);
void		push_checker(t_stack *send, t_stack *receive);
void		rotate_checker(t_struct *s, t_stack_name name);
void		reverse_rotate_checker(t_struct *s, t_stack_name name);

void		resolve(t_struct *s, int ac, char **av);
void		chunk(t_struct *s);
void		push_highest(t_struct *s, int highest);

void		sort_three_numbers(t_struct *s);
void		sort_five_numbers(t_struct *s);
void		push_lowest(t_struct *s);

void		push_chunk(t_struct *s, int chunk_size);
int			find_first(t_struct *s, int chunk_size, int current_index);
int			find_second(t_struct *s, int chunk_size, int current_index);
t_operation	ra_or_rra(t_struct *s, int first, int second);
void		rotation(t_struct *s, t_operation rotation, int first, int second);

void		radix(t_struct *s);

int			is_ordered(t_stack stack, int i);
int			find_lowest(t_stack stack);
int			find_highest(t_stack stack);
int			ft_sqrt(int nb);
void		ft_exit(t_struct *s);

#endif