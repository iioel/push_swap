/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:39:41 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/19 22:13:03 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int	abs(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	movea(t_stack_list *s, int i)
{
	while (i > 0)
	{
		ra(s);
		i--;
	}
	while (i < 0)
	{
		rra(s);
		i++;
	}
}

void	moveb(t_stack_list *s, int i)
{
	while (i > 0)
	{
		rb(s);
		i--;
	}
	while (i < 0)
	{
		rrb(s);
		i++;
	}
}

int	get_minmove(int pos, int size)
{
	if (pos < (size / 2))
		return (pos);
	else
		return (-(size - pos));
}
