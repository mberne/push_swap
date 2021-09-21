/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:58:30 by mberne            #+#    #+#             */
/*   Updated: 2021/09/21 11:05:45 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	sqrt;
	int	i;

	sqrt = 0;
	i = 1;
	while (nb > 0)
	{
		nb = nb - i;
		i = i + 2;
		sqrt++;
	}
	return (sqrt);
}

int	is_ordered(t_stack stack, int i)
{
	while (i < stack.size - 1)
	{
		if (stack.array[i].value < stack.array[i + 1].value)
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
	index = 0;
	value = stack.array[0].value;
	while (i < stack.size)
	{
		if (stack.array[i].value < value)
		{
			value = stack.array[i].value;
			index = i;
		}
		i++;
	}
	return (index);
}

int	find_highest(t_stack stack, int chunk_size)
{
	int	i;
	int	index;
	int	value;

	i = 1;
	index = 0;
	value = stack.array[0].value;
	while (i < chunk_size && i < stack.size)
	{
		if (stack.array[i].value > value)
		{
			value = stack.array[i].value;
			index = i;
		}
		i++;
	}
	return (index);
}

void	create_index(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a.size)
	{
		s->a.array[i].index = 0;
		j = 0;
		while (j < s->a.size)
		{
			if (s->a.array[i].value > s->a.array[j].value)
				s->a.array[i].index++;
			j++;
		}
		i++;
	}
}
