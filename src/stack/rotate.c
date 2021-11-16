/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:44:59 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 10:02:04 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *array)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = array->array[0];
	while (i < array->size - 1)
	{
		array->array[i] = array->array[i + 1];
		i++;
	}
	array->array[i] = tmp;
}

void	ra(t_stack_list *s)
{
	ft_putstr_fd("ra", 1);
	rotate(s->a);
}

void	rb(t_stack_list *s)
{
	ft_putstr_fd("rb", 1);
	rotate(s->a);
}

void	rr(t_stack_list *s)
{
	ft_putstr_fd("rr", 1);
	rotate(s->a);
	rotate(s->b);
}
