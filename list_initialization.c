/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:31:18 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:15:35 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicate(t_node **head, int number)
{
	t_node	*current_node;

	if (!*head)
		return (0);
	current_node = *head;
	while (current_node)
	{
		if (current_node->value == number)
		{
			return (1);
		}
		current_node = current_node->next;
	}
	return (0);
}

t_node	*create_node_from_arg(char *arg_str, size_t *position)
{
	char	*arg_copy;
	t_node	*new_node;
	long	value;

	value = 0;
	arg_copy = ft_strdup(arg_str);
	if (ft_atoi_with_check(arg_copy, &value))
	{
		free(arg_copy);
		return (NULL);
	}
	free(arg_copy);
	new_node = create_new_node(value, *position, -1);
	if (new_node)
		return (new_node);
	return (NULL);
}

void	assign_sorted_order(t_node **head, size_t total_nodes)
{
	t_node	*smallest_node;
	t_node	*current_node;
	size_t	i;

	i = 0;
	while (i < total_nodes)
	{
		current_node = *head;
		smallest_node = find_next_lowest_node(*head);
		while (current_node)
		{
			if (current_node->value == smallest_node->value)
			{
				current_node->sorted_index = i;
				break ;
			}
			current_node = current_node->next;
		}
		free(smallest_node);
		i++;
	}
}

t_node	*build_linked_list(size_t number_elements, char **elements)
{
	size_t	i;
	t_node	*new_node;
	t_node	*stacka;

	i = 0;
	stacka = NULL;
	while (i < number_elements)
	{
		new_node = create_node_from_arg(elements[i], &i);
		if (!new_node || check_for_duplicate(&stacka, new_node->value))
		{
			if (new_node)
				free(new_node);
			clear_list(&stacka);
			return (NULL);
		}
		add_node_to_end(&stacka, new_node);
		i++;
	}
	assign_sorted_order(&stacka, number_elements);
	return (stacka);
}
