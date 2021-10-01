/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_deck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 20:09:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:51:23 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_top_card(t_deck deck)
{
	t_card	prev;

	if (NULL == deck->top)
		exit (-1);
	prev = deck->top;
	deck->top = deck->top->next;
	if (deck->top)
		deck->top->previous = NULL;
	if (prev == deck->bottom)
		deck->bottom = NULL;
	free (prev);
	(deck->size)--;
}

void	delete_bottom_card(t_deck deck)
{
	t_card	next;

	if (NULL == deck->bottom)
		exit (-1);
	next = deck->bottom;
	deck->bottom = deck->bottom->previous;
	if (deck->bottom)
		deck->bottom->next = NULL;
	if (next == deck->top)
		deck->top = NULL;
	free (next);
	(deck->size)--;
}

void	add_card(int val, int order, t_deck deck)
{
	t_card	tmp;

	tmp = (t_card)malloc(sizeof(struct s_card));
	if (!tmp)
		exit(-1);
	tmp->value = val;
	tmp->order = order;
	tmp->next = deck->top;
	tmp->previous = NULL;
	if (deck->top)
		deck->top->previous = tmp;
	deck->top = tmp;
	if (NULL == deck->bottom)
		deck->bottom = tmp;
	(deck->size)++;
}

void	add_bottom(int val, int order, t_deck deck)
{
	t_card	tmp;

	tmp = (t_card)malloc(sizeof(struct s_card));
	if (!tmp)
		exit(-1);
	tmp->value = val;
	tmp->order = order;
	tmp->next = NULL;
	tmp->previous = deck->bottom;
	if (deck->bottom)
		deck->bottom->next = tmp;
	deck->bottom = tmp;
	if (NULL == deck->top)
		deck->top = tmp;
	(deck->size)++;
}

void	fill_deck(t_info tab, t_deck deck)
{
	int		i;

	i = tab->count;
	while (i)
	{
		add_card(ft_atoi((tab->elements)[i]), 0, deck);
		(i)--;
	}
	deck->median = deck_median(tab, tab->a);
}
