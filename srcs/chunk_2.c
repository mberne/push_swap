/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:05:10 by mberne            #+#    #+#             */
/*   Updated: 2021/09/21 11:07:29 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_highest(t_struct *s, int highest)
{
	int	i;

	i = 0;
	while (i < highest)
	{
		rotate(s, B);
		i++;
	}
	push(A, &s->b, &s->a);
	while (i > 0)
	{
		reverse_rotate(s, B);
		i--;
	}
}

void	final_order(t_struct *s, int chunk_size)
{
	int	i;
	int	highest;

	i = 0;
	while (i < chunk_size)
	{
		highest = find_highest(s->b, chunk_size);
		push_highest(s, highest);
		i++;
	}
}
