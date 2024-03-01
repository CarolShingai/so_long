/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:17:38 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/01 18:41:32 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *ft_free_split(char **split)
{
    int    i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
    return (NULL);
}
