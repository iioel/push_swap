/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:56:15 by yoel              #+#    #+#             */
/*   Updated: 2021/11/17 13:31:02 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <push_swap.h>

void	swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	pivot(int array, int *lo, int *hi)
{
	int mid;

	mid = (*lo + *hi) / 2;
//	if (array[mid] < array[*lo])
//		swap(&mid, lo);
//	if (array[hi] < array[*lo])
//		swap(hi, lo);
//	if (array[*hi] < array[mid])
//		swap(hi, &mid);
	return (mid);
}

int part()

void	quick_sort(t_stack_list *s, int lo, int high, int depth)
{
	int p;

	p = pivot(s->array)
	if (depth != 0)
	{
		quick_sort
	}

	quick_sort(
}
