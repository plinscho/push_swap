/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:18:29 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 15:06:29 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size;
	int		bit;

	tmp = *stack_a;
	bit = 1;
	while (stack_sorted(stack_a) != 1)
	{
		size = stack_size(*stack_a);
		while (size > 0 && tmp != NULL)
		{
			if (tmp->index & bit)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
			tmp = *stack_a;
			size--;
		}
		while (stack_size(*stack_b))
			pa(stack_a, stack_b);
		tmp = *stack_a;
		bit = bit << 1;
		size--;
	}
}

int	stack_size(t_node *stack)
{
	t_node	*node;
	int		i;

	node = stack;
	i = 0;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
