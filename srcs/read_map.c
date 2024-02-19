/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/19 19:34:21 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void primary_validation(int argc, char *argv)
{
  if (argc < 2)
    ft_printf("ERROR! you need to pass the map file as a argument.");
  else if (argc > 2)
    ft_printf("ERROR! you had surpassed the number of arguments.");
  else if(ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == 0)
    ft_printf("ERROR! the map must be a archive .ber");
  else
    check_map(&argv[1]);
}

void check_map(char *argv)
{
  int   fd;
  char  *temp_buffer;

  temp_buffer = (char *) malloc (BUFFER_SIZE + 1);
  if(!temp_buffer)
    return ;
  fd = open(argv, O_RDONLY);
  temp_buffer = read(fd, temp_buffer, BUFFER_SIZE);
  ft_printf("%s", temp_buffer);
}
