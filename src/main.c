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

	if (argc < 2)
		return (NULL);
	joined = ft_strdup(argv[1]);
	if (!joined)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		temp = joined;
		joined = ft_strjoin(temp, " ");
		if (!joined)
			return (free(temp), NULL);
		temp = joined;
		joined = ft_strjoin(temp, argv[i]);
		if (!joined)
			return (free(temp), NULL);
		free(temp);
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

void	handle_cleanup(t_stack *a, t_stack *b, char **args,
		void (*free_func)(char **))
{
	if (args && free_func)
		free_func(args);
	ft_lstclear(&a->top, free);
	ft_lstclear(&b->top, free);
	handle_error();
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*joined;
	char	**args;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	joined = join_args(argc, argv);
	if (!joined)
		handle_cleanup(&a, &b, NULL, NULL);
	args = ft_split(joined, ' ');
	free(joined);
	if (!args || !args[0] || parse_args(&a, args) < 0)
		handle_cleanup(&a, &b, args, free_split);
	free_split(args);
	dispatch_sort(&a, &b);
	return (0);
}
