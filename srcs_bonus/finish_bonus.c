/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:32:12 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/11 00:45:38 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    enable_exit(t_game *game)
{
    if (game->map.box_to_collect == 0)
    {
        game->img.exit->instances[0].enabled = true;
        ft_printf("Você coletou todas boxes!\n");
        ft_printf("A saída foi habilitada.\n");
        game->exit_state = TRUE;
    }
}

void    finish_game(t_game *game)
{
    if (((game->map.personage.x == game->map.exit.x) && (game->map.personage.y == game->map.exit.y)
        && game->exit_state == TRUE))
    {
        mlx_close_window(game->mlx);
        ft_free_split(game->map.map);
    }
    else if (game->map.map[game->map.personage.x][game->map.personage.y] == 'V')
    {
        mlx_close_window(game->mlx);
        ft_free_split(game->map.map);
    }
}