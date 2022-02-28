/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:38:01 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 20:51:18 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	functions_sup(t_list **stack_a, t_list **stack_b)
{
	int		i;

	check_double(stack_a);
	if (!check_sort(stack_a))
		exit(1);
	i = count_stack(stack_a);
	ft_index(stack_a, i);
	if (i == 2)
		sort_2(stack_a);
	if (i == 3)
		sort_3(stack_a);
	if (i == 4)
		sort_4(stack_a, stack_b);
	if (i == 5)
		sort_5(stack_a, stack_b);
	if (i > 5)
		sort_100(stack_a, stack_b, i);
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
		while (i < ac)
		{
			checker_d(av[i]);
			pam = ft_atoi(av[i]);
			check_max(pam);
			tmp = creaction_nodes(pam, 0);
			add_last(&stack_a, &tmp);
			i++;
		}
		functions_sup(&stack_a, &stack_b);
	}
}
