/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboustan <jboustan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:49:48 by jboustan          #+#    #+#             */
/*   Updated: 2024/08/19 00:33:02 by jboustan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		element_count;
	char	**parsed_elements;

	element_count = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		parsed_elements = ft_split(argv[1], ' ');
		while (parsed_elements[element_count])
			element_count++;
		sort_stack(element_count, parsed_elements);
		free_string_array(parsed_elements);
		free(parsed_elements);
	}
	else
	{
		argv++;
		sort_stack(argc - 1, argv);
	}
}
