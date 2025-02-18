/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:13:29 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 14:04:14 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* don't do any sorting after this */
void	sort3(t_stack *s)
{
	indicize(s, 0);
	if (s->s[1] == 2)
		operate(RRA, s, 0);
	if (s->s[0] - s->s[2] == 1 || s->s[2] - s->s[0] == 2)
		operate(SA, s, 0);
	if (s->s[0] == 0)
		operate(RRA, s, 0);
	if (s->s[0] == 1 && s->s[2] == 2)
		operate(RA, s, 0);
}

size_t	imin(t_stack *s)
{
	size_t	i;
	size_t	i_min;
	int		min;

	i_min = INT_MAX;
	i = 0;
	while (i < s->size)
	{
		if (s->s[i] < min)
		{
			min = s->s[i];
			i_min = i;
		}
		i++;
	}
	return (i_min);
}

void	short_sort(t_stack p[2])
{
	const size_t	size = p[0].size;
	size_t			i_min;

	if (p[0].size == 1)
		return ;
	if (p[0].size == 2)
	{
		if (p[0].s[1] > p[0].s[0])
			operate(SA, p, 0);
		return ;
	}
	if (p[0].size == 3)
	{
		sort3(&p[0]);
		return ;
	}
	i_min = imin(&p[0]);
	if (p[0].size - i_min - 1 < i_min + 1)
		repeat_op(RA, p, p[0].size - 1 - i_min);
	else
		repeat_op(RRA, p, i_min + 1);
	operate(PB, p, 0);
	if (p[0].size < size)
		short_sort(p);
	operate(PA, p, 0);
}
