/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:19 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/06 18:21:49 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int	value;
	int	index;
	struct s_node	*next;
}t_node;

typedef struct s_data
{
	int	elements;
	int biggest;
	int smallest;
	int	sorted;
	int	index;	
}t_info;

void	input_parse(t_info *data, char **argv);
void	print_stack(t_node **stack_a);

//UTILS.C
long	ft_atoi(const char *str);
void	ft_error();

//NODE.C
t_node	*new_node(int value);
void	ft_lstadd_back(t_node **stack, t_node *new);
t_node	*ft_lstlast(t_node *head);

//FREE.C
void	free_stack(t_node **stack);

//INDEX.C
void	index_init(t_node **stack_a);


#endif