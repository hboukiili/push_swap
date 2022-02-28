/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:35:11 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/24 02:18:32 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cmp(int x, int *str, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (str[i] == x)
			return (i);
		i++;
	}
	return (0);
}

void	ft_index2(int *str, t_list **stack, int y)
{
	int		i;
	int		x;
	t_list	*tmp;

	tmp = *stack;
	i = 0;
	while (tmp != NULL)
	{
		x = tmp->value;
		tmp->index = ft_cmp(x, str, y);
		tmp = tmp->next;
	}
	free (str);
}

int	*sort_tab(int *str, int y)
{
	int	i;
	int	n;
	int	x;

	i = 0;
	while (i < y)
	{
		x = i + 1;
		while (x < y)
		{
			if (str[i] > str[x])
			{
				n = str[i];
				str[i] = str[x];
				str[x] = n;
			}
			x++;
		}
		i++;
	}
	return (str);
}

void	ft_index(t_list **stack_a, int y)
{
	int		*str;
	int		i;
	t_list	*head;

	i = 0;
	head = *stack_a;
	str = malloc(sizeof(int) * y);
	if (!str)
		exit(1);
	while (head)
	{
		str[i] = head->value;
		head = head->next;
		i++;
	}
	sort_tab(str, y);
	ft_index2(str, stack_a, y);
}

int	find_first_s(t_list **stack_a, int i, int x)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index >= i && tmp->index <= x)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}
