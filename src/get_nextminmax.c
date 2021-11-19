/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nextminmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:06:24 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/19 22:54:23 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int	get_nextminpos(t_stack *a, int median)
{
	int	i;
	int	min;
	int	min_i;

	i = 0;
	min = get_min(a);
	min_i = get_minpos(a);
	while (i < a->size)
	{
		if (a->array[i] >= min && a->array[i] <= median)
		{
			min = a->array[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

int	get_nextmaxpos(t_stack *a, int median)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max = get_max(a);
	max_i = get_maxpos(a);
	while (i < a->size)
	{
		if (a->array[i] <= max && a->array[i] > median)
		{
			max = a->array[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}
