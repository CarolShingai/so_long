/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:23:19 by cshingai          #+#    #+#             */
/*   Updated: 2024/02/21 03:46:12 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/src/ft_printf.h"

# define WIDTH 1024
# define HEIGHT 1024

mlx_image_t *create_img(mlx_t*	mlx, char *img_path);
void primary_validation(int argc, char *argv);
char **read_line(char *map_path);
void check_map(char **map);
int  check_map_chars(char *map, int idx_char);

#endif
