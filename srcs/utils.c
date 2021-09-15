/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:58:30 by mberne            #+#    #+#             */
/*   Updated: 2021/09/15 13:15:56 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack stack, int i)
{
	while (i < stack.size - 1)
	{
		if (stack.array[i] < stack.array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	find_lowest(t_stack stack)
{
	int	i;
	int	index;
	int	value;

	i = 1;
	value = stack.array[0];
	index = 0;
	while (i < stack.size)
	{
		if (stack.array[i] < value)
		{
			value = stack.array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
