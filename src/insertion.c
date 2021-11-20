/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/20 18:33:01 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_stack_list *s)
{
	int	nb;
	int	nb_min;
	int	pos_max;
	int	pos_min;

	nb = get_separator_min(s->b, s->b->size / 2);
	pos_max = 0;
	pos_min = 0;
	while (s->b->size)
	{
		pos_max = get_nextmaxpos(s->b, nb);
		pos_min = get_nextminpos(s->b, nb);
		pos_max = get_minmove(pos_max, s->b->size);
		pos_min = get_minmove(pos_min, s->b->size);
		nb_min = get_min(s->b);
		if ((abs(pos_max) + 1) < abs(pos_min))
		{
			if (pos_max > 0 && s->a->array[0] > s->a->array[1])
			{
				rr(s);
				pos_max--;
			}
			else if (s->a->array[0] > s->a->array[1])
				ra(s);
			moveb(s, pos_max);
		}
		else
		{
			if (pos_min > 0 && nb_min > nb && s->a->array[0] > s->a->array[1])
			{
				rr(s);
				pos_min--;
			}
			else if (s->a->array[0] > s->a->array[1])
				ra(s);
			moveb(s, pos_min);
		}
		pa(s);
	}
	if (s->a->array[0] > s->a->array[1])
		ra(s);
}
/*
void	insertion_sort(t_stack_list *s)
{
	int	pos;

	while (s->b->size)
	{
		pos = get_maxpos(s->b);
		pos = get_minmove(pos, s->b->size);
		moveb(s, pos);
		pa(s);
	}
}
*/
