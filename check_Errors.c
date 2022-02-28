/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_Errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 03:44:18 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/27 00:48:18 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	checker_d(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57))
			|| ((str[i] == '+' && (str[i + 1] >= 48 && str[i + 1] <= 57))))
			i++;
		if (!ft_isdigit(str[i]))
		{
			error("Error");
			exit(1);
		}
		if ((ft_isdigit(str[i]))
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
		{
			error("Error");
			exit(1);
		}
		i++;
	}
}

void	check_double(t_list **node)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = (*node);
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		while (tmp2 != NULL)
		{
			if (tmp1->value == tmp2->value)
			{
				error("Error");
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
}

int	check_sort(t_list **node)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp2 = (*node)->next;
	while (tmp2 != NULL)
	{
		tmp1 = (*node);
		while (tmp1 != tmp2)
		{
			if (tmp1->value > tmp2->value)
			{	
				return (1);
			}
			tmp1 = tmp1->next;
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

int	check_big(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		i;
	int		x;

	i = 0;
	x = 0;
	tmp = (*stack_a);
	tmp1 = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->value > x)
			x = tmp->value;
		tmp = tmp->next;
	}
	return (x);
}

int	check_place(t_list **stack_a, int x)
{
	t_list	*tmp1;
	int		i;

	i = 0;
	tmp1 = (*stack_a);
	while (tmp1 != NULL)
	{
		if (tmp1->index == x)
			return (i);
		i++;
		tmp1 = tmp1->next;
	}
	return (0);
}
