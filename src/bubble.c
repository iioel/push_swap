/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:04:58 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 16:19:15 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

void	bubble_sort(t_stack_list *s)
{
	int	i;

	i = 0;
	while (! is_sorted(s->a))
	{
		i = 0;
		while (i < s->a->size)
		{
			if (s->a->array[0] > s->a->array[1] && i < (s->a->size - 1))
			{
				sa(s);
			}
			if (i == 0 && is_sorted(s->a))
				break;
			ra(s);
			i++;
		}
	}
}
