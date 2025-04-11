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
	temp = pop(a);
	push(a, pop(a));
	push(a, temp);
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->top)
		return ;
	push(b, pop(a));
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->top)
		return ;
	push(a, pop(b));
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_list	*temp;
	t_list	*last;

	if (!a->top || !a->top->next)
		return ;
	temp = a->top;
	a->top = temp->next;
	temp->next = NULL;
	last = ft_lstlast(a->top);
	last->next = temp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	t_list	*last;
	t_list	*second_last;

	if (!a->top || !a->top->next)
		return ;
	last = ft_lstlast(a->top);
	second_last = a->top;
	while (second_last->next != last)
		second_last = second_last->next;
	second_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}
