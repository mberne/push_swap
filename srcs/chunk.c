/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:41:50 by mberne            #+#    #+#             */
/*   Updated: 2021/09/21 11:08:19 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_struct *s, t_operation rotation, int first, int second)
{
	if (rotation == ROTATE)
	{
		while (first != 0)
		{
			rotate(s, A);
			first--;
		}
	}
	else
	{
		while (second != s->a.size)
		{
			reverse_rotate(s, A);
			second++;
		}
	}
}

t_operation	ra_or_rra(t_struct *s, int first, int second)
{
	int	stack_middle;

	stack_middle = s->a.size / 2;
	if (first < stack_middle && second < stack_middle)
		return (ROTATE);
	else if (first >= stack_middle && second >= stack_middle)
		return (REVERSE_ROTATE);
	else
	{
		if (s->a.size - first < second)
			return (ROTATE);
		else
			return (REVERSE_ROTATE);
	}
}

int	find_second(t_struct *s, int chunk_size, int current_index)
{
	int	i;
	int	last_index;

	i = s->a.size - 1;
	last_index = chunk_size + current_index;
	while (i >= 0)
	{
		if (s->a.array[i].index >= current_index
			&& s->a.array[i].index < last_index)
			return (i);
		i--;
	}
	return (0);
}

int	find_first(t_struct *s, int chunk_size, int current_index)
{
	int	i;
	int	last_index;

	i = 0;
	last_index = chunk_size + current_index;
	while (i < s->a.size)
	{
		if (s->a.array[i].index >= current_index
			&& s->a.array[i].index < last_index)
			return (i);
		i++;
	}
	return (0);
}

void	push_chunk(t_struct *s, int chunk_size)
{
	int			i;
	int			first;
	int			second;
	static int	current_index = 0;

	i = 0;
	while (i < chunk_size)
	{
		first = find_first(s, chunk_size, current_index);
		second = find_second(s, chunk_size, current_index);
		rotation(s, ra_or_rra(s, first, second), first, second);
		push(B, &s->a, &s->b);
		i++;
	}
	current_index += chunk_size;
}
