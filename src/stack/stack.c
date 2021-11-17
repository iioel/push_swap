/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:26:15 by yoel              #+#    #+#             */
/*   Updated: 2021/11/17 19:00:52 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>
#include <stdlib.h>

static int	is_nbr(char *str)
{
	int	i;
	int	size;

	i = 0;
	if (str[0] == '-')
		i = 1;
	size = ft_strlen(str);
	while (i < size)
		if (! ft_isdigit(str[i++]))
			return (0);
	return (1);
}

static int	is_dup(int nb, int array[], int size)
{
	int	i;

	i = 0;
	while (i < size)
		if (nb == array[i++])
			return (1);
	return (0);
}

static int	str2array(int array[], char *str[], int size)
{
	int		i;
	long	nb;

	i = 0;
	while (i < size)
	{
		if (! is_nbr(str[i]))
			return (1);
		nb = ft_atoi(str[i]);
		if (nb > INT_MAX || nb < INT_MIN || is_dup(nb, array, i))
			return (1);
		array[i] = nb;
		i++;
	}
	return (0);
}

void	clean_stack(t_stack_list *s)
{
	free(s->a->array);
	free(s->b->array);
	free(s->a);
	free(s->b);
	free(s);
}

t_stack_list	*init_stack(char *str[], int size)
{
	t_stack_list	*s;

	s = ft_calloc(1, sizeof(t_stack_list));
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
