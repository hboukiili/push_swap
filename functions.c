/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:49:01 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/24 02:11:00 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (!str[i])
	{
		error("Error");
		exit(1);
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

int	ft_isdigit(int a)
{
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	check_small_value(t_list **stack_a)
{
	t_list	*tmp;
	int		x;

	if (!*stack_a)
		return (0);
	x = (*stack_a)->index;
	tmp = (*stack_a);
	while (tmp != NULL)
	{
		if (tmp->index < x)
			x = tmp->index;
		tmp = tmp->next;
	}
	return (x);
}

int	stack_size(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
