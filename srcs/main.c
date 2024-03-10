/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:12 by cshingai          #+#    #+#             */
/*   Updated: 2024/03/10 19:02:31 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

mlx_texture_t	*negocio_a_ser_printado(char *c)
{
	mlx_texture_t	*texture;

	texture = 0;
	if (ft_strncmp(c, "1", 1) == 0)
		texture = mlx_load_png("./imgs/rocha.png");
	else if (ft_strncmp(c, "P", 1) == 0)
		texture = mlx_load_png("./imgs/cursor.png");
	else if (ft_strncmp(c, "C", 1) == 0)
		texture = mlx_load_png("./imgs/money.png");
	return (texture);
}

int32_t	main(int argc, char *argv[])
{
	primary_validation(argc, argv[1]);
	start(argv[1]);
}
