/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:01:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/10 14:05:00 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_stack *a)
{
    t_list  *current;
    int     max = 0;
    int     bits;

    current = a->top;
    while (current)
    {
        int value = *(int *)(current->content);
        if (value > max)
            max = value;
        current = current->next;
    }
    bits = 0;
    while (max)
    {
        max >>= 1;
        bits++;
    }
    return (bits);
}

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits;
    int i;
    int j;
    int size;

    // Normalize the stack first - this replaces each value with its rank
    normalize_stack(a);
    
    // Get the maximum number of bits needed
    max_bits = get_max_bits(a);
    i = 0;
    while (i < max_bits)
    {
        size = ft_lstsize(a->top);
        j = 0;
        while (j < size)
        {
            if ((((*(int *)(a->top->content)) >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j++;
        }
        while (b->top)
            pa(a, b);
        i++;
    }
}