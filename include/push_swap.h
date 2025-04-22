/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barnaud <barnaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:39:18 by barnaud           #+#    #+#             */
/*   Updated: 2025/02/25 14:48:09 by barnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*init(int ac, char **av);
void				get_index(t_stack *stack_a, int ac);

int					is_sorted(t_stack *stack);
void				three_sort(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);

int					get_lowest_index_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);

void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);

t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					stack_len(t_stack *stack);

void				free_stack(t_stack **stack);
long int			ft_atoi(const char *str);
void				ft_putstr(char *str);
int					nb_abs(int nb);

void				send_error(t_stack **stack_a, t_stack **stack_b);

int					is_correct_input(char **av);
int					is_digit(char c);
int					is_sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);

char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
int					good_split(char **av);

t_stack				*split_init(char **av);
char				**free_if_error(char **split);

void				call_function(t_stack *stack_a, t_stack *stack_b,
						int stack_size);
void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
void				send_error_split(char **result);

#endif