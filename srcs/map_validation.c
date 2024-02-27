/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/27 19:39:37 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  check_map_game(char **map, t_map game_map)
{
  int idx_str;

  idx_str = 0;
  while (map[idx_str])
  {
    if (check_map_chars(map[idx_str]) == FALSE)
      ft_error("ERROR! a not identify charecter is in the map.");
    idx_str++;
  }
  if (check_square(map, game_map) == FALSE)
    ft_error(NOT_SQUARE);

}

int check_map_chars(char *map)
{
  int idx_char;

    idx_char = -1;
    while (map[++idx_char] && idx_char >= 0)
    {
      if(ft_strchr("01CEP", map[idx_char]) == NULL)
        return (FALSE);
    }
  return (TRUE);
}

int buffer_noempty_line(char *temp_buffer, int char_read)
{
  int idx;

  idx = 0;
  while (idx <= char_read)
  {
    if (temp_buffer[idx] == '\n' && temp_buffer[idx + 1] == '\n')
    {
      free(temp_buffer);
      return (FALSE);
    }
    idx++;
  }
  return (TRUE);
}

int check_square(char **map, t_map game_map)
{
  int idx_str;

  idx_str = 0;
  while(map[idx_str])
  {
    if (game_map.width != ft_strlen(map[idx_str]))
      return (FALSE);
    idx_str++;
  }
  return (TRUE);
}

int game_border(char **map, t_map game_map)
{
  int y;
  int x;

  x = 0;
  y = 0;
  while (map[x])
  {
    if (map[0][y] != 1)
      return(FALSE);
    if (map[game_map.width][y] != 1)
      return(FALSE);
    y++;
  }
  return(TRUE);
}
