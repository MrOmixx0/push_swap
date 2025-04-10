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
int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(t_stack *a, int argc, char **argv, int *min_val)
{
	int		i;
	long	num;
	t_list	*node;
	int		*content;

	*min_val = INT_MAX;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			handle_error();
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			handle_error();
		if (is_duplicate(a, (int)num))
			handle_error();
		content = malloc(sizeof(int));
		if (!content)
			handle_error();
		*content = (int)num;
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			handle_error();
		}
		ft_lstadd_back(&a->top, node);
		if (*content < *min_val)
			*min_val = *content;
		i++;
	}
	return (*min_val);
}
