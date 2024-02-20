/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/20 13:01:23 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void primary_validation(int argc, char *argv)
{
  // char **map;
  
  if (argc < 2)
    ft_printf("ERROR! you need to pass the map file as a argument.");
  else if (argc > 2)
    ft_printf("ERROR! you had surpassed the number of arguments.");
  else if (ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == 0)
    ft_printf("ERROR! the map must be a archive .ber");
  else
    // map = read_line(&argv[1]);
    check_map(read_line(&argv[1]));
}
/* This fuction is used to open and read the choosed map archive.
I use the temp_buffer to stored the tempory the data, memory allocation
and doing all the verifications on this pointer.
Then after using as a parameter to ft_split, the data is erased.
*/

char **read_line(char *map_path)
{
  int fd;
  char *temp_buffer;
  char **map;
  int char_read;

  temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
  if (!temp_buffer)
    return(NULL);
  fd = open(&map_path[1], O_RDONLY);
  if (fd < 0 || read(fd, 0, 0) < 0)
    return(NULL);
  char_read = read(fd, temp_buffer, BUFFER_SIZE);
  temp_buffer[char_read] = '\0';
  map = ft_split(temp_buffer, '\n');
  temp_buffer = ft_calloc(ft_strlen(temp_buffer), sizeof (char));
  close(fd);
  return(map);
}
