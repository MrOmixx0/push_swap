/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:02:03 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:41:29 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	handle_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;

	if (!a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

static int	is_duplicate(t_stack *a, int value)
{
	t_list	*current;

	current = a->top;
	while (current)
	{
		if (*(int *)(current->content) == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	parse_args(t_stack *a, int argc, char **argv, int *min_val)
{
	int i;
	int place;
	long num;
	char *endptr;

	*min_val = INT_MAX;
	i = 1;
	while (i < argc)
	{
		place = argc - i;
		num = strtol(argv[place], &endptr, 10);
		if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
			handle_error();
		if (is_duplicate(a, (int)num))
			handle_error();
		push(a, (int)num);
		if ((int)num < *min_val)
			*min_val = (int)num;
		i++;
		if (place == 1)
			break ;
	}
	return (*min_val);
}