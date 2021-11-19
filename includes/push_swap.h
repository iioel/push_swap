/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:11:05 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/19 22:17:06 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void	print_stack(t_stack *a);

void	sort(t_stack_list *s);
char	is_sorted(t_stack *a);
void	insertion_sort(t_stack_list *s);

// separate.c
void	separate(t_stack_list *s, int n);
int		get_separator_min(t_stack *a, int n);
int		get_separator_min(t_stack *a, int n);

// utils.c
int		abs(int i);
void	movea(t_stack_list *s, int i);
void	moveb(t_stack_list *s, int i);
int		get_minmove(int pos, int size);

// get_minmax.c
int		get_max(t_stack *a);
int		get_min(t_stack *a);
int		get_maxpos(t_stack *a);
int		get_minpos(t_stack *a);

// get_nextminmax.c
int		get_nextmaxpos(t_stack *a, int median);
int		get_nextminpos(t_stack *a, int median);

#endif
