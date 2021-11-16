/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 22:34:00 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

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

int	get_minpos(t_stack *a)
{
	int	i;
	int	max;
	int	max_i;

	i = 0;
	max = a->array[0];
	max_i = 0;
	while (i < a->size)
	{
		if (a->array[i] < max)
		{
			max = a->array[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int get_minmove(int pos, int size)
{
	if (pos < (size / 2))
		return (pos);
	else
		return (-(size - pos));
}

void	insertion_sort(t_stack_list *s)
{
	int	pos;
	int sorted_nb;

	pos = 0;
	sorted_nb = 0;
	while (pos < (s->b->size - 1))
	{
		while (s->b->array[0] > s->b->array[1] && pos >= 0)
		{
			sb(s);
			if (pos > 0)
			{
				rrb(s);
				pos--;
			}
		}
		sorted_nb++;
		while (pos < sorted_nb)
		{
			rb(s);
			pos++;
		}
	}
	if (pos > 0)
		rb(s);
}

void	insertion_sortinb(t_stack_list *s)
{
	int	pos;

	pos = 0;
	while (s->a->size)
	{
		pos = get_minpos(s->a);
		pos = get_minmove(pos, s->a->size);
//		print_stack(s->a);
		movea(s, pos);
//		print_stack(s->a);
		pb(s);
	}
	while (s->b->size)
		pa(s);
}
