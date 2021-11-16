/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:15 by yoel              #+#    #+#             */
/*   Updated: 2021/11/15 18:14:58 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	fill_stack(t_stack *stack, char *str[], int size)
{
	int i;

	i = 0;
	stack->array = malloc(size * sizeof(int));
	while (i < size)
	{
		stack->array[i] = ft_atoi(str[i]);
		i++;
	}
	stack->size = size;
}


