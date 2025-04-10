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

static char *join_args(int argc, char **argv)
{
    char *joined = NULL;
    char *temp;
    int i = 1;

    if (argc < 2)
        return (NULL);
    joined = ft_strdup("");
    if (!joined)
        return (NULL);
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
    i = 0;
    while (joined[i])
    {
        if (joined[i] != ' ')
            break;
        i++;
    }
    if (!joined[i])
    {
        free(joined);
        return (NULL);
    }
    return (joined);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;
    int     min_val;
    char    *joined = NULL;
    char    **args = NULL;

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
    if (!args || !args[0])
    {
        if (args)
            free_split(args);
        ft_lstclear(&a.top, free);
        ft_lstclear(&b.top, free);
        handle_error();
    }
    if (parse_args(&a, args, &min_val) < 0)
    {
        free_split(args);
        ft_lstclear(&a.top, free);
        ft_lstclear(&b.top, free);
        handle_error();
    }
    free_split(args);
    if (is_sorted(&a))
    {
        ft_lstclear(&a.top, free);
        return (0);
    }
    if (ft_lstsize(a.top) <= 2)
        sort_two(&a);
    else if (ft_lstsize(a.top) <= 3)
        sort_three(&a);
    else if (ft_lstsize(a.top) <= 5)
        sort_five(&a, &b);
    else
        radix_sort(&a, &b);
    ft_lstclear(&a.top, free);
    ft_lstclear(&b.top, free);
    return (0);
}