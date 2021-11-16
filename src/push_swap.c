/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:09:04 by yoel              #+#    #+#             */
/*   Updated: 2021/11/16 18:06:59 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void print_stack(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
		printf("%i ", a->array[i++]);
	printf("\n");
}

int main(int ac, char **av)
{
	t_stack_list	*stack;
	char			**str;
	int				i;

	i = 0;
	if (ac >= 2)
	{
		if (ac > 2)
			stack = init_stack(av + 1, ac - 1);
		else
		{
			str = ft_split(av[1], ' ');
			while (str[i])
				i++;
			stack = init_stack(str, i);
		}
		sort(stack);
		//print_stack(stack->a);
	}
}
