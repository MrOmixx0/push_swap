/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:59:38 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:40:02 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL; // Empty stack
}

void	push(t_stack *stack, int value)
{
	int		*content;
	t_list	*new_node;

	content = malloc(sizeof(int));
	if (!content)
		handle_error();
	*content = value;
	new_node = ft_lstnew(content); // Create new node
	if (!new_node)
	{
		free(content);
		handle_error();
	}
	ft_lstadd_front(&stack->top, new_node); // Add to top
}

int	pop(t_stack *stack)
{
	t_list	*temp;
	int		value;

	if (!stack->top)
		handle_error();
	temp = stack->top;
	value = *(int *)(temp->content); // Get value
	stack->top = temp->next;         // Move top
	ft_lstdelone(temp, free);        // Free node and content
	return (value);
}
