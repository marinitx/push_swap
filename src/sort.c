/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:25 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/26 19:09:30 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort2(t_stack **stack_a)
{
	sa(stack_a);
}

void	sort3(t_stack **stack_a)
{
	int	min;
	int	max;

	min = get_min(*stack_a);
	max = get_max(*stack_a);
	if ((*stack_a)->content == max && (*stack_a)->next->content != min)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->content == min && (*stack_a)->next->content == max)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->content == max && (*stack_a)->next->content == min)
		ra(stack_a);
	else if ((*stack_a)->next->content == min
		&& ft_lstlast(*stack_a)->content == max)
		sa(stack_a);
	else if ((*stack_a)->next->content == max
		&& ft_lstlast(*stack_a)->content == min)
		rra(stack_a);
}

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content == get_min(*stack_a))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort3(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	return ;
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_lstsize(*stack_a);
	while (!check_sorted(stack_a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
