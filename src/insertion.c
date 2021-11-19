/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/19 23:07:38 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_stack_list *s)
{
	int nb;
	int nb_min;
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
		if ((abs(pos_max) + 1) < abs(pos_min))
			moveb(s, pos_max);
		else
			moveb(s, pos_min);
		nb_min = get_min(s->b);
		pa(s);
		if ((abs(pos_max) + 1) < abs(pos_min) || nb_min > nb)
			ra(s);
	}
}
