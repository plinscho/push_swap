/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SWAP.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:56:30 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 13:58:32 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*top;
	t_node	*next;
	int		tmp_val;
	int		tmp_ind;

	if (stack_size(*stack) < 2)
		return (1);
	top = *stack;
	next = top->next;
	tmp_val = top->value;
	tmp_ind = top->index;
	top->index = next->index;
	top->value = next->value;
	next->value = tmp_val;
	next->index = tmp_ind;
	return (0);
}

int	sa(t_node **stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_node **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_node **stack_a, t_node **stack_b)
{
	if ((stack_size(*stack_a) < 2) || (stack_size(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (0);
}
