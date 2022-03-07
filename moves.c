/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:42:22 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/07 02:57:06 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa_move(t_list **stack_a, int l)
{
	t_list	*tmp1;

	if (count_stack(stack_a) > 1)
	{
		tmp1 = (*stack_a)->next;
		(*stack_a)->next = tmp1->next;
		tmp1->next = (*stack_a);
		*stack_a = tmp1;
		if (l == 0)
			write(1, "sa\n", 3);
	}
}

void	sb_move(t_list **stack_b, int l)
{
	t_list	*tmp1;

	if (count_stack(stack_b) > 1)
	{
		tmp1 = (*stack_b)->next;
		(*stack_b)->next = tmp1->next;
		tmp1->next = (*stack_b);
		*stack_b = tmp1;
		if (l == 0)
			write(1, "sb\n", 3);
	}
}

void	ss_move(t_list **stack_a, t_list **stack_b, int l)
{
	if (count_stack(stack_a) > 1 && count_stack(stack_a) > 1)
	{
		sa_move(stack_a, 1);
		sb_move(stack_b, 1);
		if (l == 0)
			write(1, "ss\n", 3);
	}
}

void	pb_move(t_list **stack_a, t_list **stack_b, int l)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		a;
	int		index;

	if (*stack_a != NULL)
	{
		tmp1 = (*stack_a);
		a = (*stack_a)->value;
		index = (*stack_a)->index;
		tmp2 = creaction_nodes(a, index);
		add_front(stack_b, &tmp2);
		del_nodes(stack_a, tmp1);
		if (l == 0)
			write(1, "pb\n", 3);
	}
}

void	pa_move(t_list **stack_a, t_list **stack_b, int l)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		a;
	int		x;

	if (*stack_b != NULL)
	{
		tmp = (*stack_b);
		a = (*stack_b)->value;
		x = (*stack_b)->index;
		tmp2 = creaction_nodes(a, x);
		add_front(stack_a, &tmp2);
		del_nodes(stack_b, tmp);
		if (l == 0)
			write(1, "pa\n", 3);
	}
}
