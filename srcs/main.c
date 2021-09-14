/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:45:08 by mberne            #+#    #+#             */
/*   Updated: 2021/09/14 12:56:26 by mberne           ###   ########lyon.fr   */
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
	{
		create_list(&s, ac, av);
		check_duplicate(&s);
		if (!is_ordered(s.a, 0))
			resolve(&s);
	}
	free(s.a.array);
	free(s.b.array);
	return (EXIT_SUCCESS);
}

void	print_array(t_struct *s)
{
	int	i;

	printf("\nStack A\n");
	i = 0;
	while (i < s->a.size)
	{
		printf("%d ", s->a.array[i]);
		i++;
	}
	printf("\n");
	printf("\nStack B\n");
	i = 0;
	while (i < s->b.size)
	{
		printf("%d ", s->b.array[i]);
		i++;
	}
	printf("\n");
}