/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/12/06 12:36:10 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void	move_max(t_stack_list *s, int *pos_max)
{
	if (*pos_max > 0 && s->a->array[0] > s->a->array[1])
	{
		rr(s);
		(*pos_max)--;
	}
	else if (s->a->array[0] > s->a->array[1])
		ra(s);
	moveb(s, *pos_max);
}

void	move_min(t_stack_list *s, int *pos_min, int nb_min, int nb)
{
	if (*pos_min > 0 && nb_min > nb && s->a->array[0] > s->a->array[1])
	{
		rr(s);
		(*pos_min)--;
	}
	else if (s->a->array[0] > s->a->array[1])
		ra(s);
	moveb(s, *pos_min);
}

void	insertion_sort(t_stack_list *s)
{
	int	nb;
	int	nb_min;
	int	pos_max;
	int	pos_min;

	nb = get_separator_min(s->b, s->b->size / 2);
	while (s->b->size)
	{
		pos_max = get_minmove(get_nextmaxpos(s->b, nb), s->b->size);
		pos_min = get_minmove(get_nextminpos(s->b, nb), s->b->size);
		nb_min = get_min(s->b);
		if ((abs(pos_max) + 1) < abs(pos_min))
			move_max(s, &pos_max);
		else
			move_min(s, &pos_min, nb_min, nb);
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
