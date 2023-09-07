/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:05:50 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 13:57:17 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_node **stack_to, t_node **stack_from)
{
	t_node	*middleman;
	t_node	*head_to;
	t_node	*head_from;

	if (stack_size(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	middleman = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = middleman;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		middleman->next = head_to;
		*stack_to = middleman;
	}
	return (0);
}

int	pa(t_node **stack_a, t_node **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_node **stack_b, t_node **stack_a)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
