/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:51:01 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/18 18:25:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_image_t *create_img(mlx_t*	mlx, char *img_path)
{
  mlx_texture_t*	texture;
  mlx_image_t*  img;

  texture = mlx_load_png(img_path);
  if(!texture)
		ft_error();
	img = mlx_texture_to_image(mlx, texture);
	if(!img)
		ft_error();
  mlx_delete_texture(texture);
  return(img);
}