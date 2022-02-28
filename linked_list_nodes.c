/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 05:51:06 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/24 23:52:04 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*creaction_nodes(int value, int index)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	add_last(t_list **stack, t_list **new_nodes)
{
	t_list	*last_node;

	if (*stack == NULL)
	{
		*stack = *new_nodes;
		(*stack)->next = NULL;
	}
	else
	{
		last_node = (*stack);
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = *new_nodes;
	}
}

void	del_nodes(t_list **stack, t_list *tmp1)
{
	t_list	*head;

	head = tmp1;
	tmp1 = (*stack)->next;
	(*stack) = tmp1;
	free(head);
}

void	add_front(t_list **stack, t_list **new_node)
{
	(*new_node)->next = (*stack);
	(*stack) = (*new_node);
}

void	del_lastnodes(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	head = tmp->next;
	tmp->next = NULL;
	free(head);
}
