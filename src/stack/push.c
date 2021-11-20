/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:32:27 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/20 15:48:44 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	pa(t_stack_list *s)
{
	int	i;

	if (s->b->size > 0)
	{
		i = ++s->a->size - 1;
		while (i > 0)
		{
			s->a->array[i] = s->a->array[i - 1];
			i--;
		}
		s->a->array[0] = s->b->array[0];
		while (i < s->b->size - 1)
		{
			s->b->array[i] = s->b->array[i + 1];
			i++;
		}
		s->b->size--;
		if (! s->cpy)
			ft_putendl_fd("pa", 1);
		s->moves++;
	}
}

void	pb(t_stack_list *s)
{
	int	i;

	if (s->a->size > 0)
	{
		i = ++s->b->size - 1;
		while (i > 0)
		{
			s->b->array[i] = s->b->array[i - 1];
			i--;
		}
		s->b->array[0] = s->a->array[0];
		while (i < s->a->size - 1)
		{
			s->a->array[i] = s->a->array[i + 1];
			i++;
		}
		s->a->size--;
		if (! s->cpy)
			ft_putendl_fd("pb", 1);
		s->moves++;
	}
}
