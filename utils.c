/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 06:34:35 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 15:05:04 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(int a, int b, int rev)
{
	if (rev)
		return (a < b);
	return (a > b);
}

/*
void	roll(size_t i, t_stack *p, int rev)
{
	while (p[0].size > i + 1)
		operate(PB, p, rev);
	while (p[0].size < i + 1)
		operate(PA, p, rev);
}

*/
void	max_to_bottom(t_stack p[2])
{
	const size_t	pos = imax(&p[0]);

	if (pos < p[0].size - pos)
		repeat_op(RRA, p, pos);
	else
		repeat_op(RA, p, p[0].size - pos);
}

void	bubble_sort(int *a, size_t size, int rev)
{
	int		tmp;
	size_t	i;
	size_t	count;

	count = 1;
	while (count)
	{
		count = 0;
		i = 1;
		while (i < size)
		{
			if (compare(a[i - 1], a[i], rev))
			{
				tmp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = tmp;
				count++;
			}
			i++;
		}
	}
}

void	print_code(t_opcode o, int rev)
{
	const char	codes[16][4] = {
		"sa", "sb", "ss", "",
		"pa", "pb", "", "",
		"ra", "rb", "rr", "",
		"rra", "rrb", "rrr", ""
	};
	size_t		len;

	len = 2;
	if (o >= 12)
		len = 3;
	if (rev && o % 4 < 2)
		o = (o / 4) * 4 + !(o % 4);
	write(1, &codes[o], len);
	write(1, "\n", 1);
}

void	repeat_op(t_opcode o, t_stack p[2], size_t n)
{
	while (n--)
		operate(o, p, 0);
}
