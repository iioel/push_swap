/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:58:30 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 10:01:34 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate_rev(t_stack *array)
{
	int	i;
	int	tmp;

	i = array->size - 1;
	tmp = array->array[array->size - 1];
	while (i > 0)
	{
		array->array[i] = array->array[i - 1];
		i--;
	}
	array->array[0] = tmp;
}

void	rra(t_stack_list *s)
{
	ft_putstr_fd("rra", 1);
	rotate_rev(s->a);
}

void	rrb(t_stack_list *s)
{
	ft_putstr_fd("rrb", 1);
	rotate_rev(s->a);
}

void	rrr(t_stack_list *s)
{
	ft_putstr_fd("rrr", 1);
	rotate_rev(s->a);
	rotate_rev(s->b);
}
