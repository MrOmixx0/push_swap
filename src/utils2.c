/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 09:12:58 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/10 09:13:02 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Move minimum element to top of stack efficiently
void	move_min_to_top(t_stack *a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(a);
	size = ft_lstsize(a->top);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
}

// Find position of the maximum value in stack
int	find_max_position(t_stack *stack)
{
	t_list	*curr;
	int		max_val;
	int		max_pos;
	int		curr_pos;

	if (!stack->top)
		return (-1);
	curr = stack->top;
	max_val = *(int *)(curr->content);
	max_pos = 0;
	curr_pos = 0;
	while (curr)
	{
		if (*(int *)(curr->content) > max_val)
		{
			max_val = *(int *)(curr->content);
			max_pos = curr_pos;
		}
		curr_pos++;
		curr = curr->next;
	}
	return (max_pos);
}

// Move the maximum element to top of stack B efficiently
void	move_max_to_top_b(t_stack *b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_position(b);
	size = ft_lstsize(b->top);
	if (max_pos <= size / 2)
	{
		while (max_pos-- > 0)
			rb(b);
	}
	else
	{
		while (max_pos++ < size)
			rrb(b);
	}
}
