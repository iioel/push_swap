/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:15 by yoel              #+#    #+#             */
/*   Updated: 2021/12/06 12:56:04 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>
#include <stdlib.h>

int	is_nbr(char *str);
int	is_dup(int nb, int array[], int size);
int	str2array(int array[], char *str[], int size);

t_stack_list	*init_stack(char *str[], int size)
{
	t_stack_list	*s;

	s = ft_calloc(1, sizeof(t_stack_list));
	s->moves = 0;
	s->cpy = 0;
	s->a = ft_calloc(1, sizeof(t_stack));
	s->b = ft_calloc(1, sizeof(t_stack));
	s->a->array = ft_calloc(size, sizeof(int));
	s->b->array = ft_calloc(size, sizeof(int));
	s->a->size = size;
	s->b->size = 0;
	if (! s || ! s->a || ! s->b || ! s->a->array
		|| ! s->a->array || str2array(s->a->array, str, size))
	{
		clean_stack(s);
		return (NULL);
	}
	return (s);
}

t_stack_list	*copy_stack(t_stack_list *s)
{
	int				i;
	t_stack_list	*dup;

	i = -1;
	dup = ft_calloc(1, sizeof(t_stack_list));
	dup->moves = 0;
	dup->cpy = 1;
	dup->a = ft_calloc(1, sizeof(t_stack));
	dup->b = ft_calloc(1, sizeof(t_stack));
	dup->a->array = ft_calloc(s->a->size, sizeof(int));
	dup->b->array = ft_calloc(s->a->size, sizeof(int));
	dup->a->size = s->a->size;
	dup->b->size = 0;
	while (i++ < s->a->size)
		dup->a->array[i] = s->a->array[i];
	return (dup);
}

void	clean_stack(t_stack_list *s)
{
	free(s->a->array);
	free(s->b->array);
	free(s->a);
	free(s->b);
	free(s);
}
