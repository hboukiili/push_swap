/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortof_2_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:04:43 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 21:07:59 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_2(t_list **stack)
{
	sa_move(stack, 0);
}

void	sort_3(t_list **stack)
{
	int	i;

	i = check_3(stack);
	if (i == 1)
		sort_2(stack);
	if (i == 2)
	{
		sort_2(stack);
		rra_move(stack, 0);
	}
	if (i == 3)
		ra_move(stack, 0);
	if (i == 4)
	{
		sort_2(stack);
		ra_move(stack, 0);
	}
	if (i == 5)
		rra_move(stack, 0);
}

int	check_3(t_list **stack)
{
	int	i;
	int	j;
	int	x;

	x = (*stack)->index;
	j = (*stack)->next->index;
	i = (*stack)->next->next->index;
	if (x > j && x < i && j < i)
		return (1);
	if (x > j && j > i && x > i)
		return (2);
	if (x > j && x > i && j < i)
		return (3);
	if (x < j && j > i && i > x)
		return (4);
	if (x < j && j > i && i < x)
		return (5);
	return (0);
}
