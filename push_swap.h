/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:13:19 by plinscho          #+#    #+#             */
/*   Updated: 2023/09/07 15:05:43 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}t_node;

typedef struct s_data
{
	int	elements;
	int	biggest;
	int	smallest;
	int	sorted;
	int	index;	
}t_info;

//	main.c
void	print_stack(t_node **stack_a);
long	ft_atoi(const char *str);
void	ft_error(void);
void	free_stack(t_node **stack);
void	index_init(t_node **stack_a);
int		stack_size(t_node *stack);
void	sort(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);

//	input.c
void	input_parse(t_info *data, char **argv);

//	nodes.c
t_node	*new_node(int value);
void	ft_lstadd_back(t_node **stack, t_node *new_node);
t_node	*ft_lstlast(t_node *head);
t_node	*node_max(t_node **stack);
t_node	*node_min(t_node **stack);

//	sort.c
void	sort(t_node **stack_a, t_node **stack_b);

//	sort_utils.c
int		put_node_top_a(t_node **stack_a, t_node *node);
int		put_node_top_b(t_node **stack_b, t_node *node);
int		stack_sorted(t_node **stack);
t_node	*stack_end(t_node **stack);

//	swap.c
int		swap(t_node **stack);
int		sa(t_node **stack_a);
int		sb(t_node **stack_b);
int		ss(t_node **stack_a, t_node **stack_b);

//	rotate..c
int		rotate(t_node **stack);
int		reverse_rot(t_node **stack);
int		ra(t_node **stack_a);
int		rra(t_node **stack_a);
int		rb(t_node **stack_b);

//	push.c
int		push(t_node **stack_to, t_node **stack_from);
int		pa(t_node **stack_a, t_node **stack_b);
int		pb(t_node **stack_b, t_node **stack_a);

#endif