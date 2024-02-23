/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/23 19:54:36 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void primary_validation(int argc, char *argv)
{
  char **map;

  map = read_line(&argv[1]);
  if (argc < 2)
    ft_error("ERROR! you need to pass the map file as a argument.");
  else if (argc > 2)
    ft_error("ERROR! you had surpassed the number of arguments.");
  else if (ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == 0)
    ft_error("ERROR! the map must be a archive .ber");
  else if (check_map_chars(map) == FALSE)
    ft_error("ERROR! a not identify charecter is in the map.");
  // else check_map(map);
}

int check_map_chars(char **map)
{
  int idx_str;
  int idx_char;

  idx_str = 0;
  while (map[idx_str])
  {
    idx_char = -1;
    while (map[idx_str][++idx_char] && idx_char >= 0)
    {
      if(ft_strchr("01CEP", map[idx_str][idx_char]) == NULL)
        return (FALSE);
    }
    idx_str++;
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

int check_square(t_map game_map, char **map)
{
  int idx_str;

  idx_str = 0;
  while(map[idx_str])
  {
    if (game_map.width != ft_strlen(map[idx_str]))
      return (ft_error(NOT_SQUARE), FALSE);
    idx_str++;
  }
  return (TRUE);
}
