/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:59:36 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/06 14:47:10 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_num(char *argv);
static int	check_rep(long tmp, char **argv, int i, t_info *data);

void	input_parse(t_info *data, char **argv)
{
	int		i;
	long	tmp;
	
	i = 1;
	while (argv[i])
	{
		tmp = ft_atoi(argv[i]);
		if (check_num(argv[i]))
			ft_error();
		if (check_rep(tmp, argv, i, data))
			ft_error();
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_error();
		i++;
	}
}

static int	check_num(char *argv)
{
	int	i;
	
	i = 0;
	if (argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int	check_rep(long tmp, char **argv, int i, t_info *data)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return (1);
		if (tmp > data->biggest)
			data->biggest = tmp;
		else if (tmp < data->smallest)
			data->smallest = tmp;
		i++;
	}
	return (0);
}