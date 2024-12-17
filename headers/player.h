/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:18:26 by samartin          #+#    #+#             */
/*   Updated: 2024/12/17 17:12:58 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# ifndef FOV
#  define FOV 60.0f
# endif
# ifndef VEL
#  define VEL 0.1f
# endif

/**
 * Type Player: Contains all the needed values to execute movement in a grid and
 *  raycasting representation. It is used along with the constant `FOV` (field
 *  of view).
 * @var map: t_map struct containing horizontal and vertical size, two colors
 *  for ceiling and floor and a 2D matrix with the scenario distribution.
 * @var coords: An array of 2 floats representing the X and Y position of the
 *  player on the map.
 * @var aov: Angle of View, a single float containing an angle in degrees
 *  representing the camera orientation relative to the zero point (North).
 *  
*/
typedef struct s_player
{
	t_map	map;
	float	coords[2];
	float	aov;
	int		xmov;
	int		ymov;
	int		rotate;
	int		rotmod;
}				t_player;

float		launch_ray(t_player *player, float angle, t_minimap *minimap);
int			keyspressed(int keycode, void *param);
int			unmove(int keycode, void *param);
int			mouserot(int x, int y, void *param);
int			main_loop(void *c3d);
int			detect_colision(float y, float x, t_map *map);
t_player	init_player(int fd, void *mlxptr);

#endif
