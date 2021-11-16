/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:46:20 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 20:24:56 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

void	sort(t_stack_list *s)
{
	//bubble_sort(s);
	insertion_sort(s);
}

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

