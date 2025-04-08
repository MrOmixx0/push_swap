/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:00:23 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:40:19 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (!a->top || !a->top->next)
		return ;
	temp = pop(a);   // Pop top
	push(a, pop(a)); // Swap with second
	push(a, temp);   // Push first back
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->top)
		return ;
	push(b, pop(a)); // Move top of a to b
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->top)
		return ;
	push(a, pop(b)); // Move top of b to a
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_list	*temp;
	t_list	*last;

	if (!a->top || !a->top->next)
		return ;
	temp = a->top;             // Save top
	a->top = temp->next;       // Move top to next
	temp->next = NULL;         // Detach
	last = ft_lstlast(a->top); // Find last node
	last->next = temp;         // Attach to end
	write(1, "ra\n", 3);
}
