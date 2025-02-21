/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnaud <barnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:37:58 by barnaud           #+#    #+#             */
/*   Updated: 2025/02/21 12:54:09 by barnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*init(int argc, char **argv)
// {
// 	t_stack		*stack_a;
// 	long int	nb;
// 	int			i;

// 	stack_a = NULL;
// 	nb = 0;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		nb = ft_atoi(argv[i]);
// 		if (nb > INT_MAX || nb < INT_MIN)
// 			send_error(&stack_a, NULL);
// 		if (i == 1)
// 			stack_a = new_nb((int)nb);
// 		else
// 			stack_fill(&stack_a, new_nb((int)nb));
// 		i++;
// 	}
// 	return (stack_a);
// }

// void	get_index(t_stack *stack_a, int stack_size)
// {
// 	t_stack	*ptr;
// 	t_stack	*highest;
// 	int		value;

// 	while (--stack_size > 0)
// 	{
// 		ptr = stack_a;
// 		value = INT_MIN;
// 		highest = NULL;
// 		while (ptr)
// 		{
// 			if (ptr->content == INT_MIN && ptr->index == 0)
// 				ptr->index = 1;
// 			if (ptr->content > value && ptr->index == 0)
// 			{
// 				value = ptr->content;
// 				highest = ptr;
// 				ptr = stack_a;
// 			}
// 			else
// 				ptr = ptr->next;
// 		}
// 		if (highest != NULL)
// 			highest->index = stack_size;
// 	}
// }

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			send_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_nb((int)nb);
		else
			stack_fill(&stack_a, new_nb((int)nb));
		i++;
	}
	return (stack_a);
}

void	get_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > value && ptr->index == 0)
			{
				value = ptr->content;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}