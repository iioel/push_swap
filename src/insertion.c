/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isertion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:21:12 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/17 19:02:18 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_stack_list *s)
{
	int	pos;

	pos = 0;
	while (s->b->size)
	{
		pos = get_maxpos(s->b);
		pos = get_minmove(pos, s->b->size);
		moveb(s, pos);
		pa(s);
	}
}
