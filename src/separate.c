/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:36:02 by ycornamu          #+#    #+#             */
/*   Updated: 2021/12/06 15:49:40 by ycornamu         ###   ########.fr       */
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

void	check_seps(t_stack_list *s, int size, int *sep_min, int *sep_max)
{
	static int	min_count;
	static int	max_count;

	if (s == NULL)
	{
		min_count = INT_MAX;
		max_count = INT_MAX;
		return ;
	}
	if (! (min_count < size))
	{
		*sep_min = get_separator_min(s->a, size);
		min_count = 0;
	}
	if (! (max_count < size))
	{
		*sep_max = get_separator_max(s->a, size);
		max_count = 0;
	}
	if (s->a->array[0] <= *sep_min)
		min_count++;
	else if (s->a->array[0] > *sep_max)
		max_count++;
}

void	push_seps(t_stack_list *s, int size)
{
	int	sep_min;
	int	sep_max;

	check_seps(NULL, 0, 0, 0);
	while (s->a->size)
	{
		check_seps(s, size, &sep_min, &sep_max);
		if (s->a->array[0] <= sep_min || s->a->array[0] > sep_max)
		{
			pb(s);
			if (s->b->array[0] > sep_max && ! (s->a->array[0] > sep_max)
				&& ! (s->a->array[0] <= sep_min))
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
