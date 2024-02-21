/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/21 17:54:38 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(char **map)
{
  int idx_str;
  int idx_char;

  idx_str = 0;
  idx_char = 0;
  while (map[idx_str])
  {
    if (check_map_chars(*map, idx_char) == FALSE)
    {
      ft_printf("ERROR! a not identify charecter is in the map.");
      return ;
    }
    else if (check_map_square(*map, idx_char) == FALSE)
    {
      ft_printf("ERROR! the map is not square.");
      return ;
    }
    else if (empty_map(map) == FALSE)
      ft_printf("ERROR! empty map.");
    idx_str++;
  }
  check_map_square(*map, idx_char);
  printf("deu bom");
  // ft_printf("%d", ft_strlen(&map[idx_str][idx_char]));
}
// the 0 is false, 1 is true.
int check_map_chars(char *map, int idx_char)
{
  while (map[idx_char])
  {
    if (map[idx_char] == '0')
      idx_char++;
    else if (map[idx_char] == '1')
      idx_char++;
    else if (map[idx_char] == 'C')
      idx_char++;
    else if (map[idx_char] == 'E')
      idx_char++;
    else if (map[idx_char] == 'P')
      idx_char++;
    else
      return (FALSE);
  }
  return(TRUE);
}

int check_map_square(char *map, int idx_char)
{
  while(map[idx_char])
  {
    if(ft_strlen(&map[idx_char]) != ft_strlen(&map[idx_char + 1]))
      return(FALSE);
    else
      idx_char++;
  }
  return(TRUE);
}

int empty_map(char **map)
{
  if (map[0])
    return(TRUE);
  else
    return(FALSE);
}
