/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:45:08 by mberne            #+#    #+#             */
/*   Updated: 2021/09/10 14:28:59 by mberne           ###   ########lyon.fr   */
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
			if (s->a.array[i] == s->a.array[j])
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
			s->a.array[i] = ft_atoi(av[i + 1]);
			if (INT32_MIN > s->a.array[i] || s->a.array[i] > INT32_MAX)
				ft_exit(s);
		}
		else
			ft_exit(s);
		i++;
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
		number = ft_atoi(av[1]);
		if (INT32_MIN > number || number > INT32_MAX)
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