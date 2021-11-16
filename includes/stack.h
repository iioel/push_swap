/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:44:33 by yoel              #+#    #+#             */
/*   Updated: 2021/11/16 10:27:37 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"

typedef struct s_stack
{
	int	*array;
	int	size;
}				t_stack;

typedef struct s_stack_list
{
	t_stack	*a;
	t_stack	*b;
}				t_stack_list;

// stack.c
t_stack_list *init_stack(char *str[], int size);

// swap.c
void	sa(t_stack_list *s);
void	sb(t_stack_list *s);
void	ss(t_stack_list *s);

// push.c
void pa(t_stack_list *s);
void pb(t_stack_list *s);

// rotate.c
void	ra(t_stack_list *s);
void	rb(t_stack_list *s);
void	rr(t_stack_list *s);

// rotate_rev.c
void	rra(t_stack_list *s);
void	rrb(t_stack_list *s);
void	rrr(t_stack_list *s);

#endif
