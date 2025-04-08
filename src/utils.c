/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:02:03 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:15:19 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (a->size < 2)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0); // Not sorted if current > next
		current = current->next;
	}
	return (1);
}
