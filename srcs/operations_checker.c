/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:30:48 by mberne            #+#    #+#             */
/*   Updated: 2021/09/27 16:00:44 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_checker(t_struct *s, t_stack_name name)
{
	t_elem	tmp;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[0];
		s->a.array[0] = s->a.array[1];
		s->a.array[1] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0];
		s->b.array[0] = s->b.array[1];
		s->b.array[1] = tmp;
	}
}

void	push_checker(t_stack *send, t_stack *receive)
{
	int	i;

	if (send->size > 0)
	{
		i = receive->size;
		while (i > 0)
		{
			receive->array[i] = receive->array[i - 1];
			i--;
		}
		i = 0;
		receive->array[i] = send->array[i];
		send->size--;
		receive->size++;
		while (i < send->size)
		{
			send->array[i] = send->array[i + 1];
			i++;
		}
	}
}

void	rotate_checker(t_struct *s, t_stack_name name)
{
	t_elem	tmp;
	int		i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[0];
		i = -1;
		while (++i < s->a.size - 1)
			s->a.array[i] = s->a.array[i + 1];
		s->a.array[s->a.size - 1] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0];
		i = -1;
		while (++i < s->b.size - 1)
			s->b.array[i] = s->b.array[i + 1];
		s->b.array[s->b.size - 1] = tmp;
	}
}

void	reverse_rotate_checker(t_struct *s, t_stack_name name)
{
	t_elem	tmp;
	int		i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[s->a.size - 1];
		i = s->a.size;
		while (--i > 0)
			s->a.array[i] = s->a.array[i - 1];
		s->a.array[0] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[s->b.size - 1];
		i = s->b.size;
		while (--i > 0)
			s->b.array[i] = s->b.array[i - 1];
		s->b.array[0] = tmp;
	}
}
