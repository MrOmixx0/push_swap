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
	stack->top = NULL;
}

int	push(t_stack *stack, int value)
{
	int		*content;
	t_list	*node;

	content = malloc(sizeof(int));
	if (!content)
		return (-1);
	*content = value;
	node = ft_lstnew(content);
	if (!node)
	{
		free(content);
		return (-1);
	}
	ft_lstadd_front(&stack->top, node);
	return (0);
}

int	pop(t_stack *stack)
{
	t_list	*temp;
	int		value;

	if (!stack->top)
		return (-1);
	temp = stack->top;
	value = *(int *)(temp->content);
	stack->top = temp->next;
	free(temp->content);
	free(temp);
	return (value);
}
