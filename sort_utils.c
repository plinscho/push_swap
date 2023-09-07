/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:48:17 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/01 15:48:28 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	put_node_top_a(t_node **stack_a, t_node *node)
{
	while (*stack_a != node)
	{
		ra(stack_a);
	}
	return (0);
}

int	put_node_top_b(t_node **stack_b, t_node *node)
{
	while (*stack_b != node)
	{
		rb(stack_b);
	}
	return (0);
}

int	stack_sorted(t_node **stack)
{
	t_node	*node;

	node = *stack;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

t_node	*stack_end(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}
