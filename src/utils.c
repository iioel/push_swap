/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:39:41 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/17 17:38:33 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	movea(t_stack_list *s, int i)
{
	while (i > 0)
	{
		ra(s);
		i--;
	}
	while (i < 0)
	{
		rra(s);
		i++;
	}
}

void	moveb(t_stack_list *s, int i)
{
	while (i > 0)
	{
		rb(s);
		i--;
	}
	while (i < 0)
	{
		rrb(s);
		i++;
	}
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
		if (a->array[i] > min)
		{
			min = a->array[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

int	get_minmove(int pos, int size)
{
	if (pos < (size / 2))
		return (pos);
	else
		return (-(size - pos));
}
