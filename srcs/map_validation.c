/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 03:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/20 19:16:13 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(char **map)
{
  int idx_str;
  int idx_char;

  idx_str = 0;
  idx_char = 0;
  while (map[idx_str++])
  {
    while (map[idx_str][idx_char++])
    {
      if (map[idx_str][idx_char] == 'R')
      {
        ft_printf("achou o char certo");
        return ;
      }
    }
    ft_printf("não achou nada");
  }
}
