/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:05:10 by mberne            #+#    #+#             */
/*   Updated: 2021/09/22 17:15:20 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_struct *s)
{
	int	i;
	int	bit;

	bit = 0;
	while (!is_ordered(s->a, 0))
	{
		i = s->a.size;
		while (i > 0)
		{
			if ((s->a.array[0].index >> bit) & 1)
				rotate(s, A);
			else
				push(B, &s->a, &s->b);
			i--;
		}
		while (s->b.size != 0)
			push(A, &s->b, &s->a);
		bit++;
	}
}
