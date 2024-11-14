/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:37:57 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:32:05 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_operation(char operation_type,
	char stack_identifier, int is_reverse)
{
	if (operation_type == 'p')
		ft_putchar_fd('p', 1);
	else if (operation_type == 's')
		ft_putchar_fd('s', 1);
	else if (operation_type == 'r')
	{
		if (is_reverse < 0)
			write(1, "r", 1);
		write(1, "r", 1);
	}
	ft_putchar_fd(stack_identifier, 1);
	ft_putchar_fd('\n', 1);
}

void	swap_top_two_nodes(t_node **head, char stack_id)
{
	t_temp_data	temp;
	t_node		*first_node;
	t_node		*second_node;

	if (!*head || (*head)->next == NULL)
		return ;
	if (stack_id == 'a' || stack_id == 'b')
		display_operation('s', stack_id, 0);
	first_node = *head;
	second_node = first_node->next;
	temp.value = first_node->value;
	temp.original_pos = first_node->original_pos;
	temp.sorted_index = first_node->sorted_index;
	first_node->value = second_node->value;
	first_node->original_pos = second_node->original_pos;
	first_node->sorted_index = second_node->sorted_index;
	second_node->value = temp.value;
	second_node->original_pos = temp.original_pos;
	second_node->sorted_index = temp.sorted_index;
}

void	push(t_node **source_stack, t_node **destination_stack, char stack_id)
{
	t_node	*node_to_move;
	t_node	*new_top_node;

	if (stack_id == 'a' || stack_id == 'b')
		display_operation('p', stack_id, 0);
	node_to_move = *source_stack;
	if ((*source_stack)->next)
		new_top_node = (*source_stack)->next;
	else
		new_top_node = NULL;
	add_node_to_start(destination_stack, node_to_move);
	if (!new_top_node)
	{
		*source_stack = NULL;
		return ;
	}
	new_top_node->previous = NULL;
	*source_stack = new_top_node;
}

void	swap_top_nodes_of_both_stacks(t_node **first_stack,
					t_node **second_stack)
{
	swap_top_two_nodes(first_stack, 's');
	swap_top_two_nodes(second_stack, 's');
	write(1, "ss\n", 3);
}
