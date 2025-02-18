/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:11:00 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/10 14:07:34 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_atoi_error(int *error)
{
	*error = 1;
	return (0);
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
			return (my_atoi_error(error));
		val = 10 * val + *str - '0';
		str++;
	}
	if (neg)
		val = -val;
	if (val > INT_MAX || val < INT_MIN)
		return (my_atoi_error(error));
	return ((int)val);
}

/*
void	read_stack(char *arg, t_stack p[2])
{
	char 			*ptr;
	const size_t	count = count_list(arg);
	int				error;

	init_pair(p, count);
	if (!p[0].s)
		return ;
	error = 0;
	p = arg;
	while (*p)
	{
		while (*p && p != ' ')
			p++;
		*p = '\0';
		my_atoi(arg, &error);
		if (error)
		{
			free_pair(p);
			return ;
		}
		p[0].s[p[0].size++] = n;
		p++;
		arg = p;
	}
}
*/

int	read_stack(size_t n, char **args, int *s)
{
	size_t	i;
	int		error;

	error = 0;
	i = 0;
	while (i < n)
	{
		s[i] = my_atoi(args[n - 1 - i], &error);
		if (error)
			return (0);
		i++;
	}
	return (i);
}
