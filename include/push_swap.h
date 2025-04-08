/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:52:20 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:37:58 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "unistd.h"
# include "libft.h"

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

void				init_stack(t_stack *stack);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				sa(t_stack *a);
void				pb(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				radix_sort(t_stack *a, t_stack *b);
int					is_sorted(t_stack *a);
void				handle_error(void);
int					get_max_bits(t_stack *a);

#endif
