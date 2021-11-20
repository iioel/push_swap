/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:36:02 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/20 18:32:01 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

int	get_separator_min(t_stack *a, int n)
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

int	get_separator_max(t_stack *a, int n)
{
	int	i;
	int	max;
	int	val;

	max = get_max(a);
	while (n)
	{
		i = 0;
		val = get_min(a);
		while (i < a->size)
		{
			if (a->array[i] > val && a->array[i] < max)
				val = a->array[i];
			i++;
		}
		max = val;
		n--;
	}
	return (val);
}

void	push_seps(t_stack_list *s, int size)
{
	int	sep_min;
	int	sep_max;
	int	min_count;
	int	max_count;

	min_count = INT_MAX;
	max_count = INT_MAX;
	while (s->a->size)
	{
		if (! (min_count < size))
		{
			sep_min = get_separator_min(s->a, size);
			min_count = 0;
		}
		if (! (max_count < size))
		{
			sep_max = get_separator_max(s->a, size);
			max_count = 0;
		}
		if (s->a->array[0] <= sep_min)
			min_count++;
		else if (s->a->array[0] > sep_max)
			max_count++;
		if (s->a->array[0] <= sep_min || s->a->array[0] > sep_max)
		{
			pb(s);
			if (s->b->array[0] > sep_max && ! (s->a->array[0] > sep_max) && ! (s->a->array[0] <= sep_min))
				rr(s);
			else if (s->b->array[0] > sep_max)
				rb(s);
		}
		else
			ra(s);
	}
}

void	separate(t_stack_list *s, int n)
{
	int	size;

	size = s->a->size;
	push_seps(s, size / n);
}
