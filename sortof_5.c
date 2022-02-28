/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortof_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:06:52 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 21:10:58 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	small_third(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a, 0);
	rra_move(stack_a, 0);
	rra_move(stack_a, 0);
	sort_5(stack_a, stack_b);
}

void	small_first(t_list **stack_a, t_list **stack_b)
{
	pb_move(stack_a, stack_b, 0);
	sort_4(stack_a, stack_b);
	pa_move(stack_a, stack_b, 0);
}

void	small_second(t_list **stack_a, t_list **stack_b)
{
	sort_2(stack_a);
	pb_move(stack_a, stack_b, 0);
	sort_4(stack_a, stack_b);
	pa_move(stack_a, stack_b, 0);
}

void	small_last(t_list **stack_a, t_list **stack_b)
{
	rra_move(stack_a, 0);
	pb_move(stack_a, stack_b, 0);
	sort_4(stack_a, stack_b);
	pa_move(stack_a, stack_b, 0);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	m;

	m = check_small_value(stack_a);
	x = check_place(stack_a, m);
	if (x == 0)
		small_first(stack_a, stack_b);
	if (x == 1)
		small_second(stack_a, stack_b);
	if (x == 2)
		small_third(stack_a, stack_b);
	if (x == 3)
	{
		rra_move(stack_a, 0);
		sort_5(stack_a, stack_b);
	}
	if (x == 4)
		small_last(stack_a, stack_b);
}
