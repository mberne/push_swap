/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 10:49:19 by mberne            #+#    #+#             */
/*   Updated: 2021/09/15 13:58:50 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	resolve(t_struct *s, int ac, char **av)
{
	create_list(s, ac, av);
	check_duplicate(s);
	// print_array(s);
	if (!is_ordered(s->a, 0))
	{
		if (s->a.size == 2)
			rotate(s, A);
		else if (s->a.size == 3)
			sort_three_numbers(s);
		else if (s->a.size == 4 || s->a.size == 5)
			sort_five_numbers(s);
		else
			printf("ça chunk ici ou quoi ?\n");
	}
	// print_array(s);
}
