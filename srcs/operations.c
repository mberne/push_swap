/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 14:17:39 by mberne            #+#    #+#             */
/*   Updated: 2021/09/16 13:20:02 by mberne           ###   ########lyon.fr   */
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
		tmp = s->a.array[0].value;
		s->a.array[0].value = s->a.array[1].value;
		s->a.array[1].value = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0].value;
		s->b.array[0].value = s->b.array[1].value;
		s->b.array[1].value = tmp;
	}
	print_operation(name, SWAP);
}

void	push(t_stack_name name, t_stack *send, t_stack *receive)
{
	int	i;

	if (send->size > 0)
	{
		i = receive->size;
		while (i > 0)
		{
			receive->array[i].value = receive->array[i - 1].value;
			i--;
		}
		receive->array[i].value = send->array[i].value;
		while (i < send->size - 1)
		{
			send->array[i].value = send->array[i + 1].value;
			i++;
		}
		send->size--;
		receive->size++;
		print_operation(name, PUSH);
	}
}

void	rotate(t_struct *s, t_stack_name name)
{
	int	tmp;
	int	i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[0].value;
		i = -1;
		while (++i < s->a.size - 1)
			s->a.array[i].value = s->a.array[i + 1].value;
		s->a.array[s->a.size - 1].value = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[0].value;
		i = -1;
		while (++i < s->b.size - 1)
			s->b.array[i].value = s->b.array[i + 1].value;
		s->b.array[s->b.size - 1].value = tmp;
	}
	print_operation(name, ROTATE);
}

void	reverse_rotate(t_struct *s, t_stack_name name)
{
	int	tmp;
	int	i;

	if ((name == A || name == BOTH) && s->a.size > 1)
	{
		tmp = s->a.array[s->a.size - 1].value;
		i = s->a.size;
		while (--i > 0)
			s->a.array[i].value = s->a.array[i - 1].value;
		s->a.array[0].value = tmp;
	}
	if ((name == B || name == BOTH) && s->b.size > 1)
	{
		tmp = s->b.array[s->b.size - 1].value;
		i = s->b.size;
		while (i > 0)
			s->b.array[i].value = s->b.array[i - 1].value;
		s->b.array[0].value = tmp;
	}
	print_operation(name, REVERSE_ROTATE);
}
