/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:25:18 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:03:31 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_with_check(const char *input_str, long *result)
{
	int	sign;
	int	index;

	index = 0;
	sign = 1;
	if (*input_str == '-' && *input_str)
	{
		sign *= -1;
		input_str++;
	}
	if (!*input_str)
		return (1);
	while (input_str[index])
	{
		if (ft_isdigit(input_str[index]) == 1)
			*result = (*result * 10) + (input_str[index++] - '0');
		else
			return (1);
		if (*result * sign > 2147483647 || *result * sign < -2147483648)
			return (1);
	}
	*result = *result * sign;
	return (0);
}

int	is_sorted(t_node *node)
{
	while (node->next != NULL)
	{
		if (node->next->value > node->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

void	free_string_array(char **string_array)
{
	int	index;

	index = 0;
	while (string_array[index])
	{
		free(string_array[index]);
		index++;
	}
}

t_node	*find_next_lowest_node(t_node *head)
{
	t_node	*small_node;
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->sorted_index < 0)
		{
			small_node = create_new_node(current->value, current->original_pos,
					current->sorted_index);
			break ;
		}
		current = current->next;
	}
	while (head)
	{
		if (head->value < small_node->value && head->sorted_index < 0)
		{
			small_node->value = head->value;
			small_node->original_pos = head->original_pos;
			small_node->sorted_index = head->sorted_index;
		}
		head = head->next;
	}
	return (small_node);
}

t_node	*find_minimum_value_node(t_node *head)
{
	t_node	*min_value_node;

	min_value_node = create_new_node(head->value, head->original_pos,
			head->sorted_index);
	while (head)
	{
		if (head->value < min_value_node->value)
		{
			min_value_node->value = head->value;
			min_value_node->original_pos = head->original_pos;
		}
		head = head->next;
	}
	return (min_value_node);
}
