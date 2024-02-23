/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/23 19:50:06 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This fuction is used to open and read the choosed map archive.
I use the temp_buffer to stored the tempory the data, memory allocation
and doing all the verifications on this pointer.
Then after using as a parameter to ft_split, the data is erased.
char_read: get the numb of chars in fuction read.
map: return the result of ft_split.
*/

char **read_line(char *map_path)
{
	int fd;
	char *temp_buffer;
	char **map;
	int char_read;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (ft_error(ALLOCATION), NULL);
	fd = open(&map_path[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		ft_printf("%d", fd);
		return (ft_error(OPEN_FILE), NULL);
	}
	char_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (char_read == 0)
		return (ft_error(EMPTY_MAP), NULL);
	temp_buffer[char_read] = '\0';
	if (buffer_noempty_line(temp_buffer, char_read) == FALSE)
		return (ft_error(EMPTY_LINE), NULL);
	map = ft_split(temp_buffer, '\n');
	free(temp_buffer);
	close(fd);
	set_game_map(map);
	return (map);
}

// void    *ft_free_split(char **split)
// {
//     int    i;

//     i = 0;
//     while (split[i])
//     {
//         free(split[i]);
//         i++;
//     }
//     free(split);
//     return (NULL);
// }
