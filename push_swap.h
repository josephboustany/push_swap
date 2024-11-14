/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:30:42 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:27:39 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	long			sorted_index;
	size_t			original_pos;
	int				value;
	struct s_node	*previous;
	struct s_node	*next;
}	t_node;

typedef struct s_temp_data
{
	size_t	original_pos;
	int		value;
	long	sorted_index;
}	t_temp_data;

t_node	*find_next_lowest_node(t_node *head);
t_node	*find_minimum_value_node(t_node *head);
t_node	*create_new_node(int value, size_t original_pos, long sorted_index);
t_node	*get_last_node(t_node *head);
t_node	*create_node_from_arg(char *arg_str, size_t *position);
t_node	*build_linked_list(size_t number_elements, char **elements);
int		ft_atoi_with_check(const char *input_str, long *result);
int		is_sorted(t_node *node);
void	free_string_array(char **string_array);
void	add_node_to_end(t_node **head, t_node *new_node);
void	add_node_to_start(t_node **head, t_node *new_node);
void	clear_list(t_node **head);
int		check_for_duplicate(t_node **head, int number);
void	assign_sorted_order(t_node **head, size_t total_nodes);
void	display_operation(char operation_type, char stack_identifier,
			int is_reverse);
void	swap_top_two_nodes(t_node **head, char stack_id);
void	push(t_node **source_stack, t_node **destination_stack, char stack_id);
void	swap_top_nodes_of_both_stacks(t_node **first_stack,
			t_node **second_stack);
void	rotate_stack(t_node **stack, char stack_id);
void	reverse_rotate_stack(t_node **stack, char stack_id);
void	rotate_or_reverse_both_stacks(t_node **first_stack,
			t_node **second_stack, int direction);
void	sort_three_elements(t_node **stack, int values[3]);
void	move_two_smallest_out_of_five_to_b(t_node **source_stack,
			t_node **destination_stack, size_t total_size);
void	sort_small_stack(t_node **stackA, t_node **stackB, size_t total_size);
void	radix_sort(t_node **stackA, int total_elements);
void	sort_stack(int element_count, char **elements);

#endif
