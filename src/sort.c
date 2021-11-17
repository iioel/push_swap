/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:46:20 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/17 19:03:39 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

char	is_sorted(t_stack *a)
{
	int		i;

	i = 0;
	while (i < (a->size - 1))
	{
		if (! (a->array[i] <= a->array[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	sort_3(t_stack_list *s)
{
	if (s->a->array[0] > s->a->array[1] && s->a->array[0] > s->a->array[2]
		&& s->a->array[1] < s->a->array[2])
		ra(s);
	else
	{
		if (s->a->array[0] > s->a->array[1])
			sa(s);
		if (s->a->array[1] > s->a->array[2])
			rra(s);
		if (s->a->array[0] > s->a->array[1])
			sa(s);
	}
}

int	abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	sort_5(t_stack_list *s)
{
	int	pos;

	if (abs(get_minmove(get_minpos(s->a), s->a->size))
		< abs(get_minmove(get_maxpos(s->a), s->a->size)))
	{
		pos = get_minmove(get_minpos(s->a), s->a->size);
		movea(s, pos);
		pb(s);
		pos = get_minmove(get_minpos(s->a), s->a->size);
		movea(s, pos);
		pb(s);
	}
	else
	{
		pos = get_minmove(get_minpos(s->a), s->a->size);
		movea(s, pos);
		pb(s);
		pos = get_minmove(get_minpos(s->a), s->a->size);
		movea(s, pos);
		pb(s);
	}
	sort_3(s);
	insertion_sort(s);
	movea(s, 2);
}

void	sort(t_stack_list *s)
{
	if (! is_sorted(s->a))
	{
		if (s->a->size == 2)
			sa(s);
		else if (s->a->size == 3)
			sort_3(s);
		else if (s->a->size == 5)
			sort_5(s);
		else
		{
			if (s->a->size < 150)
				separate(s, 5);
			else
				separate(s, 12);
			insertion_sort(s);
		}
	}
}
