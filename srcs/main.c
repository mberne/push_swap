/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:45:08 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 11:41:03 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	s;

	if (ac <= 1)
		exit(EXIT_FAILURE);
	else
		resolve(&s, ac, av);
	free(s.a.array);
	free(s.b.array);
	return (EXIT_SUCCESS);
}
