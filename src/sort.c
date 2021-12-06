/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:46:20 by ycornamu          #+#    #+#             */
/*   Updated: 2021/12/06 13:02:48 by ycornamu         ###   ########.fr       */
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
	if (s->b->array[0] > s->a->array[0])
		movea(s, 2);
}

static int	get_best_sep(t_stack_list *s)
{
	int				i;
	int				nb;
	int				min_moves;
	t_stack_list	*scpy;

	i = 1;
	min_moves = 0;
	while (i <= 25)
	{
		scpy = copy_stack(s);
		separate(scpy, i);
		insertion_sort(scpy);
		if (scpy->moves < min_moves || ! min_moves)
		{
			nb = i;
			min_moves = scpy->moves;
		}
		clean_stack(scpy);
		i++;
	}
	return (nb);
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
			separate(s, get_best_sep(s));
			insertion_sort(s);
		}
	}
}
