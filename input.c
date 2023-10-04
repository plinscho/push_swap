/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:59:36 by plinscho          #+#    #+#             */
/*   Updated: 2023/10/04 18:12:46 by plinscho         ###   ########.fr       */
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

long	ft_atoi(const char *str)
{
	long	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * sign);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
