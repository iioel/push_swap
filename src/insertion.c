/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/17 16:39:22 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

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
	while (s->b->size)
	{
		pos = get_maxpos(s->b);
		pos = get_minmove(pos, s->b->size);
	//	print_stack(s->b);
		moveb(s, pos);
	//	print_stack(s->b);
		pa(s);
	}
	//print_stack(s->a);
	//while (s->b->size)
	//	pa(s);
}
