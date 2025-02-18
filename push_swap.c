/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:53:32 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 15:06:14 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indicize(t_stack *p, int rev)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < p[0].size)
		p[1].s[p[1].size + i] = p[0].s[i];
	bubble_sort(&p[1].s[p[1].size], p[0].size, rev);
	i = 0;
	while (i < p[0].size)
	{
		j = 0;
		while (p[0].s[i] != p[1].s[p[1].size + j])
			j++;
		p[0].s[i] = j;
		i++;
	}
}

/* perform the operations to partition the elements in stack a
 * into stack b such that the upper half of the elements are 
 * above the lower half
 */
void	partition(t_stack p[2], int rev)
{
	const size_t	size = p[0].size;
	size_t			i;

	i = 0;
	while (i++ < size)
	{
		if ((size_t)(p[0].s[p[0].size - 1]) > (size - 1) / 2)
			operate(RA, p, rev);
		else
			operate(PB, p, rev);
	}
	while (p[0].size)
		operate(PB, p, rev);
}

t_opnode	*push_swap(t_stack p[2])
{
	t_opnode	*queue;

	if (p[0].size < 10)
	{
		short_sort(p);
		return (op_queue(IGNORE));
	}
	indicize(p, 0);
	partition(p, 0);
	operate(PA, p, 0);
	cheapest_first_sort(p);
	queue = op_queue(-1);
	collapse_antiops(&queue);
	unite_simops(&queue);
	return (queue);
}
