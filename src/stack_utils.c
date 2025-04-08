/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:59:38 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:14:41 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL; // No nodes yet
	stack->size = 0;
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		handle_error();
	new_node->value = value;
	new_node->next = stack->top; // Link to old top
	stack->top = new_node;       // New top
	stack->size++;
}

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		handle_error();
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next; // Move top to next node
	free(temp);
	stack->size--;
	return (value);
}
