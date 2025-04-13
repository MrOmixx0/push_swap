/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:55:00 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/10 13:55:00 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack, int size)
{
	t_list	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i++] = *(int *)(current->content);
		current = current->next;
	}
	return (arr);
}

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	find_position(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack *stack)
{
	t_list	*current;
	int		*arr;
	int		size;
	int		pos;

	size = ft_lstsize(stack->top);
	arr = stack_to_array(stack, size);
	if (!arr)
		return ;
	insertion_sort(arr, size);
	current = stack->top;
	while (current)
	{
		pos = find_position(arr, size, *(int *)(current->content));
		*(int *)(current->content) = pos;
		current = current->next;
	}
	free(arr);
}
