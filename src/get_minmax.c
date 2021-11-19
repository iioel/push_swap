/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:05:16 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/19 22:55:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	get_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] < min)
			min = a->array[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->array[0];
	while (i < a->size)
	{
		if (a->array[i] > max)
			max = a->array[i];
		i++;
	}
	return (max);
}

int	get_maxpos(t_stack *a)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max = a->array[0];
	max_i = 0;
	while (i < a->size)
	{
		if (a->array[i] > max)
		{
			max = a->array[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int	get_minpos(t_stack *a)
{
	int	i;
	int	min;
	int	min_i;

	i = 0;
	min = a->array[0];
	min_i = 0;
	while (i < a->size)
	{
		if (a->array[i] < min)
		{
			min = a->array[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}
