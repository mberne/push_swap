/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:49:19 by mberne            #+#    #+#             */
/*   Updated: 2021/09/22 17:14:39 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_highest(t_struct *s, int highest)
{
	int	i;
	int	stack_middle;

	stack_middle = s->b.size / 2;
	if (highest < stack_middle)
	{
		i = 0;
		while (i < highest)
		{
			rotate(s, B);
			i++;
		}
	}
	else
	{	
		i = highest;
		while (i < s->b.size)
		{
			reverse_rotate(s, B);
			i++;
		}
	}
	push(A, &s->b, &s->a);
}

void	chunk(t_struct *s)
{
	int	i;
	int	num_of_chunk;
	int	chunk_size;
	int	highest;

	i = 0;
	num_of_chunk = ft_sqrt(s->a.size) / 2;
	chunk_size = s->a.size / num_of_chunk;
	while (i <= num_of_chunk && s->a.size > 5)
	{
		push_chunk(s, chunk_size);
		i++;
	}
	if (s->a.size == 2 && !is_ordered(s->a, 0))
		rotate(s, A);
	else if (s->a.size == 3 && !is_ordered(s->a, 0))
		sort_three_numbers(s);
	else if ((s->a.size == 4 && !is_ordered(s->a, 0))
		|| (s->a.size == 5 && !is_ordered(s->a, 0)))
		sort_five_numbers(s);
	while (s->b.size != 0)
	{
		highest = find_highest(s->b);
		push_highest(s, highest);
	}
}

void	push_lowest(t_struct *s)
{
	int	index;

	index = find_lowest(s->a);
	if (index == 3 || index == 4)
	{
		if (index == 3)
			reverse_rotate(s, A);
		reverse_rotate(s, A);
	}
	else if (index == 1 || index == 2)
	{
		if (index == 2)
			rotate(s, A);
		swap(s, A);
	}
	push(B, &s->a, &s->b);
}

void	sort_five_numbers(t_struct *s)
{
	int	index;

	if (s->a.size == 5)
		push_lowest(s);
	index = find_lowest(s->a);
	if (index == 3)
		reverse_rotate(s, A);
	else if (index == 1 || index == 2)
	{
		if (index == 2)
			rotate(s, A);
		swap(s, A);
	}
	push(B, &s->a, &s->b);
	sort_three_numbers(s);
	push(A, &s->b, &s->a);
	push(A, &s->b, &s->a);
}

void	sort_three_numbers(t_struct *s)
{
	if (!is_ordered(s->a, 0))
	{
		if (s->a.array[0].value < s->a.array[2].value
			&& s->a.array[1].value < s->a.array[2].value)
			swap(s, A);
		else if (s->a.array[0].value > s->a.array[2].value
			&& s->a.array[1].value > s->a.array[2].value)
		{
			if (s->a.array[0].value > s->a.array[1].value)
				swap(s, A);
			reverse_rotate(s, A);
		}
		else
		{
			if (s->a.array[0].value < s->a.array[1].value)
				swap(s, A);
			rotate(s, A);
		}
	}
}
