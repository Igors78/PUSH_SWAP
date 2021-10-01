/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 12:20:02 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:56:30 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_array(int *arr, long size)
{
	int		tmp;
	long	i;
	int		swap;

	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swap = 1;
			}
			i++;
		}
	}
	return (arr);
}

static void	desired_order(t_info tab, t_deck deck, int *arr, long size)
{
	long	i;

	tab->current = deck->top;
	while (tab->current)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i++] == tab->current->value)
				tab->current->order = i;
		}
		tab->current = tab->current->next;
	}
}

int	deck_median(t_info tab, t_deck deck)
{
	int		*arr;
	int		result;
	long	i;

	i = 0;
	arr = NULL;
	arr = (int *)malloc(sizeof(int) * deck_size(deck));
	if (NULL == arr)
		exit(-1);
	tab->current = deck->top;
	while (tab->current)
	{
		arr[i++] = tab->current->value;
		tab->current = tab->current->next;
	}
	sort_array(arr, i);
	desired_order(tab, deck, arr, i);
	result = arr[i / 2];
	free (arr);
	return (result);
}
