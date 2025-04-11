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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	get_max_bits(t_stack *a)
{
	t_list	*current;
	int		max;
	int		bits;

	current = a->top;
	max = 0;
	bits = 0;
	while (current)
	{
		if (*(int *)(current->content) > max)
			max = *(int *)(current->content);
		current = current->next;
	}
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		size;

	normalize_stack(a);
	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(a->top);
		while (size)
		{
			if ((((*(int *)(a->top->content)) >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (b->top)
			pa(a, b);
		i++;
	}
}
