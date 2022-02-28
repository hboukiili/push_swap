/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboukili <hboukili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:50:57 by hboukili          #+#    #+#             */
/*   Updated: 2022/02/28 21:32:33 by hboukili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct push
{
	int	min;
	int	max;
	int	med;
	int	push;
	int	ch;
}	t_push;

void	error(char *str);
long	ft_atoi(char *str);
void	check_double(t_list **node);
int		ft_isdigit(int a);
void	checker_d(char *str);
void	add_last(t_list **nodes, t_list **new_nodes);
t_list	*creaction_nodes(int value, int index);
int		check_sort(t_list **node);
void	functions_sup(t_list **stack_a, t_list **stack_b);
void	sa_move(t_list **stack_a, int i);
void	ss_move(t_list **stack_a, t_list **stack_b, int i);
void	sb_move(t_list **stack_b, int i);
void	pb_move(t_list **stack_a, t_list **stack_b, int i);
void	del_nodes(t_list **stack, t_list *tmp1);
void	pa_move(t_list **stack_a, t_list **stack_b, int i);
void	add_front(t_list **stack, t_list **new_node);
void	ra_move(t_list **stack_a, int i);
void	rb_move(t_list **stack_b, int i);
void	rr_move(t_list **stack_a, t_list **stack_b, int i);
void	rra_move(t_list **stack_a, int i);
void	del_lastnodes(t_list *head);
void	rrb_move(t_list **stack_b, int i);
void	rrr_move(t_list **stack_a, t_list **stack_b, int i);
void	sort_3(t_list **stack_a);
void	sort_2(t_list **stack);
int		check_3(t_list **stack);
void	sort_4(t_list **stack, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
int		check_place(t_list **stack_a, int m);
int		check_big(t_list **stack_a);
void	sort_100(t_list **stack_a, t_list **stack_b, int i);
int		check_small_value(t_list **stack_a);
void	ft_index(t_list **stack_a, int y);
void	ft_index2(int *str, t_list **stack, int y);
int		ft_cmp(int x, int *str, int y);
int		*sort_tab(int *str, int y);
int		stack_size(t_list **stack);
int		find_first_s(t_list **stack_a, int i, int x);
int		stack_size(t_list **stack);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strchr(char *s);
int		ft_strlen(char *str);
char	*ft_check(char *a);
char	*ft_print(char *a);
char	*get_len(int fd, char *a);
void	check_max(long x);
int		count_stack(t_list **stack_a);

#endif