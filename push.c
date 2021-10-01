/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:52:05 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:55:45 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	pa: push 'a' - take the first element from the top of 'b' and put it on
*		the top of 'a'. Do nothing if 'b' is empty.
*	pb: push 'b' - take the first element from the top of 'a' and put it on
*		the top of 'b'. Do nothing if 'a' is empty.
*/

void	pa(t_info tab)
{
	if (tab->b->top)
	{
		add_card(tab->b->top->value, tab->b->top->order, tab->a);
		delete_top_card(tab->b);
		ft_printf("pa\n");
	}
}

void	pb(t_info tab)
{
	if (tab->a->top)
	{
		add_card(tab->a->top->value, tab->a->top->order, tab->b);
		delete_top_card(tab->a);
		ft_printf("pb\n");
	}
}
