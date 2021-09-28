/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberne <mberne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:01:36 by mberne            #+#    #+#             */
/*   Updated: 2021/09/28 11:39:06 by mberne           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *s)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	if (s[0] == '-')
		j++;
	if ((i == 1 && j == 1) || i == 0)
		return (0);
	while (ft_isdigit(s[j]))
		j++;
	if (i == j)
		return (1);
	return (0);
}
