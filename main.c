/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuki <kazuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 00:34:11 by kazuki            #+#    #+#             */
/*   Updated: 2023/01/26 07:59:48 by kazuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize_stack_a(t_stack *stack_a, int	*data, int argc)
{
	int		i;
	bool	res;

	i = 0;
	stack_a = create_stack();
	while (i < argc - 1)
	{
		res = push_back(stack_a, data[i]);
		if (!res)
		{
			free(stack_a);
			error_message();
		}
		i++;
	}
	return (stack_a);
}

bool	is_sorted(t_stack *stack)
{
	t_stack_node	*head;

	if (stack->head == NULL)
		return (true);
	head = stack->head;
	while (head->next != NULL)
	{
		if (head->val > head->next->val)
			return (false);
		head = head->next;
	}
	return (true);
}

bool	has_duplicate(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (i != j && ps_atoi(argv[i]) == ps_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*data;

	if (argc < 2)
		return (0);
	data = argv_to_array(argc, argv);
	if (has_duplicate(argv))
		error_message();
	data = compression(data, argc);
	a = initialize_stack_a(a, data, argc);
	free(data);
	b = create_stack();
	if (!is_sorted(a))
		sort(&a, &b);
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
