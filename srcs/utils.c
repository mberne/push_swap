/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:58:30 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 12:18:21 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_struct *s)
{
	free(s->a.array);
	free(s->b.array);
	printf("Error\n");
	exit(EXIT_FAILURE);
}

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

int	find_highest(t_stack stack)
{
	int	i;
	int	index;
	int	value;

	i = 1;
	index = 0;
	value = stack.array[0].value;
	while (i < stack.size)
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
