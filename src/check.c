/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:25:37 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/26 19:55:29 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Comprueba que no estén los números duplicados
void	check_dup(int num, char **args, int i)
{
	i++;
	while (args[i] != NULL)
	{
		if (num == ft_atoi(args[i]))
			ft_error();
		i++;
	}
}

//Comprueba si es un dígito
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

//Comprueba que los argumentos sean números y no otra cosa
void	check_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i] != '\0' && num[i] != ' ')
	{
		if (!ft_isdigit(num[i]))
			ft_error();
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	char	**args;
	int		i;
	long	tmp;

	i = 0;
	if (*argv && argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		check_num(args[i]);
		tmp = ft_atol(argv[i]);
		if (tmp < -2147483647 || tmp > 2147483647)
			ft_error();
		if (args[i + 1] != NULL)
			check_dup(ft_atoi(args[i]), args, i);
		i++;
	}
	if (argc == 2)
		ft_free_str(args);
}

//El stack está ordenado? el actual > que el siguiente? 0 no ordenado, 1 sí
int	check_sorted(t_stack **stack_a)
{
	t_stack	*head;

	head = *stack_a;
	while (head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}
