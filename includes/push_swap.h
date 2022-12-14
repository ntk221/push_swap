/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:51:53 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/07 04:59:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack_node
{
	int					val;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

typedef struct s_stack
{
	t_stack_node	*head;
	t_stack_node	*last;
	size_t			size;
}	t_stack;

/* deque operations */
t_stack			*create_stack(void);
bool			push_front(t_stack *stack, int value);
bool			push_back(t_stack *stack, int value);
bool			pop_front(t_stack *stack, int **data);
bool			pop_back(t_stack *stack, int **data);
void			destroy_stack(t_stack *stack);

void			print_stack(t_stack *stack);

/* normal operations */
t_stack			*swap(t_stack *stack);
t_stack			*sa(t_stack *stack_a);
t_stack			*sb(t_stack *stack_b);
t_stack			*rotate(t_stack *stack);
t_stack			*ra(t_stack *stack_a);
t_stack			*rb(t_stack *stack_b);
t_stack			*reverse_rotate(t_stack *stack);
t_stack			*rra(t_stack *stack_a);
t_stack			*rrb(t_stack *stack_b);
t_stack			*push(t_stack *src, t_stack *dst);
t_stack			*pa(t_stack *stack_a, t_stack *stack_b);
t_stack			*pb(t_stack *stack_a, t_stack *stack_b);

/* composite operations */

/* sort functions */
// t_stack			*bubble_sort(t_stack *stack_a, t_stack *stack_b);
t_stack			*radix_sort(t_stack *a, t_stack *b);
t_stack			*sort_3(t_stack *stack_a);
t_stack			*sort_4(t_stack *stack_a, t_stack *stack_b);
t_stack			*sort_5(t_stack *stack_a, t_stack *stack_b);
t_stack			*sort(t_stack *stack_a, t_stack *stack_b);

/* sort utils */
t_stack_node	*find_min_node(t_stack *stack_a, size_t *index);
// t_stack_node	*find_max_node(t_stack *stack_a);

/* util functions */
// static int		is_space(const char c);
// static bool		is_digits(const char c);
int				ps_atoi(const char *str, bool *error);
int				atoi_loop(const char *str, int num, int sign, bool *error);
bool			check_argv(int argc, char **argv);
void			error_message(void);
t_stack			*initialize_stack_a(t_stack *stack_a, int *data, int argc);
bool			is_sorted(t_stack *stack);
bool			has_duplicate(char **src);
int				*argv_to_array(int argc, char **argv);
int				linear_search(int *ordered_array, int search);
int				*bubble_sort_arr(int *list, int len);
int				*copy_data(int *copy, int argc);
int				*compression(int	*data, int argc);

#endif
