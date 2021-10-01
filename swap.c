/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 13:18:04 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:54:50 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	sa: swap 'a' - swap the first 2 elements at the top of deck 'a'. Do nothing
*		if there is only one or no elements.
*	sb: swap 'b' - swap the first 2 elements at the top of deck 'b'. Do nothing
*		if there is only one or no elements.
*	ss: sa and sb at the same time.
*/

void	sa(t_info tab)
{
	int	tmp;
	int	order;

	if ((tab->a->size) > 1)
	{
		tmp = tab->a->top->value;
		order = tab->a->top->order;
		tab->a->top->value = tab->a->top->next->value;
		tab->a->top->order = tab->a->top->next->order;
		tab->a->top->next->value = tmp;
		tab->a->top->next->order = order;
		ft_printf("sa\n");
	}
}

void	sb(t_info tab)
{
	int	tmp;
	int	order;

	if ((tab->b->size) > 1)
	{
		tmp = tab->b->top->value;
		order = tab->b->top->order;
		tab->b->top->value = tab->b->top->next->value;
		tab->b->top->order = tab->b->top->next->order;
		tab->b->top->next->value = tmp;
		tab->b->top->next->order = order;
		ft_printf("sb\n");
	}
}

void	ss(t_info tab)
{
	sa(tab);
	sb(tab);
	ft_printf("ss\n");
}
