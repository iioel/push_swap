/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:09:04 by yoel              #+#    #+#             */
/*   Updated: 2021/11/15 17:57:43 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void	fill_stack(t_stack *stack, char *str[], int size);

int main(int ac, char **av)
{
	t_stack	*stack[2];
	char	**str;
	int		i;

	i = 0;
	stack[0] = malloc(sizeof(t_stack));
	stack[1] = malloc(sizeof(t_stack));
	if (ac > 2)
		fill_stack(stack[0], av + 1, ac - 1);
	else if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		while (str[i])
			i++;
		fill_stack(stack[0], str, i);
	}
	i = 0;
	while (i < stack[0]->size)
		printf("%i\n", stack[0]->array[i++]);
}
