/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:58:47 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/08 08:39:04 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup("");
	if (argc < 2)
		return (NULL);
	if (!joined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = joined;
		if (i > 1)
		{
			joined = ft_strjoin(temp, " ");
			free(temp);
			if (!joined)
				return (NULL);
			temp = joined;
		}
		joined = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!joined)
			return (NULL);
		i++;
	}
	return (joined);
}

static void	dispatch_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_lstsize(a->top);
	if (is_sorted(a))
	{
		ft_lstclear(&a->top, free);
		return ;
	}
	if (size <= 2)
		sort_two(a);
	else if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
	ft_lstclear(&a->top, free);
	ft_lstclear(&b->top, free);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char *joined;
	char **args;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	joined = join_args(argc, argv);
	if (!joined)
	{
		ft_lstclear(&a.top, free);
		ft_lstclear(&b.top, free);
		handle_error();
	}
	args = ft_split(joined, ' ');
	free(joined);
	if (!args)
	{
		ft_lstclear(&a.top, free);
		ft_lstclear(&b.top, free);
		handle_error();
	}
	if (!args[0])
	{
		free_split(args);
		ft_lstclear(&a.top, free);
		ft_lstclear(&b.top, free);
		handle_error();
	}
	if (parse_args(&a, args, &(int){INT_MAX}) < 0)
	{
		free_split(args);
		ft_lstclear(&a.top, free);
		ft_lstclear(&b.top, free);
		handle_error();
	}
	free_split(args);
	dispatch_sort(&a, &b);
	return (0);
}