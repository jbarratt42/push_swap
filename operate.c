/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:46:35 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 15:02:24 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *s)
{
	int	n;

	n = s->s[s->size - 1];
	s->s[s->size - 1] = s->s[s->size - 2];
	s->s[s->size - 2] = n;
}

void	rev_rotate(t_stack *s)
{
	int		n;
	size_t	i;

	n = s->s[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->s[i] = s->s[i + 1];
		i++;
	}
	s->s[s->size - 1] = n;
}

void	rotate(t_stack *s, int rev)
{
	int		n;
	size_t	i;

	if (s->size < 2)
		return ;
	if (rev)
		rev_rotate(s);
	else
	{
		n = s->s[s->size - 1];
		i = s->size - 1;
		while (i)
		{
			s->s[i] = s->s[i - 1];
			i--;
		}
		s->s[0] = n;
	}
}

void	push(t_stack *p, int to_b)
{
	p[to_b].size++;
	p[to_b].s[p[to_b].size - 1] = p[!to_b].s[p[!to_b].size - 1];
	p[!to_b].size--;
}

void	operate(t_opcode o, t_stack *p, int rev)
{
	if (o % 4 == 2)
	{
		operate(o - 2, p, rev);
		operate(o - 1, p, rev);
	}
	else if (o / 4 == 0)
		swap(&p[o % 4]);
	else if (o / 4 == 1)
		push(p, o % 4);
	else
		rotate(&p[o % 4], o >= 12);
	if (rev && o % 4 < 2)
		o = 4 * (o / 4) + !(o % 4);
	op_queue(o);
}
