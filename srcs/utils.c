/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:58:30 by mberne            #+#    #+#             */
/*   Updated: 2021/09/14 13:02:47 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack s, int i)
{
	while (i < s.size - 1)
	{
		if (s.array[i] < s.array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	find_lowest(t_stack s)
{
	int	i;
	int	index;
	int	value;

	i = 1;
	value = s.array[0];
	index = 0;
	while (i < s.size)
	{
		if (s.array[i] < value)
		{
			value = s.array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
