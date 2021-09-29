/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:49:19 by mberne            #+#    #+#             */
/*   Updated: 2021/09/29 15:16:12 by mberne           ###   ########lyon.fr   */
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
	while (i <= num_of_chunk)
	{
		push_chunk(s, chunk_size);
		i++;
	}
	while (s->b.size != 0)
	{
		highest = find_highest(s->b);
		push_highest(s, highest);
	}
}

void	resolve(t_struct *s, int ac, char **av)
{
	create_list(s, ac, av);
	check_duplicate(s);
	if (!is_ordered(s->a, 0))
	{
		if (s->a.size == 1)
			return ;
		else if (s->a.size == 2)
			rotate(s, A);
		else if (s->a.size == 3)
			sort_three_numbers(s);
		else if (s->a.size == 4 || s->a.size == 5)
			sort_five_numbers(s);
		else
		{
			create_index(s);
			if (s->a.size < 500)
				chunk(s);
			else
				radix(s);
		}
	}
}
