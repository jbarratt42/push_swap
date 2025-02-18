/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_collapse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:00:58 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 15:00:59 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_antiops(t_opcode a, t_opcode b)
{
	if (b < a)
		return (check_antiops(b, a));
	return ((a >= 8 && b - a == 4) || (a == PA && b == PB));
}

int	check_simops(t_opcode a, t_opcode b)
{
	if (b < a)
		return (check_simops(b, a));
	return (a / 4 == b / 4 && a / 4 != 1 && a % 4 == 0 && b % 4 == 1);
}

size_t	collapse_antiops(t_opnode **n)
{
	t_opnode	*next;
	size_t		nodes_trimmed;

	if (!*n || !(*n)->next)
		return (0);
	nodes_trimmed = collapse_antiops(&(*n)->next);
	if (check_antiops((*n)->op, (*n)->next->op))
	{
		next = (*n)->next->next;
		free((*n)->next);
		free(*n);
		*n = next;
		nodes_trimmed += 2;
	}
	return (nodes_trimmed);
}

size_t	unite_simops(t_opnode **n)
{
	t_opnode	*next;
	size_t		nodes_trimmed;

	if (!*n || !(*n)->next)
		return (0);
	nodes_trimmed = unite_simops(&(*n)->next);
	if (check_simops((*n)->op, (*n)->next->op))
	{
		next = (*n)->next->next;
		free((*n)->next);
		(*n)->op = 4 * ((*n)->op / 4) + 2;
		(*n)->next = next;
		nodes_trimmed++;
	}
	return (nodes_trimmed);
}
