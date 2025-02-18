/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:57:37 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 14:58:01 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_queue(t_opnode *n)
{
	if (!n)
		return (0);
	print_code(n->op, 0);
	n = n->next;
	return (1 + print_queue(n));
}

size_t	queue_len(t_opnode *n)
{
	if (!n)
		return (0);
	return (1 + queue_len(n->next));
}

//size_t	short_circuit_rotation(t_opnode *queue)

t_opnode	*op_queue(t_opcode o)
{
	static t_opnode	*head;
	t_opnode		**n;

	if (o == CLEAR)
	{
		free_queue(head);
		head = NULL;
	}
	if (o < 0)
		return (head);
	n = &head;
	while (*n)
		n = &(*n)->next;
	*n = malloc(sizeof(t_opnode));
	if (!*n)
	{
		free_queue(head);
		return (NULL);
	}
	(*n)->op = (t_opcode)o;
	(*n)->next = NULL;
	return (head);
}

void	free_queue(t_opnode *n)
{
	if (!n)
		return ;
	free_queue(n->next);
	free(n);
	return ;
}
