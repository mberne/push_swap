/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:57:50 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 12:03:42 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	check_duplicate(t_struct *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->a.size)
	{
		j = 0;
		while (j < i)
		{
			if (s->a.array[i].value == s->a.array[j].value)
				ft_exit(s);
			j++;
		}
		i++;
	}
}

void	create_list(t_struct *s, int ac, char **av)
{
	int	i;

	i = 0;
	s->a.size = ac - 1;
	s->b.size = 0;
	s->a.array = ft_calloc(s->a.size, sizeof(t_elem));
	s->b.array = ft_calloc(s->a.size, sizeof(t_elem));
	if (!s->a.array || !s->b.array)
		ft_exit(s);
	while (i < s->a.size)
	{
		if (ft_isnumber(av[i + 1]))
		{
			s->a.array[i].value = ft_atol(av[i + 1]);
			if (INT32_MIN > s->a.array[i].value
				|| s->a.array[i].value > INT32_MAX)
				ft_exit(s);
		}
		else
			ft_exit(s);
		i++;
	}
}
