/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortof_100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:04:36 by hboukili          #+#    #+#             */
/*   Updated: 2022/05/11 19:07:26 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_low(t_list **stack_a, t_list **stack_b, t_push x, int size)
{
	while (x.ch <= size / 2)
	{
		if ((*stack_a)->index >= x.min && (*stack_a)->index <= x.max)
		{
			pb_move(stack_a, stack_b, 0);
			if ((*stack_b)->index < x.med)
				rb_move(stack_b, 0);
			x.push--;
			if (x.push == 0)
				break ;
			break ;
		}
		else
			ra_move(stack_a, 0);
		size = stack_size(stack_a);
		x.ch++;
	}
	return (x.push);
}

int	is_up(t_list **stack_a, t_list **stack_b, t_push x, int size)
{
	while (x.ch > size / 2)
	{
		if ((*stack_a)->index >= x.min && (*stack_a)->index <= x.max)
		{
			pb_move(stack_a, stack_b, 0);
			if ((*stack_b)->index < x.med)
				rb_move(stack_b, 0);
			x.push--;
			if (x.push == 0)
				break ;
			break ;
		}
		else
			rra_move(stack_a, 0);
		size = stack_size(stack_a);
		x.ch--;
	}
	return (x.push);
}

void	ft_a(t_list **stack_b, int n, int l)
{
	int	size;

	size = stack_size(stack_b);
	if (l > size / 2)
	{
		while (l > size / 2)
		{
			if (n == (*stack_b)->index)
				break ;
			rrb_move(stack_b, 0);
			l--;
		}
	}
	else if (l <= size / 2)
	{
		while (l <= size / 2)
		{
			if (n == (*stack_b)->index)
				break ;
			rb_move(stack_b, 0);
			l++;
		}
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	n;
	int	l;

	size = stack_size(stack_b);
	while (size != 0)
	{
		if ((*stack_a)->index - 1 == (*stack_b)->index)
			pa_move(stack_a, stack_b, 0);
		if ((*stack_a)->index - 1 != (*stack_b)->index)
		{
			n = (*stack_a)->index - 1;
			l = check_place(stack_b, n);
			ft_a(stack_b, n, l);
		}
		size = stack_size(stack_b);
	}
	if (size == 0)
		pa_move(stack_a, stack_b, 0);
}

void	sort_100(t_list **stack_a, t_list **stack_b, int size)
{
	t_push	x;
	
	while (size >= 5)
	{
		if (size <= 100)
			x.push = ((size - 5) / 3) + 1;
		if (size > 100)
		 	x.push = ((size - 5) / 5) + 1;
		x.min = check_small_value(stack_a);
		x.max = (x.min + x.push) - 1;
		x.med = (x.min + x.max) / 2;
		while (x.push != 0)
		{
			x.ch = find_first_s(stack_a, x.min, x.max);
			if (x.ch <= size / 2)
				x.push = is_low(stack_a, stack_b, x, size);
			else if (x.ch > size / 2)
				x.push = is_up(stack_a, stack_b, x, size);
		}
		size = stack_size(stack_a);
	}
	sort_5(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}
