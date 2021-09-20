/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:41:50 by mberne            #+#    #+#             */
/*   Updated: 2021/09/20 15:22:48 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_or_rra(t_struct *s, int first, int second)
{
	int	stack_middle;

	stack_middle = s->a.size / 2;
	if (first < stack_middle && second < stack_middle)
	{
		while (first != 0)
		{
			rotate(s, A);
			first--;
		}
	}
	else if (first >= stack_middle && second >= stack_middle)
	{
		while (second != s->a.size)
		{
			reverse_rotate(s, A);
			second++;
		}
	}
	else if (first < stack_middle && second >= stack_middle)
	{
		if (s->a.size - first < second)
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
}

int	find_hold_second(t_struct *s, int chunk_size, int current_index)
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

int	find_hold_first(t_struct *s, int chunk_size, int current_index)
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
		first = find_hold_first(s, chunk_size, current_index);
		second = find_hold_second(s, chunk_size, current_index);
		ra_or_rra(s, first, second);
		push(B, &s->a, &s->b);
		i++;
	}
	current_index += chunk_size;
}

void	chunk(t_struct *s)
{
	int	i;
	int	num_of_chunk;
	int	chunk_size;
	int	modulo_chunk_size;

	i = 0;
	num_of_chunk = ft_sqrt(s->a.size) / 2;
	chunk_size = s->a.size / num_of_chunk;
	while (i <= num_of_chunk)
	{
		push_chunk(s, chunk_size);
		i++;
	}
	modulo_chunk_size = s->b.size % num_of_chunk;
	if (modulo_chunk_size != 0)
	{
		final_order(s, modulo_chunk_size);
		i--;
	}
	while (i > 0)
	{
		final_order(s, chunk_size);
		i--;
	}
}
