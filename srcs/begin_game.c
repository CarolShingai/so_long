/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:12 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/19 04:06:35 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }
//pegar uma variavél, ver se o número corresponde a 1
// tentar fazer isso funcionar
mlx_texture_t	*negocio_a_ser_printado(char *c)
{
	mlx_texture_t*	texture;

	texture = 0;
	if (ft_strncmp(c, "1", 1) == 0)
		texture = mlx_load_png("./imgs/rocha.png");
	else if (ft_strncmp(c, "P", 1) == 0)
		texture = mlx_load_png("./imgs/cursor.png");
	else if (ft_strncmp(c, "C", 1) == 0)
		texture = mlx_load_png("./imgs/money.png");
	return(texture);
}

int32_t	main(int argc, char *argv[])
{
		primary_validation(argc, argv[1]);
}		