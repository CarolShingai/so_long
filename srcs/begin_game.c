/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:36:12 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/02 19:14:09 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
//pegar uma variavél, ver se o número corresponde a 1
// tentar fazer isso funcionar
mlx_texture_t	*negocio_a_ser_printado(char *c)
{
	mlx_texture_t*	texture;

	texture = 0;
	if (ft_strncmp(c, "1", 1) == 0)
		texture = mlx_load_png("./imgs/rocha.png");
	else if (ft_strncmp(c, "P", 1) == 0)
		texture = mlx_load_png("./imgs/foguete.png");
	else if (ft_strncmp(c, "C", 1) == 0)
		texture = mlx_load_png("./imgs/money.png");
	return(texture);
}

void	read_map(char map)
{
	char	*temp_buffer;
	char	*memory;
	int		fd;

	memory = read(fd, temp_buffer, BUFFER_SIZE);
	return(ft_split(memory, '\n'));
}

int32_t	main(void)
{
	mlx_t*	mlx;
	mlx_image_t*	img;
	mlx_texture_t*	t;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
	t = negocio_a_ser_printado("1");
	

	if(!t)
		ft_error();
	img = mlx_texture_to_image(mlx, t);
	if(!img)
		ft_error();
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	//carregar imagem
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	//encerrar programa
	mlx_delete_image(mlx, img);
	mlx_delete_texture(t);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
