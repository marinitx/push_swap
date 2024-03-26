/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:11:34 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/26 19:05:44 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*get_next_min(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*min;
	int		found;

	min = NULL;
	found = 0;
	head = *stack_a;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (found == 0 || head->content
					< min->content))
			{
				min = head;
				found = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

// para cada número añadido, mira si es más pequeño que el valor más pequeño
void	add_index_to_stack(t_stack **stack_a)
{
	t_stack	*head;
	int		new_index;

	new_index = 0;
	head = get_next_min(stack_a);
	while (head)
	{
		head->index = new_index++;
		head = get_next_min(stack_a);
	}
}
