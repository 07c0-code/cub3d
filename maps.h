/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:46:18 by samartin          #+#    #+#             */
/*   Updated: 2024/08/19 14:32:16 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H
# include "libft/include/libft.h"
# ifndef WINW
#  define WINW 1280
# endif
# ifndef WINH
#  define WINH 720
# endif
# ifndef TEXW
#  define TEXW 128
# endif
# ifndef TEXH
#  define TEXH 128
# endif
# ifndef BPP
#  define BPP sizeof(int32_t)
# endif

/**
 * The map structure contains all the data loaded from the map .cub file.
 * @var map_size Width ([0]) and Height ([1]) of the rectangular region to be
 *  loaded.
 * @var floor_color RGBA quad in a single int, for floor visual region.
 * @var ceil_color RGBA quad in a single int, for ceiling visual region.
 * @var txtr_lst List of lists, each second dimmension contanins a single node
 *  with an MLX texture or more if they are for animation. The fixed
 *  order is: North Wall, East Wall, South Wall, West Wall, Sprites.
 * @var map_matrix char 2D matrix containing 0 for walkable, 1 for wall,
 *  N-S-E-W for player pressence and orientation, whitespace for outer,
 *  non-walkable empty space.
 */
typedef	struct s_map
{
	size_t	map_size[2];
	int32_t	floor_color;
	int32_t	ceil_color;
	t_list	*txtr_lst;
	char	**map_matrix;
}	t_map;

#endif