/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:45:08 by mberne            #+#    #+#             */
/*   Updated: 2021/09/22 17:13:43 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_struct *s, int ac, char **av)
{
	create_list(s, ac, av);
	check_duplicate(s);
	if (!is_ordered(s->a, 0))
	{
		if (s->a.size == 2)
			rotate(s, A);
		else if (s->a.size == 3)
			sort_three_numbers(s);
		else if (s->a.size == 4 || s->a.size == 5)
			sort_five_numbers(s);
		else
		{
			create_index(s);
			if (s->a.size < 500)
				chunk(s);
			else
				radix(s);
		}
	}
}

void	ft_exit(t_struct *s)
{
	free(s->a.array);
	free(s->b.array);
	printf("Error\n");
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_struct	s;
	int			number;

	if (ac <= 1)
		ft_exit(&s);
	else if (ac == 2)
	{
		if (ft_isnumber(av[1]))
		{
			number = ft_atoi(av[1]);
			if (INT32_MIN > number || number > INT32_MAX)
				ft_exit(&s);
		}
		else
			ft_exit(&s);
	}
	else
		resolve(&s, ac, av);
	free(s.a.array);
	free(s.b.array);
	return (EXIT_SUCCESS);
}
