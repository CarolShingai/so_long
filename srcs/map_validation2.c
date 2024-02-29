/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:52:51 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/29 19:53:31 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_itens(char **map, char item)
{
	int	count;
	int	idx_str;
	int	idx_char;

	count = 0;
	idx_str = -1;
	while (map[++idx_str])
	{
		idx_char = 0;
		while(map[idx_str][idx_char])
		{
			if (map[idx_str][idx_char] == item)
				count++;
			idx_char++;
		}
	}
	ft_printf("%d\n", count);
	return (count);
}

int	check_flood_fill(char **map)
{
	
}

// int fload_field(char **map)
