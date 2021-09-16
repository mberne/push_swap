/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:57:50 by mberne            #+#    #+#             */
/*   Updated: 2021/09/16 13:20:13 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	s->a.array = ft_calloc(s->a.size, sizeof(int));
	s->b.array = ft_calloc(s->a.size, sizeof(int));
	if (!s->a.array || !s->b.array)
		ft_exit(s);
	while (i < s->a.size)
	{
		if (ft_isnumber(av[i + 1]))
		{
			s->a.array[i].value = ft_atoi(av[i + 1]);
			if (INT32_MIN > s->a.array[i].value
				|| s->a.array[i].value > INT32_MAX)
				ft_exit(s);
		}
		else
			ft_exit(s);
		i++;
	}
}
