/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:45:33 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:11:55 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_node **stack, int values[3])
{
	if (values[0] > values[1] && values[0] < values[2])
		swap_top_two_nodes(stack, 'a');
	else if (values[0] > values[1] && values[0] > values[2])
	{
		if (values[1] > values[2])
		{
			swap_top_two_nodes(stack, 'a');
			reverse_rotate_stack(stack, 'a');
		}
		else
			rotate_stack(stack, 'a');
	}
	else if (values[0] < values[1] && values[0] < values[2])
	{
		swap_top_two_nodes(stack, 'a');
		rotate_stack(stack, 'a');
	}
	else
		reverse_rotate_stack(stack, 'a');
}

void	move_two_smallest_out_of_five_to_b(t_node **source_stack,
			t_node **destination_stack, size_t total_size)
{
	size_t	count;
	t_node	*smallest_node;

	count = 0;
	while (count < total_size - 3)
	{
		smallest_node = find_minimum_value_node(*source_stack);
		if (smallest_node->original_pos > total_size / 2)
		{
			while ((*source_stack)->value != smallest_node->value)
				reverse_rotate_stack(source_stack, 'a');
		}
		else
		{
			while ((*source_stack)->value != smallest_node->value)
				rotate_stack(source_stack, 'a');
		}
		push(source_stack, destination_stack, 'b');
		count++;
		free(smallest_node);
	}
}

void	sort_small_stack(t_node **stackA, t_node **stackB, size_t total_size)
{
	int		top_three_values[3];
	size_t	count;

	count = 0;
	if (total_size > 3)
		move_two_smallest_out_of_five_to_b(stackA, stackB, total_size);
	top_three_values[0] = (*stackA)->value;
	top_three_values[1] = (*stackA)->next->value;
	top_three_values[2] = (*stackA)->next->next->value;
	if (!is_sorted(*stackA))
		sort_three_elements(stackA, top_three_values);
	if (total_size > 3)
	{
		while (count < total_size - 3)
		{
			push(stackB, stackA, 'a');
			count++;
		}
	}
}

void	radix_sort(t_node **stackA, int total_elements)
{
	int		bit_position;
	int		max_bits;
	int		i;
	t_node	*stackb;

	bit_position = 0;
	max_bits = 0;
	stackb = NULL;
	while (((total_elements - 1) >> max_bits) != 0)
		++max_bits;
	while (bit_position < max_bits)
	{
		i = 0;
		while (i < total_elements)
		{
			if ((((*stackA)->sorted_index >> bit_position) & 1) == 0)
				push(stackA, &stackb, 'b');
			else
				rotate_stack(stackA, 'a');
			i++;
		}
		while (stackb)
			push(&stackb, stackA, 'a');
		bit_position++;
	}
}

void	sort_stack(int element_count, char **elements)
{
	t_node	*stacka;
	t_node	*stackb;

	stacka = build_linked_list(element_count, elements);
	stackb = NULL;
	if (!stacka)
		write(2, "Error\n", 6);
	else if (is_sorted(stacka))
	{
		clear_list(&stacka);
		free(stacka);
		return ;
	}
	else if (element_count < 6 && element_count > 2)
		sort_small_stack(&stacka, &stackb, element_count);
	else if (element_count == 2)
		swap_top_two_nodes(&stacka, 'a');
	else
		radix_sort(&stacka, element_count);
	clear_list(&stacka);
	free(stacka);
}
