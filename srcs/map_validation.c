/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/27 20:12:23 by cshingai         ###   ########.fr       */
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
  if (game_border(map, game_map) == FALSE)
    ft_error(BORDER_WRONG);
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
  while (y < game_map.width)
  {
    if ((map[0][y] != '1') || (map[game_map.height - 1][y] != '1'))
      return (FALSE);
    y++;
  }
  while (x < game_map.height)
  {
    ft_printf("%s\n", &map[x][0]);
    if ((map[x][0] != '1') || (map[x][game_map.width - 1] != '1'))
      return (FALSE);
    x++;
  }
  return (TRUE);
}
