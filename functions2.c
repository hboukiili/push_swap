/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:50:17 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 23:48:29 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	count_stack(t_list **stack_a)
{
	t_list	*head;
	int		i;

	head = *stack_a;
	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	check_max(long x)
{
	if (x > 2147483647 || x < -2147483648)
	{
		error("Error");
		exit(1);
	}
}

void	rrr_move(t_list **stack_a, t_list **stack_b, int l)
{
	rra_move(stack_a, 1);
	rrb_move(stack_b, 1);
	if (l == 0)
		error("rrr");
}
