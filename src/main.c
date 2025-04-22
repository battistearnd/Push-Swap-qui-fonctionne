/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnaud <barnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:47:11 by barnaud           #+#    #+#             */
/*   Updated: 2025/03/13 10:54:05 by barnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		three_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**result;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		result = ft_split(av[1], ' ');
		if (!good_split(result))
			send_error_split(result);
		stack_a = split_init(result);
		free_if_error(result);
	}
	else
	{
		if (!is_correct_input(av))
			send_error(NULL, NULL);
		stack_a = init(ac, av);
	}
	stack_b = NULL;
	stack_size = stack_len(stack_a);
	call_function(stack_a, stack_b, stack_size);
	return (0);
}
