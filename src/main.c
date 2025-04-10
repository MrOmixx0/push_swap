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

static void free_split(char **split)
{
    int i = 0;
    while (split[i])
        free(split[i++]);
    free(split);
}

static char *join_args(int argc, char **argv)
{
    char *joined = NULL;
    char *temp;
    int i = 1;

    if (argc < 2)
        return (NULL);
    joined = ft_strdup(argv[i]); // Start with first arg
    if (!joined)
        handle_error();
    i++;
    while (i < argc)
    {
        temp = joined;
        joined = ft_strjoin(temp, " "); // Add space
        free(temp);
        if (!joined)
            handle_error();
        temp = joined;
        joined = ft_strjoin(temp, argv[i]); // Add next arg
        free(temp);
        if (!joined)
            handle_error();
        i++;
    }
    return (joined);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int     min_val;
    int     size;
    char    *joined;
    char    **args;

    init_stack(&a);
    init_stack(&b);
    if (argc < 2)
        return (0);
    joined = join_args(argc, argv);
    if (!joined)
        return (0);
    args = ft_split(joined, ' ');
    free(joined);
    if (!args || !args[0]) // Empty or failed split
    {
        if (args)
            free_split(args);
        return (0);
    }
    min_val = parse_args(&a, args, &min_val);
    free_split(args);
    size = ft_lstsize(a.top);
    if (is_sorted(&a))
    {
        ft_lstclear(&a.top, free);
        return (0);
    }
    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size <= 5)
        sort_five(&a, &b);
    else
        radix_sort(&a, &b, min_val);
    ft_lstclear(&a.top, free);
    ft_lstclear(&b.top, free);
    return (0);
}