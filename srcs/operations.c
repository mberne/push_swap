/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:17:39 by mberne            #+#    #+#             */
/*   Updated: 2021/09/10 12:43:06 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(t_stack_name name, t_operation operation)
{
	if (operation == SWAP)
		printf("s");
	else if (operation == PUSH)
		printf("p");
	else if (operation == ROTATE)
		printf("r");
	else if (operation == REVERSE_ROTATE)
		printf("rr");
	if (name == A)
		printf("a\n");
	else if (name == B)
		printf("b\n");
	else if (name == BOTH)
	{
		if (operation == SWAP)
			printf("s\n");
		else if (operation == ROTATE || operation == REVERSE_ROTATE)
			printf("r\n");
	}
}

void	swap(t_struct *s, t_stack_name name)
{
	int	tmp;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[0];
		s->a.array[0] = s->a.array[1];
		s->a.array[1] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0];
		s->b.array[0] = s->b.array[1];
		s->b.array[1] = tmp;
	}
	print_operation(name, SWAP);
}

void	push(t_struct *s, t_stack_name name)
{
	int	i;

	if (name == A && s->b.size > 0)
	{
		i = s->a.size;
		while (i > 0)
		{
			s->a.array[i] = s->a.array[i - 1];
			i--;
		}
		s->a.array[0] = s->b.array[0];
		while (i < s->b.size - 1)
		{
			s->b.array[i] = s->b.array[i + 1];
			i++;
		}
		s->a.size++;
		s->b.size--;
	}
	if (name == B && s->a.size > 0)
	{
		i = s->b.size;
		while (i > 0)
		{
			s->b.array[i] = s->b.array[i - 1];
			i--;
		}
		s->b.array[0] = s->a.array[0];
		while (i < s->a.size - 1)
		{
			s->a.array[i] = s->a.array[i + 1];
			i++;
		}
		s->a.size--;
		s->b.size++;
	}
	print_operation(name, PUSH);
}

void	rotate(t_struct *s, t_stack_name name)
{
	int	tmp;
	int	i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[0];
		i = 0;
		while (i < s->a.size - 1)
		{
			s->a.array[i] = s->a.array[i + 1];
			i++;
		}
		s->a.array[s->a.size - 1] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0];
		i = 0;
		while (i < s->b.size - 1)
		{
			s->b.array[i] = s->b.array[i + 1];
			i++;
		}
		s->b.array[s->b.size - 1] = tmp;
	}
	print_operation(name, ROTATE);
}

void	reverse_rotate(t_struct *s, t_stack_name name)
{
	int	tmp;
	int	i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[s->a.size - 1];
		i = s->a.size - 1;
		while (i > 0)
		{
			s->a.array[i] = s->a.array[i - 1];
			i--;
		}
		s->a.array[0] = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[s->b.size - 1];
		i = s->b.size - 1;
		while (i > 0)
		{
			s->b.array[i] = s->b.array[i - 1];
			i--;
		}
		s->b.array[0] = tmp;
	}
	print_operation(name, REVERSE_ROTATE);
}
