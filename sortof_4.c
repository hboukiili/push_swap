/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortof_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:06:00 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 21:09:27 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	small_is_first(t_list **stack_a, t_list **stack_b)
{
	pb_move(stack_a, stack_b, 0);
	sort_3(stack_a);
	pa_move(stack_a, stack_b, 0);
}

void	small_is_second(t_list **stack_a, t_list **stack_b)
{
	sort_2(stack_a);
	pb_move(stack_a, stack_b, 0);
	sort_3(stack_a);
	pa_move(stack_a, stack_b, 0);
}

void	small_is_third(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a, 0);
	sort_4(stack_a, stack_b);
}

void	small_is_last(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a, 0);
	pb_move(stack_a, stack_b, 0);
	sort_3(stack_a);
	pa_move(stack_a, stack_b, 0);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	m;

	m = check_small_value(stack_a);
	x = check_place(stack_a, m);
	if (x == 0)
		small_is_first(stack_a, stack_b);
	if (x == 1)
		small_is_second(stack_a, stack_b);
	if (x == 2)
		small_is_third(stack_a, stack_b);
	if (x == 3)
		small_is_last(stack_a, stack_b);
}
