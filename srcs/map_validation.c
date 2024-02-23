/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/23 02:25:26 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void primary_validation(int argc, char *argv)
{
  char **map;

  map = read_line(&argv[1]);
  if (argc < 2)
    ft_printf("ERROR! you need to pass the map file as a argument.");
  else if (argc > 2)
    ft_printf("ERROR! you had surpassed the number of arguments.");
  else if (ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == 0)
    ft_printf("ERROR! the map must be a archive .ber");
  else if (map == NULL)
    ft_printf("ERROR!");
  else if (check_map_chars(map) == FALSE)
    ft_printf("ERROR! a not identify charecter is in the map.");
  // else check_map(map);
}

int check_map_chars(char **map)
{
  int idx_str;
  int idx_char;

  idx_str = 0;
  while (map[idx_str])
  {
    idx_char = 0;
    while (map[idx_str][idx_char] && idx_char >= 0)
    {
      if (map[idx_str][idx_char] == '0' || (map[idx_str][idx_char] == '1') ||
          (map[idx_str][idx_char] == 'C') || (map[idx_str][idx_char] == 'E') ||
          (map[idx_str][idx_char] == 'P'))
        idx_char++;
      else
        return (FALSE);
    }
    idx_str++;
  }
  return (TRUE);
}

int buffer_empty_line(char *temp_buffer, int char_read)
{
  int idx;

  idx = 0;
  while (idx <= char_read)
  {
    if (temp_buffer[idx] == '\n' && temp_buffer[idx + 1] == '\n')
    {
      free(temp_buffer);
      ft_printf("ERROR! unvalid map, there is a empty line.");
      ft_error();
      return (TRUE);
    }
    idx++;
  }
  return (FALSE);
}

int check_map_game(t_map game_map, char **map)
{
  int idx_str;

  idx_str = 0;
  while(map[idx_str])
  {
    if (game_map.width != ft_strlen(map[idx_str]))
    {
      ft_printf("ERROR! the map is not square");
      return (FALSE);
    }
    idx_str++;
  }
  return (TRUE);
}
