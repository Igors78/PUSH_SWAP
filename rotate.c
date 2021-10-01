/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:39:05 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:55:21 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	ra: rotate 'a' - shift up all elements of 'a' by 1. The first element
*		becomes the last one.
*	rb: rotate 'b' - shift up all elements of 'b' by 1. The first element
*		becomes the last one.
*	rr: ra and rb at the same time.
*/

void	ra(t_info tab)
{
	if (tab->a->top && tab->a->bottom)
	{
		add_bottom(tab->a->top->value, tab->a->top->order, tab->a);
		delete_top_card(tab->a);
		ft_printf("ra\n");
	}
}

void	rb(t_info tab)
{
	if (tab->b->top && tab->b->bottom)
	{
		add_bottom(tab->b->top->value, tab->b->top->order, tab->b);
		delete_top_card(tab->b);
		ft_printf("rb\n");
	}
}

void	rr(t_info tab)
{
	ra(tab);
	rb(tab);
	ft_printf("rr\n");
}
