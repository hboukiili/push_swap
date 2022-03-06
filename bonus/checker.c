/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:32:29 by hboukili          #+#    #+#             */
/*   Updated: 2022/03/06 22:57:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	ft_strcmp(char *str, char *str1)
{
	int	i;

	i = 0;
	while (str[i] && str1[i] && str[i] == str1[i])
		i++;
	return (str[i] - str1[i]);
}

void	checker2(t_list **stack_a, t_list **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa_move(stack_a, 1);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb_move(stack_b, 1);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss_move(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra_move(stack_a, 1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb_move(stack_b, 1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr_move(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa_move(stack_a, stack_b, 1);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb_move(stack_a, stack_b, 1);
	else
	{
		error("Error");
		exit(1);
	}
}

void	res(t_list **stack_a, int i)
{
	if (count_stack(stack_a) == i)
	{
		if (!check_sort(stack_a))
			error("OK");
		else
			error("KO");
	}
	else
		error("KO");
}

void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	i = count_stack(stack_a);
	while (str)
	{
		if (ft_strcmp(str, "ra\n") == 0)
			ra_move(stack_a, 1);
		else if (ft_strcmp(str, "rb\n") == 0)
			rb_move(stack_b, 1);
		else if (ft_strcmp(str, "rr\n") == 0)
			rr_move(stack_a, stack_a, 1);
		else
			checker2(stack_a, stack_b, str);
		free(str);
		str = get_next_line(0);
	}
	res(stack_a, i);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	int		i;
	long	pam;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		while (av[i])
		{
			checker_d(av[i]);
			pam = ft_atoi(av[i]);
			check_max(pam);
			tmp = creaction_nodes(pam, 0);
			add_last(&stack_a, &tmp);
			i++;
		}
		check_double(&stack_a);
		checker(&stack_a, &stack_b);
	}
	//system("leaks checker");
}
