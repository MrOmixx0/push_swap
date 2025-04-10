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
# include "ft_printf.h"
# include "limits.h"

typedef struct s_stack
{
    t_list  *top;
}   t_stack;

void    init_stack(t_stack *stack);
int     push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    sa(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rra(t_stack *a);
void    radix_sort(t_stack *a, t_stack *b, int min_val);
int     is_sorted(t_stack *a);
void    handle_error(void);
int     get_max_bits(t_stack *a, int min_val);
int     is_valid_number(const char *str);
int     parse_args(t_stack *a, char **args, int *min_val);
long    ft_atol(char *nptr);
void    sort_two(t_stack *a);
void    sort_three(t_stack *a);
void    sort_five(t_stack *a, t_stack *b);
void    free_split(char **split);

#endif