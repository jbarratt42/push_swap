/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:11:00 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 16:30:13 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bail(t_stack p[2])
{
	write(1, "Error!\n", 7);
	free_pair(p);
	exit(1);
}

static int	my_atoi(char *str, int *error)
{
	int		neg;
	long	val;

	neg = 0;
	if (str[0] == '-')
	{
		neg = 1;
		str++;
	}
	val = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			*error = 1;
		val = 10 * val + *str - '0';
		str++;
	}
	if (neg)
		val = -val;
	if (val > INT_MAX || val < INT_MIN)
		*error = 1;
	return ((int)val);
}

int	read_stack(size_t n, char **args, t_stack p[2])
{
	int		error;

	error = 0;
	p[0].size = 0;
	while (p[0].size < n)
	{
		p[0].s[p[0].size] = my_atoi(args[n - 1 - p[0].size], &error);
		if (error || !is_unique(p, p[0].s[p[0].size]))
			bail(p);
		p[0].size++;
	}
	return (p[0].size);
}
