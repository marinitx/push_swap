/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:26:27 by mhiguera          #+#    #+#             */
/*   Updated: 2024/03/26 20:08:47 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack			*ft_lstnew(int content);
void			ft_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack			*ft_lstlast(t_stack *lst);
void			check_args(int argc, char **argv);
void			check_num(char *num);
void			check_dup(int num, char **args, int i);
int				check_sorted(t_stack **stack_a);
int				ft_lstsize(t_stack *lst);
void			sa(t_stack **stack_a);
void			ss(t_stack **stack_a, t_stack **stack_b);
void			sb(t_stack **stack_b);
void			print_stack(t_stack *stack);
void			pa(t_stack **stack_a, t_stack **stack_b);
void			pb(t_stack **stack_a, t_stack **stack_b);
void			ra(t_stack **stack_a);
void			rb(t_stack **stack_b);
void			rr(t_stack **stack_a, t_stack **stack_b);
void			rra(t_stack **stack_a);
void			rra(t_stack **stack_a);
void			rrb(t_stack **stack_b);
void			sort2(t_stack **stack_a);
void			sort3(t_stack **stack_a);
void			sort5(t_stack **stack_a, t_stack **stack_b);
int				get_min(t_stack *stack);
int				get_max(t_stack *stack);
void			radix(t_stack **stack_a, t_stack **stack_b);
void			ft_free_stack(t_stack **stack);
char			**ft_split(const char *s, char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_free_str(char **str);
void			add_index_to_stack(t_stack **stack);
t_stack			*get_next_min(t_stack **stack);
void			ft_error(void);
long long int	ft_atol(const char *str);

#endif