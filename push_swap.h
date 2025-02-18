/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarratt <jbarratt@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:37:35 by jbarratt          #+#    #+#             */
/*   Updated: 2025/02/18 14:49:44 by jbarratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef enum e_opcode
{
	SA = 0,
	SB = 1,
	SS = 2,
	PA = 4,
	PB = 5,
	RA = 8,
	RB = 9,
	RR = 10,
	RRA = 12,
	RRB = 13,
	RRR = 14,
	IGNORE = -1,
	CLEAR = -2
}	t_opcode;
typedef struct s_stack
{
	int		*s;
	size_t	size;
}	t_stack;
typedef struct s_opnode	t_opnode;
typedef struct s_opnode
{
	t_opcode	op;
	t_opnode	*next;
}	t_opnode;
/* ./push_swap.c */
void		indicize(t_stack *p, int rev);
void		partition(t_stack p[2], int rev);
t_opnode	*push_swap(t_stack p[2]);
/* ./cheapest_first_sort.c */
size_t		imax(t_stack *s);
size_t		get_position(int val, t_stack *s);
size_t		calculate_cost(size_t i, t_stack p[2]);
void		sort_element(size_t i, t_stack p[2]);
void		cheapest_first_sort(t_stack p[2]);
/* ./operate.c */
void		swap(t_stack *s);
void		rev_rotate(t_stack *s);
void		rotate(t_stack *s, int rev);
void		push(t_stack *p, int to_b);
void		operate(t_opcode o, t_stack *p, int rev);
/* ./read_stack.c */
int			read_stack(size_t n, char **args, int *s);
/* ./queue.c */
int			print_queue(t_opnode *n);
size_t		queue_len(t_opnode *n);
t_opnode	*op_queue(t_opcode o);
void		free_queue(t_opnode *n);
/* ./queue_collapse.c */
int			check_antiops(t_opcode a, t_opcode b);
int			check_simops(t_opcode a, t_opcode b);
size_t		collapse_antiops(t_opnode **n);
size_t		unite_simops(t_opnode **n);
/* ./stack.c */
void		init_stack(t_stack *s, size_t size);
void		init_pair(t_stack *p, size_t size);
void		free_pair(t_stack p[2]);
int			is_unique(t_stack *s, int n);
/* ./short_sort.c */
void		sort3(t_stack *s);
size_t		imin(t_stack *s);
void		short_sort(t_stack p[2]);
/* ./utils.c */
int			compare(int a, int b, int rev);
void		max_to_bottom(t_stack p[2]);
void		bubble_sort(int *a, size_t size, int rev);
void		print_code(t_opcode o, int rev);
void		repeat_op(t_opcode o, t_stack p[2], size_t n);
#endif
