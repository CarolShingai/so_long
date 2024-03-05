/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/05 02:03:00 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*create_img(mlx_t *mlx, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(img_path);
	if (!texture)
		ft_error(TEXTURE_ERROR);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error(IMAGE_ERROR);
	mlx_delete_texture(texture);
	return (img);
}

void	insert_img(t_game game)
{
	game.img.floor = create_img(game.mlx, "./sprites/grass_tile.png");
	game.img.wall = create_img(game.mlx, "./sprites/block_tile.png");
}