/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:45:08 by mberne            #+#    #+#             */
/*   Updated: 2021/09/09 13:05:10 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(t_struct *s, int ac, char **av)
{
	int	i;

	i = 0;
	s->a.size = ac - 1;
	s->a.array = calloc(s->a.size, sizeof(int));
	s->b.array = calloc(s->a.size, sizeof(int));
	if (!s->a.array || !s->b.array)
		ft_exit(s);
	while (i < s->a.size)
	{
		if (ft_isnumber(av[i + 1]))
			s->a.array[i] = ft_atoi(av[i + 1]);
		else
			ft_exit(s);
		i++;
	}
}

void	ft_exit(t_struct *s)
{
	(void)s;
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
		// s.b.array[0] = 12;
		// s.b.array[1] = 15;
		// s.b.array[2] = 32;
		// s.b.array[3] = 55;
		// s.b.array[4] = 11;
		// s.b.array[5] = 28;
		// s.b.size = 6;
		// printf("\nA\n\n");
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// swap(&s, A);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// rotate(&s, A);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// reverse_rotate(&s, A);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// push(&s, A);
		// printf("A : %d %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5], s.a.array[6]);
		// printf("B : %d %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5], s.b.array[6]);
		// printf("\nB\n\n");
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// swap(&s, B);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// rotate(&s, B);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// reverse_rotate(&s, B);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// push(&s, B);
		// printf("A : %d %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5], s.a.array[6]);
		// printf("B : %d %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5], s.b.array[6]);
		// printf("\nBOTH\n\n");
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// swap(&s, BOTH);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// rotate(&s, BOTH);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
		// reverse_rotate(&s, BOTH);
		// printf("A : %d %d %d %d %d %d\n", s.a.array[0], s.a.array[1], s.a.array[2], s.a.array[3], s.a.array[4], s.a.array[5]);
		// printf("B : %d %d %d %d %d %d\n", s.b.array[0], s.b.array[1], s.b.array[2], s.b.array[3], s.b.array[4], s.b.array[5]);
	}
	return (EXIT_SUCCESS);
}
