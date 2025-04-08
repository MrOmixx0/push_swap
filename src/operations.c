/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:00:23 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:14:53 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = pop(a);   // Remove top
	push(a, pop(a)); // Swap with second
	push(a, temp);   // Put first back
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size == 0)
		return ;
	push(b, pop(a)); // Move top of a to b
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size == 0)
		return ;
	push(a, pop(b)); // Move top of b to a
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_node	*temp;
	t_node	*current;

	if (a->size < 2)
		return ;
	temp = a->top;       // Save top node
	a->top = temp->next; // Move top to next
	current = a->top;
	while (current->next)
		current = current->next; // Find last node
	current->next = temp;        // Attach old top to end
	temp->next = NULL;
	write(1, "ra\n", 3);
}
