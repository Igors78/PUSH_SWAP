/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contract.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 12:45:17 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/27 21:02:58 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_if_valid_int(int argc, char **argv)
{
	int		i;

	if (argc < 3)
		exit (-1);
	i = 1;
	while (i < argc)
	{	
		if (!(ft_atoi(argv[i])) && argv[i][0] != '0')
		{
			ft_putstr_fd("Error\n", 2);
			exit (-1);
		}
		i++;
	}
}

static void	check_if_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(ft_isdigit(argv[i][j])))
			{
				if ((argv[i][j]) == '-' || (argv[i][j]) == '+')
					j++;
				else
				{
					ft_putstr_fd("Error\n", 2);
					exit (-1);
				}
			}
			j++;
		}
		i++;
	}
}

static void	check_for_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr_fd("Error\n", 2);
				exit (-1);
			}
			j++;
		}
		i++;
	}
}

static void	check_if_sorted(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc - 1 && ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
		i++;
	if (i == argc - 1)
	{
		exit (-1);
	}
}

void	check_contract(int argc, char **argv)
{
	check_if_valid_int(argc, argv);
	check_if_digits(argc, argv);
	check_for_duplicates(argc, argv);
	check_if_sorted(argc, argv);
}
