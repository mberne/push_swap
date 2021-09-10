/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:49:19 by mberne            #+#    #+#             */
/*   Updated: 2021/09/10 14:37:59 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_numbers(t_struct *s)
{
	push(s, B);
	sort_four_numbers(s);
	print_array(s);
	if (s->b.array[0] > s->a.array[0] && s->b.array[0] < s->a.array[1])
	{
		rotate(s, A);
		push(s, A);
		reverse_rotate(s, A);
	}
	else if (s->b.array[0] > s->a.array[1] && s->b.array[0] < s->a.array[2])
	{
		rotate(s, A);
		rotate(s, A);
		push(s, A);
		reverse_rotate(s, A);
		reverse_rotate(s, A);
	}
	else if (s->b.array[0] > s->a.array[2] && s->b.array[0] < s->a.array[3])
	{
		reverse_rotate(s, A);
		push(s, A);
		rotate(s, A);
		rotate(s, A);
	}
	else if (s->b.array[0] > s->a.array[3])
	{
		push(s, A);
		rotate(s, A);
	}
	else
		push(s, A);
}

void	sort_four_numbers(t_struct *s)
{
	if (!is_ordered(s->a, 1))
	{
		push(s, B);
		sort_three_numbers(s);
		push(s, A);
	}
	if (s->a.array[0] > s->a.array[1] && s->a.array[0] < s->a.array[2])
		swap(s, A);
	else if (s->a.array[0] > s->a.array[2] && s->a.array[0] < s->a.array[3])
	{
		swap(s, A);
		rotate(s, A);
		swap(s, A);
		reverse_rotate(s, A);
	}
	else if (s->a.array[0] > s->a.array[3])
		rotate(s, A);
}

void	sort_three_numbers(t_struct *s)
{
	if (s->a.array[0] < s->a.array[2] && s->a.array[1] < s->a.array[2])
		swap(s, A);
	else if (s->a.array[0] > s->a.array[2] && s->a.array[1] > s->a.array[2])
	{
		if (s->a.array[0] > s->a.array[1])
			swap(s, A);
		reverse_rotate(s, A);
	}
	else
	{
		if (s->a.array[0] < s->a.array[1])
			swap(s, A);
		rotate(s, A);
	}
}

void	resolve(t_struct *s)
{
	if (s->a.size == 2)
		rotate(s, A);
	else if (s->a.size == 3)
		sort_three_numbers(s);
	else if (s->a.size == 4)
		sort_four_numbers(s);
	else if (s->a.size == 5)
		sort_five_numbers(s);
	else
		printf("ça chunk ici ou quoi ?\n");
	print_array(s);
}
