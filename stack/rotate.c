/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:49:38 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/06 08:01:04 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*rotate(t_stack *stack)
{
	int		*data;
	bool	res;

	data = (int *)malloc(sizeof(int));
	res = pop_front(stack, &data);
	if (!res)
		return (NULL);
	res = push_back(stack, *data);
	free(data);
	if (!res)
		return (NULL);
	return (stack);
}

t_stack	*ra(t_stack *stack_a)
{
	t_stack	*result;

	result = rotate(stack_a);
	if (!result)
		return (result);
	write(1, "ra\n", 3);
	return (result);
}

t_stack	*rb(t_stack *stack_b)
{
	t_stack	*result;

	result = rotate(stack_b);
	if (!result)
		return (result);
	write(1, "rb\n", 3);
	return (result);
}
