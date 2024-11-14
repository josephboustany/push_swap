/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:28:19 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:18:00 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int value, size_t original_pos, long sorted_index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->original_pos = original_pos;
	new_node->sorted_index = sorted_index;
	new_node->previous = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_node_to_end(t_node **head, t_node *new_node)
{
	t_node	*current_node;

	current_node = *head;
	if (!(*head))
	{
		*head = new_node;
		return ;
	}
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
	new_node->previous = current_node;
}

void	add_node_to_start(t_node **head, t_node *new_node)
{
	t_node	*current_node;

	if (!*head)
	{
		new_node->next = NULL;
		*head = new_node;
		return ;
	}
	new_node->next = *head;
	*head = new_node;
	current_node = *head;
	current_node = current_node->next;
	while (current_node != NULL)
	{
		current_node->original_pos += 1;
		current_node = current_node->next;
	}
}

void	clear_list(t_node **head)
{
	t_node	*current_node;

	if (!*head)
		return ;
	while (*head)
	{
		current_node = (*head)->next;
		free(*head);
		*head = current_node;
	}
	*head = NULL;
}

t_node	*get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}
