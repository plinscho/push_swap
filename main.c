/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:12:59 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/20 21:45:22 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		data_init(t_info *data, int argc);
static void	stack_init(t_node **stack_a, char **argv);
int			check_sorted(t_node **stack_a);
//void		print_stack(t_node **stack_a);

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_info	data;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3 || argv[1][0] == '\0')
		return (1);
	data_init(&data, argc);
	input_parse(&data, argv);
	stack_init(&stack_a, argv);
	if (check_sorted(&stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		exit(1);
	}
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

int	check_sorted(t_node **stack_a)
{
	t_node	*node;
	t_node	*tmp;

	node = *stack_a;
	tmp = node->next;
	while (node->next)
	{
		if (node->value < tmp->value)
		{
			node = node->next;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

static void	stack_init(t_node **stack_a, char **argv)
{
	int		i;
	t_node	*new;

	i = 1;
	while (argv[i])
	{
		new = new_node(ft_atoi(argv[i]));
		ft_lstadd_back(stack_a, new);
		i++;
	}
	index_init(stack_a);
}

void	data_init(t_info *data, int argc)
{
	data->elements = argc - 1;
	data->smallest = INT_MAX;
	data->biggest = INT_MIN;
	data->sorted = 0;
	data->index = 0;
}
/*
void	print_stack(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		printf("val: %d | idx: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}*/
