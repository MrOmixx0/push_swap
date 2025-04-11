/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:34:12 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/10 19:34:12 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *b)
{
	t_list	*top;

	top = b->top;
	if (!top || !top->next)
		return ;
	b->top = top->next;
	ft_lstadd_back(&(b->top), top);
	top->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *b)
{
	t_list	*last;
	t_list	*prev;

	last = b->top;
	prev = NULL;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	write(1, "rrb\n", 4);
}
