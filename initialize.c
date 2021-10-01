/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:19:20 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 19:33:02 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_info_fields(t_info tab, char **argv)
{
	tab->a->top = NULL;
	tab->b->top = NULL;
	tab->a->bottom = NULL;
	tab->b->bottom = NULL;
	tab->a->min_index = 0;
	tab->b->min_index = 0;
	tab->a->median = 0;
	tab->b->median = 0;
	tab->a->size = 0;
	tab->b->size = 0;
	tab->count = 0;
	tab->elements = argv;
	tab->current = NULL;
}

t_info	initialize_info(t_info tab, char **argv)
{
	tab = (t_info)malloc(sizeof(struct s_info));
	if (!tab)
		return (NULL);
	tab->a = NULL;
	tab->b = NULL;
	tab->a = (t_deck)malloc(sizeof(struct s_deck));
	if (!(tab->a))
	{
		free(tab);
		return (NULL);
	}
	tab->b = (t_deck)malloc(sizeof(struct s_deck));
	if (!(tab->b))
	{
		free(tab->a);
		free(tab);
		return (NULL);
	}
	init_info_fields(tab, argv);
	return (tab);
}

int	deck_minimum(t_deck deck)
{
	t_card	tmp;
	int		min;
	int		i;

	i = 0;
	deck->min_index = 0;
	min = deck->top->value;
	tmp = deck->top;
	while (tmp)
	{
		if (min > tmp->value)
		{
			min = tmp->value;
			deck->min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}

int	deck_size(t_deck deck)
{
	t_card	tmp;
	int		i;

	i = 0;
	tmp = deck->top;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
