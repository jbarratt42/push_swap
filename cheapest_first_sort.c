/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_first_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:05:27 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 14:53:24 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the position of the largest value in stack s */
size_t	imax(t_stack *s)
{
	size_t	i;

	i = 0;
	while (i < s->size && s->s[i] > s->s[(i + 1) % s->size])
		i++;
	return ((i + 1) % s->size);
}

/* find the correct position of val in stack s */
size_t	get_position(int val, t_stack *s)
{
	const size_t	start = imax(s);
	size_t			i;

	if (val > s->s[start] || val < s->s[(start + s->size - 1) % s->size])
		return (start);
	i = (start + 1) % s->size;
	while (s->s[i] > val)
		i = (i + 1) % s->size;
	return (i);
}

/* the cost of moving element i in stack b to it's correct position in
 * stack a is the sum of:
 * - number of ops to get to the top of stack b
 * - one push to stack a
 * - number of ops to get to the correct position in stack a
 */
size_t	calculate_cost(size_t i, t_stack p[2])
{
	size_t	dest;
	size_t	cost;

	if (i + 1 < p[1].size - 1 - i)
		cost = i + 1;
	else
		cost = p[1].size - 1 - i;
	dest = get_position(p[1].s[i], &p[0]);
	if (dest < p[0].size - dest)
		cost += 1 + dest;
	else
		cost += 1 + p[0].size - dest;
	return (cost);
}

/* perform the operations necessary to get from position i in 
 * stack b to the correct position in stack a
 */
void	sort_element(size_t i, t_stack p[2])
{
	size_t	dest;

	if (i + 1 < p[1].size - 1 - i)
		repeat_op(RRB, p, i + 1);
	else
		repeat_op(RB, p, p[1].size - 1 - i);
	dest = get_position(p[1].s[p[1].size - 1], &p[0]);
	if (dest < p[0].size - dest)
		repeat_op(RRA, p, dest);
	else
		repeat_op(RA, p, p[0].size - dest);
	operate(PA, p, 0);
}

/* sort the elements of stack b into stack a, cheapest first,
 * where the cost of sorting an element is determined by
 * calculate_cost
 */
void	cheapest_first_sort(t_stack p[2])
{
	size_t	i;
	size_t	cost;
	size_t	imin;
	size_t	min_cost;

	while (p[1].size)
	{
		min_cost = SIZE_MAX;
		i = 0;
		while (i < p[1].size)
		{
			cost = calculate_cost(i, p);
			if (cost < min_cost)
			{
				imin = i;
				min_cost = cost;
			}
			i++;
		}
		sort_element(imin, p);
	}
	max_to_bottom(p);
}
