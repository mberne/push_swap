/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:30:07 by mberne            #+#    #+#             */
/*   Updated: 2021/09/29 15:49:43 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_instruction(t_struct *s, char *instruction)
{
	if (!ft_strncmp(instruction, "sa", 2))
		swap_checker(s, A);
	else if (!ft_strncmp(instruction, "sb", 2))
		swap_checker(s, B);
	else if (!ft_strncmp(instruction, "ss", 2))
		swap_checker(s, BOTH);
	else if (!ft_strncmp(instruction, "pa", 2))
		push_checker(&s->b, &s->a);
	else if (!ft_strncmp(instruction, "pb", 2))
		push_checker(&s->a, &s->b);
	else if (!ft_strncmp(instruction, "ra", 2))
		rotate_checker(s, A);
	else if (!ft_strncmp(instruction, "rb", 2))
		rotate_checker(s, B);
	else if (!ft_strncmp(instruction, "rr", 2))
		rotate_checker(s, BOTH);
	else if (!ft_strncmp(instruction, "rra", 3))
		reverse_rotate_checker(s, A);
	else if (!ft_strncmp(instruction, "rrb", 3))
		reverse_rotate_checker(s, B);
	else if (!ft_strncmp(instruction, "rrr", 3))
		reverse_rotate_checker(s, BOTH);
}

int	read_answer(t_struct *s)
{
	char	*instruction;
	int		ret;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &instruction);
		if (ret == -1)
			return (EXIT_FAILURE);
		else if (ret == 0)
		{
			if (*instruction)
				ret = -1;
		}
		else
			make_instruction(s, instruction);
		free(instruction);
	}
	if (ret == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_struct	s;
	int			ret;

	ret = EXIT_FAILURE;
	if (ac <= 1)
		exit(EXIT_FAILURE);
	else
	{
		create_list(&s, ac, av);
		check_duplicate(&s);
		ret = read_answer(&s);
		if (ret == EXIT_SUCCESS)
		{
			if (is_ordered(s.a, 0) && s.b.size == 0)
				printf("OK\n");
			else
				printf("KO\n");
		}
		else
			ft_exit(&s);
	}
	free(s.a.array);
	free(s.b.array);
	return (EXIT_SUCCESS);
}
