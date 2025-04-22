/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnaud <barnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:30:25 by barnaud           #+#    #+#             */
/*   Updated: 2025/02/25 12:36:17 by barnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_function(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
