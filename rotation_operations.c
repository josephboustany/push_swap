/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:40:14 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:05:41 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack, char stack_id)
{
	t_node	*top_node;
	t_node	*bottom_node;
	int		temp_last_value;
	size_t	temp_last_sorted_index;

	if (stack_id == 'a' || stack_id == 'b')
		display_operation('r', stack_id, 1);
	if (!(*stack)->next)
		return ;
	top_node = *stack;
	bottom_node = get_last_node(top_node);
	temp_last_value = bottom_node->value;
	temp_last_sorted_index = bottom_node->sorted_index;
	bottom_node->value = top_node->value;
	bottom_node->sorted_index = top_node->sorted_index;
	while (top_node->next != bottom_node)
	{
		top_node->value = top_node->next->value;
		top_node->sorted_index = top_node->next->sorted_index;
		top_node = top_node->next;
	}
	top_node->value = temp_last_value;
	top_node->sorted_index = temp_last_sorted_index;
}

void	reverse_rotate_stack(t_node **stack, char stack_id)
{
	t_node	*top_node;
	t_node	*bottom_node;
	int		temp_first_value;
	long	temp_first_sorted_index;

	if (stack_id == 'a' || stack_id == 'b')
		display_operation('r', stack_id, -1);
	if (!(*stack)->next)
		return ;
	top_node = *stack;
	bottom_node = get_last_node(top_node);
	temp_first_value = top_node->value;
	temp_first_sorted_index = top_node->sorted_index;
	top_node->value = bottom_node->value;
	top_node->sorted_index = bottom_node->sorted_index;
	while (bottom_node->previous != top_node)
	{
		bottom_node->value = bottom_node->previous->value;
		bottom_node->sorted_index = bottom_node->previous->sorted_index;
		bottom_node = bottom_node->previous;
	}
	bottom_node->value = temp_first_value;
	bottom_node->sorted_index = temp_first_sorted_index;
}

void	rotate_or_reverse_both_stacks(t_node **first_stack,
			t_node **second_stack, int direction)
{
	if (direction < 0)
	{
		reverse_rotate_stack(first_stack, 's');
		reverse_rotate_stack(second_stack, 's');
		write(1, "rrr\n", 4);
	}
	else
	{
		rotate_stack(first_stack, 's');
		rotate_stack(second_stack, 's');
		write(1, "rr\n", 4);
	}
}
