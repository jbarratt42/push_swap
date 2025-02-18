/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:54:23 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 12:59:38 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s, size_t size)
{
	s->s = malloc(size * sizeof(int));
	if (!s->s)
		return ;
	s->size = 0;
}

void	init_pair(t_stack *p, size_t size)
{
	init_stack(&p[0], size);
	init_stack(&p[1], size);
	if (!(p[0].s && p[1].s))
		free_pair(p);
}

void	free_pair(t_stack p[2])
{
	free(p[0].s);
	free(p[1].s);
}

int	is_unique(t_stack *s, int n)
{
	size_t	i;

	i = 0;
	while (i < s->size)
		if (n == s->s[i++])
			return (0);
	return (1);
}
