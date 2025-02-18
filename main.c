/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:28:13 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 16:12:55 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		p[2];
	t_opnode	*queue;

	if (argc < 2)
		return (0);
	init_pair(p, argc - 1);
	if (!read_stack(argc - 1, &argv[1], &p[0]))
		return (1);
	p[0].size = argc - 1;
	queue = push_swap(&p[0]);
	while ((p[0].size <= 100 && queue_len(queue) > 700)
		|| (p[0].size <= 500 && queue_len(queue) > 5500))
	{
		op_queue(CLEAR);
		read_stack(argc - 1, &argv[1], &p[0]);
		repeat_op(RA, &p[0], p[0].size / 2 - 7);
		queue = push_swap(&p[0]);
	}
	print_queue(queue);
	free_queue(op_queue(-1));
	free_pair(p);
	return (0);
}
