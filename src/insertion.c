/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 21:02:10 by ycornamu         ###   ########.fr       */
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
	while (pos < (s->a->size - 1))
	{
		while (s->a->array[0] > s->a->array[1] && pos >= 0)
		{
			sa(s);
			if (pos > 0)
			{
				rra(s);
				pos--;
			}
		}
		sorted_nb++;
		while (pos < sorted_nb)
		{
			ra(s);
			pos++;
		}
	}
	if (pos > 0)
		ra(s);
}
