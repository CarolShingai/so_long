/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:35:22 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/20 19:19:08 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map_game(char **map, t_game game)
{
	int	idx_str;

	idx_str = -1;
	while (map[++idx_str])
	{
		if (check_map_chars(map[idx_str]) == FALSE)
			error(W_CHAR, &game);
	}
	if (check_shape(map, game.map) == FALSE)
		error(NOT_SQUARE, &game);
	else if (check_border(map, game.map) == FALSE)
		error(BORDER_WRONG, &game);
	else if (count_itens(game.map.map, 'C') == 0)
		error(COLLECTABLE, &game);
	else if (count_itens(game.map.map, 'P') < 1)
		error(PERSONAGE, &game);
	else if (count_itens(game.map.map, 'P') > 1)
		error(EXTRA_PERS, &game);
	else if (count_itens(game.map.map, 'E') < 1)
		error(EXIT, &game);
	else if (count_itens(game.map.map, 'E') > 1)
		error(EXTRA_EXIT, &game);
	else if (check_flood_fill(game.map) == FALSE)
		error(PATH_ERROR, &game);
}

t_bool	check_map_chars(char *map)
{
	int	idx_char;

	idx_char = -1;
	while (map[++idx_char] && idx_char >= 0)
	{
		if (ft_strchr("01CEPV", map[idx_char]) == NULL)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	buffer_noempty_line(char *temp_buffer, int char_read)
{
	int	idx;

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

t_bool	check_shape(char **map, t_map game_map)
{
	int	idx_str;

	idx_str = 0;
	while (map[idx_str])
	{
		if (game_map.width != ft_strlen(map[idx_str]))
			return (FALSE);
		idx_str++;
	}
	return (TRUE);
}

t_bool	check_border(char **map, t_map game_map)
{
	int	y;
	int	x;

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
		if ((map[x][0] != '1') || (map[x][game_map.width - 1] != '1'))
			return (FALSE);
		x++;
	}
	return (TRUE);
}
