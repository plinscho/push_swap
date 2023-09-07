/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:06:31 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 13:58:14 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = stack_end(stack);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}

int	reverse_rot(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (stack_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = stack_end(stack);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	ra(t_node **stack_a)
{
	if (rotate(stack_a) == -1)
	{
		return (-1);
	}
	write(1, "ra\n", 3);
	return (0);
}

int	rra(t_node **stack_a)
{
	if (reverse_rot(stack_a) == -1)
		return (1);
	write(1, "rra\n", 4);
	return (0);
}

int	rb(t_node **stack_b)
{
	if (rotate(stack_b) == -1)
	{
		return (-1);
	}
	write(1, "rb\n", 3);
	return (0);
}
