/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:01:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:41:07 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_stack *a, int min_val) // Add min_val parameter
{
    t_list  *current;
    long     max;
    int     bits;

    max = 0;
    current = a->top;
    while (current)
    {
        long normalized = (long)*(int *)(current->content) - min_val; // Normalize
        if (normalized > max)
            max = normalized;
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

void    radix_sort(t_stack *a, t_stack *b, int min_val)
{
    int max_bits;
    int i;
    int j;
    int size;

    max_bits = get_max_bits(a, min_val); // Pass min_val
    i = 0;
    while (i < max_bits)
    {
        size = ft_lstsize(a->top);
        j = 0;
        while (j < size)
        {
            if (((((long)*(int *)(a->top->content) - min_val) >> i) & 1) == 0)
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