/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:47:44 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/10 09:47:45 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_stack *a)
{
    if (*(int *)(a->top->content) > *(int *)(a->top->next->content))
        sa(a);
}

void sort_three(t_stack *a)
{
    int first = *(int *)(a->top->content);
    int second = *(int *)(a->top->next->content);
    int third = *(int *)(ft_lstlast(a->top)->content);

    if (first > second && second < third && first < third) // 2 1 3
        sa(a);
    else if (first > second && second > third) // 3 2 1
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third) // 3 1 2
        ra(a);
    else if (first < second && second > third && first < third) // 1 3 2
        {
            sa(a);
            ra(a);
        }
    else if (first < second && second > third) // 2 3 1
        rra(a);
}
