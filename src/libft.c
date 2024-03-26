/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:24:53 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/26 19:52:41 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static size_t	ft_countword(char *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i++])
	{
		if (s[i] == c)
			count++;
	}
	return (count);
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL || !s || !str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	d;
	char			**table;

	a = 0;
	d = 0;
	table = malloc((count(s, c) + 1) * sizeof * table);
	if (table == NULL || !s)
		return (NULL);
	while (s[a])
	{
		while (s[a] == c)
			a++;
		b = a;
		while (s[a] && s[a] != c)
			a++;
		if (b < a)
			table[d++] = ft_strndup(s + b, a - b);
	}
	table[d] = NULL;
	return (table);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sig;

	sig = 1;
	res = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r'
		|| *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sig = -sig;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		res = (res * 10) + (*str - 48);
		str++;
	}
	return (res * sig);
}
