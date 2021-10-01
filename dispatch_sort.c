/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:09:15 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/27 22:54:50 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_info tab, t_deck deck)
{
	if ((deck->top->value) > (deck->top->next->value))
		sa(tab);
}

static void	sort_three(t_info tab, t_deck deck)
{
	if ((deck->top->value) < (deck->top->next->value)
		&& (deck->top->value) > (deck->bottom->value))
		rra(tab);
	else if ((deck->top->value) > (deck->top->next->value)
		&& (deck->top->next->value) > (deck->bottom->value))
	{
		sa(tab);
		rra(tab);
	}
	else if ((deck->top->value) > (deck->top->next->value)
		&& (deck->top->value) > (deck->bottom->value))
		ra(tab);
	else if ((deck->top->value) < (deck->top->next->value)
		&& (deck->top->next->value) > (deck->bottom->value))
	{
		sa(tab);
		ra(tab);
	}
	else if ((deck->top->value) > (deck->top->next->value)
		&& (deck->top->value) < (deck->bottom->value))
		sa(tab);
}

static void	sort_four(t_info tab, t_deck deck)
{
	while (deck->top->value != deck_minimum(deck))
	{
		if (deck->min_index < 2)
			ra(tab);
		else
			rra(tab);
	}
	pb(tab);
	if (!is_sorted(deck))
		sort_three(tab, deck);
	pa(tab);
}

static void	sort_five(t_info tab, t_deck deck)
{
	while (deck->top->value != deck_minimum(deck))
	{
		if (deck->min_index <= (deck->size / 2))
			ra(tab);
		else
			rra(tab);
	}
	if (!is_sorted(deck))
	{
		pb(tab);
		sort_four(tab, deck);
		pa(tab);
	}
}

void	dispatch_sort(t_info tab, t_deck deck)
{
	if ((deck->size) == 2)
		sort_two(tab, deck);
	if ((deck->size) == 3)
		sort_three(tab, deck);
	if ((deck->size) == 4)
		sort_four(tab, deck);
	if ((deck->size) == 5)
		sort_five(tab, deck);
	if ((deck->size) > 5)
		sort_big(tab, deck);
}
