/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 03:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/20 13:35:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(char **map)
{
  int idx;

  idx = 0;
  while (*map[idx] != '\0')
  {
    ft_printf("%s\n", map[idx]);
    // if (map[idx] == 0 && map[idx + 1] != 0)
    //   ft_printf("ERROR! empty line.");
    // else
    //   ft_printf("Sem erro.");
    idx++;
  }
}