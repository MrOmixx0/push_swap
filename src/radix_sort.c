/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:01:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:15:03 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		max;
	int		bits;

	max = 0;
	current = a->top;
	while (current)
	{
		if (current->value > max)
			max = current->value; // Find largest number
		current = current->next;
	}
	bits = 0;
	while (max)
	{
		max >>= 1; // Count bits by shifting
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = a->size; // Number of elements to process
		j = 0;
		while (j < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b); // Bit 0 goes to b
			else
				ra(a); // Bit 1 stays in a, rotated
			j++;
		}
		while (b->size > 0)
			pa(a, b); // Merge b back to a
		i++;
	}
}
