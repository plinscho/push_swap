/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:25:42 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 15:03:12 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*next_min(t_node **stack_a);

void	index_init(t_node **stack_a)
{
	t_node	*node;
	int		index;

	node = next_min(stack_a);
	index = 0;
	while (node)
	{
		node->index = index++;
		node = next_min(stack_a);
	}
}

static	t_node	*next_min(t_node **stack_a)
{
	t_node	*head;
	t_node	*min;
	int		min_f;

	head = *stack_a;
	min = NULL;
	min_f = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!min_f || head->value < min->value))
			{
				min = head;
				min_f = 1;
			}
			head = head->next;
		}
	}
	return (min);
}
