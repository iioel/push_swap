/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:36:02 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/17 17:37:05 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

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

int	get_separator(t_stack *a, int n)
{
	int	i;
	int	min;
	int	val;

	min = get_min(a);
	while (n)
	{
		i = 0;
		val = get_max(a);
		while (i < a->size)
		{
			if (a->array[i] < val && a->array[i] > min)
				val = a->array[i];
			i++;
		}
		min = val;
		n--;
	}
	return (val);
}

void	push_sep(t_stack_list *s, int sep)
{
	int	j;

	j = 0;
	while (j < s->a->size)
	{
		if (s->a->array[0] <= sep)
			pb(s);
		else
		{
			ra(s);
			j++;
		}
	}
}

void	separate(t_stack_list *s, int n)
{
	int	i;
	int	sep;
	int	size;

	i = 0;
	size = s->a->size;
	while (i <= n)
	{
		sep = get_separator(s->a, size / n);
		push_sep(s, sep);
		i++;
	}
	push_sep(s, get_max(s->a));
}
