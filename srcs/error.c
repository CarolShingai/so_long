/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 03:35:17 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/22 19:23:41 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}

int	error(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	ft_free_split(game->map.map);
	exit(EXIT_FAILURE);
}

void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
