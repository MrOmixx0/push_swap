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
		return (free(content), -1);
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

long	ft_atol(char *nptr)
{
	long	i;
	long	sign;
	long	results;

	i = 0;
	sign = 1;
	results = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		results = results * 10 + (nptr[i] - 48);
		i++;
		if (results * sign > INT_MAX || results * sign < INT_MIN)
			break ;
	}
	return (results * sign);
}

int	find_min_position(t_stack *a)
{
	t_list	*current;
	int		min_val;
	int		min_pos;
	int		current_pos;

	if (!a->top)
		return (-1);
	current = a->top;
	min_val = *(int *)(current->content);
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (*(int *)(current->content) < min_val)
		{
			min_val = *(int *)(current->content);
			min_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (min_pos);
}
