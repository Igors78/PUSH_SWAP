/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 18:39:31 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:55:33 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	rra: reverse rotate 'a' - shift down all elements of 'a'. The last element
*		becomes the first one.
*	rrb: reverse rotate 'b' - shift down all elements of 'b'. The last element
*		becomes the first one.
*	rrr: rra and rrb at the same time.
*/

void	rra(t_info tab)
{
	if (tab->a->top && tab->a->bottom)
	{
		add_card(tab->a->bottom->value, tab->a->bottom->order, tab->a);
		delete_bottom_card(tab->a);
		ft_printf("rra\n");
	}
}

void	rrb(t_info tab)
{
	if (tab->b->top && tab->b->bottom)
	{
		add_card(tab->b->bottom->value, tab->b->bottom->order, tab->b);
		delete_bottom_card(tab->b);
		ft_printf("rrb\n");
	}
}

void	rrr(t_info tab)
{
	rra(tab);
	rrb(tab);
	ft_printf("rrr\n");
}
