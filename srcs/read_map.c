/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:27:47 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/07 20:14:16 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	primary_validation(int argc, char *argv)
{
	if (argc < 2)
		ft_error("ERROR! you need to pass the map file as a argument.");
	else if (argc > 2)
		ft_error("ERROR! you had surpassed the number of arguments.");
	else if (ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == 0)
		ft_error("ERROR! the map must be a archive .ber");
}

void	start(char *argv)
{
	t_game	game;
	// t_map	game_map;

	game.map.map = read_line(&argv[1]);
	set_game_map(game.map.map, &game);
	check_map_game(game.map.map, game);
	ft_free_split(game.map.map);
	game.map.map = read_line(&argv[1]);
	init_game(&game);
}

/* This fuction is used to open and read the choosed map archive.
I use the temp_buffer to stored the tempory the data, memory allocation
and doing all the verifications on this pointer.
Then after using as a parameter to ft_split, the data is erased.
char_read: get the numb of chars in fuction read.
map: return the result of ft_split.
*/

char	**read_line(char *map_path)
{
	int		fd;
	char	*temp_buffer;
	char	**map;
	int		char_read;

	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (ft_error(ALLOCATION), NULL);
	fd = open(&map_path[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (ft_error(OPEN_FILE), NULL);
	char_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (char_read == 0)
		return (ft_error(EMPTY_MAP), NULL);
	temp_buffer[char_read] = '\0';
	if (buffer_noempty_line(temp_buffer, char_read) == FALSE)
		return (ft_error(EMPTY_LINE), NULL);
	map = ft_split(temp_buffer, '\n');
	free(temp_buffer);
	close(fd);
	return (map);
}
