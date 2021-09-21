/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:49:19 by mberne            #+#    #+#             */
/*   Updated: 2021/09/21 11:05:43 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	resolve(t_struct *s, int ac, char **av)
{
	create_list(s, ac, av);
	check_duplicate(s);
	if (!is_ordered(s->a, 0))
	{
		if (s->a.size == 2)
			rotate(s, A);
		else if (s->a.size == 3)
			sort_three_numbers(s);
		else if (s->a.size == 4 || s->a.size == 5)
			sort_five_numbers(s);
		else
		{
			create_index(s);
			chunk(s);
		}
	}
}
