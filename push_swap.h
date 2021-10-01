/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 10:33:10 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/29 19:31:14 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/libft.h"

typedef struct s_card
{
	long			order;
	int				value;
	struct s_card	*next;
	struct s_card	*previous;
}					*t_card;

typedef struct s_deck
{
	int		size;
	int		min_index;
	int		max_bits;
	int		median;
	t_card	top;
	t_card	bottom;
}					*t_deck;

typedef struct s_info
{
	t_deck	a;
	t_deck	b;
	t_card	current;
	int		count;
	char	**elements;
}				*t_info;

void	check_contract(int argc, char **argv);
t_info	initialize_info(t_info tab, char **argv);
void	fill_deck(t_info tab, t_deck deck);
void	add_card(int val, int order, t_deck deck);
void	add_bottom(int val, int order, t_deck deck);
void	delete_top_card(t_deck deck);
void	delete_bottom_card(t_deck deck);
void	sa(t_info tab);
void	sb(t_info tab);
void	ss(t_info tab);
void	pa(t_info tab);
void	pb(t_info tab);
void	ra(t_info tab);
void	rb(t_info tab);
void	rr(t_info tab);
void	rra(t_info tab);
void	rrb(t_info tab);
void	rrr(t_info tab);
void	print_deck(t_deck deck);
void	dispatch_sort(t_info tab, t_deck deck);
int		is_sorted(t_deck deck);
int		is_sorted_descend(t_deck deck);
int		deck_minimum(t_deck deck);
int		deck_maximum(t_deck deck);
void	sort_big(t_info tab, t_deck deck);
void	keep_b_order(t_info tab);
int		deck_size(t_deck deck);
void	multi_cond(t_info tab);
int		deck_median(t_info tab, t_deck deck);

#endif
