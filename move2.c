/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:47:39 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 23:41:51 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra_move(t_list **stack_a, int l)
{
	int		a;
	int		i;
	t_list	*tmp2;
	t_list	*tmp;

	if (stack_size(stack_a) > 0)
	{
		tmp = (*stack_a);
		a = tmp->value;
		i = tmp->index;
		tmp2 = creaction_nodes(a, i);
		add_last(stack_a, &tmp2);
		del_nodes(stack_a, tmp);
		if (l == 0)
			error("ra");
	}
}

void	rb_move(t_list **stack_b, int l)
{
	int		a;
	int		i;
	t_list	*tmp;
	t_list	*tmp2;

	if (count_stack(stack_b) > 0)
	{	
		tmp = (*stack_b);
		a = tmp->value;
		i = tmp->index;
		tmp2 = creaction_nodes(a, i);
		add_last(stack_b, &tmp2);
		del_nodes(stack_b, tmp);
		if (l == 0)
			error("rb");
	}
}

void	rr_move(t_list **stack_a, t_list **stack_b, int i)
{
	if (count_stack(stack_a) > 0 && count_stack(stack_b) > 0)
	{
		ra_move(stack_a, 1);
		rb_move(stack_b, 1);
		if (i == 0)
			error("rr");
	}
}

void	rra_move(t_list **stack_a, int l)
{
	t_list	*tmp;
	int		a;
	t_list	*tmp2;
	int		i;

	if (count_stack(stack_a) > 0)
	{	
		tmp = (*stack_a);
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		a = tmp->next->value;
		i = tmp->next->index;
		tmp2 = creaction_nodes(a, i);
		add_front(stack_a, &tmp2);
		del_lastnodes(tmp);
		if (l == 0)
			error("rra");
	}
}

void	rrb_move(t_list **stack_b, int l)
{
	t_list	*tmp;
	int		a;
	int		i;
	t_list	*tmp2;

	if (count_stack(stack_b) > 1)
	{
		tmp = (*stack_b);
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		a = tmp->next->value;
		i = tmp->next->index;
		tmp2 = creaction_nodes(a, i);
		add_front(stack_b, &tmp2);
		del_lastnodes(tmp);
		if (l == 0)
			error("rrb");
	}
}
