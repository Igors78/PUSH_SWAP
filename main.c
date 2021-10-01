/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:44:12 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 18:53:55 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Technically the challenge to be associated with the deque(further DECK),
*	not stack, as we have access not only to the top, but to the bottom of deck
*	as well.
*	I really suggest to think about it as about deck of playing cards and 
*	empty bank(deck) to put cards temporarily in. Just like in kind of solitaire
*	game. Therefore structure used for deck is doubly linked list.
*/

static void	delete_deck(t_deck deck)
{
	t_card	tmp;
	t_card	next;

	tmp = deck->top;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(deck);
	deck = NULL;
}

int	is_sorted(t_deck deck)
{
	t_card	tmp;
	int		i;

	i = 1;
	tmp = deck->top->next;
	while (tmp && (tmp->previous->order < tmp->order))
	{
		i++;
		tmp = tmp->next;
	}
	if (i == deck->size)
		return (1);
	return (0);
}

int	is_sorted_descend(t_deck deck)
{
	t_card	tmp;
	int		i;

	i = 1;
	tmp = deck->top->next;
	while (tmp && (tmp->previous->order > tmp->order))
	{
		i++;
		tmp = tmp->next;
	}
	if (i == deck->size)
		return (1);
	return (0);
}

void	print_deck(t_deck deck)
{
	t_card	tmp;

	tmp = deck->top;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_info	tab;

	check_contract(argc, argv);
	tab = NULL;
	tab = initialize_info(tab, argv);
	if (!tab)
		return (-1);
	tab->count = argc - 1;
	fill_deck(tab, tab->a);
	dispatch_sort(tab, tab->a);
	delete_deck(tab->a);
	delete_deck(tab->b);
	free(tab);
	return (0);
}
