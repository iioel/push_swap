/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:11:05 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 17:44:19 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

void print_stack(t_stack *a);

void	sort(t_stack_list *s);
char	is_sorted(t_stack *a);
void	bubble_sort(t_stack_list *s);
void	insertion_sort(t_stack_list *s);

#endif
