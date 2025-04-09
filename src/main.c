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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		min_val;

	init_stack(&a);
	init_stack(&b);
	if (argc < 2)
		return (0);
	min_val = parse_args(&a, argc, argv, &min_val);
	if (is_sorted(&a))
	{
		ft_lstclear(&a.top, free);
		return (0);
	}
	radix_sort(&a, &b, min_val);
	ft_lstclear(&a.top, free);
	ft_lstclear(&b.top, free);
	return (0);
}
