/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:12:59 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/06 19:17:45 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void		data_init(t_info *data, int argc);
static void	stack_init(t_node **stack_a, char **argv);
void		print_stack(t_node **stack_a);

int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_info	data;

	if (argc < 3 || argv[1][0] == '\0')
		return (1);
	data_init(&data, argc);
	input_parse(&data, argv);
	printf("Input passed!\n");
	stack_a = (t_node *)malloc(sizeof(t_node));
	stack_b = (t_node *)malloc(sizeof(t_node));
	stack_a = NULL;
	stack_b = NULL;
	stack_init(&stack_a, argv);
	print_stack(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
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
		printf("i: %i | val: %d\n", i, new->value);
		i++;
	}
	index_init(stack_a);
	printf("init done!\n");
}

void	data_init(t_info *data, int argc)
{
	data->elements = argc - 1;
	data->smallest = INT_MAX;
	data->biggest = INT_MIN;
	data->sorted = 0;
	data->index = 0;
}

void	print_stack(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		printf("val: %d | idx: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}
