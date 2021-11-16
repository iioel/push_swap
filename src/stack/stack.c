/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:15 by yoel              #+#    #+#             */
/*   Updated: 2021/11/16 14:43:04 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

static void	str2array(int array[], char *str[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(str[i]);
		i++;
	}
}

t_stack_list *init_stack(char *str[], int size)
{
	t_stack_list	*s;

	s = ft_calloc(1, sizeof(t_stack_list));
	s->a = ft_calloc(1, sizeof(t_stack));
	s->b = ft_calloc(1, sizeof(t_stack));
	s->a->array = ft_calloc(size, sizeof(int));
	s->b->array = ft_calloc(size, sizeof(int));
	s->a->size = size;
	s->b->size = size;
	str2array(s->a->array, str, size);
	return (s);
}
