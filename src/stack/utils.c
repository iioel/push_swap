/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:54:02 by ycornamu          #+#    #+#             */
/*   Updated: 2021/12/06 12:57:17 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

int	is_nbr(char *str)
{
	int	i;
	int	size;

	i = 0;
	if (str[0] == '-')
		i = 1;
	size = ft_strlen(str);
	while (i < size)
		if (! ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	is_dup(int nb, int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (nb == array[i++])
			return (1);
	return (0);
}

int	str2array(int array[], char *str[], int size)
{
	int		i;
	long	nb;

	i = 0;
	while (i < size)
	{
		if (! is_nbr(str[i]))
			return (1);
		nb = ft_atoi(str[i]);
		if (nb > INT_MAX || nb < INT_MIN || is_dup(nb, array, i))
			return (1);
		array[i] = nb;
		i++;
	}
	return (0);
}
