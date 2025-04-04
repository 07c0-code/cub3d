/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:10:40 by samartin          #+#    #+#             */
/*   Updated: 2025/03/24 13:40:46 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_MAP_H
# define NEW_MAP_H

uint8_t	c3d_read_header(int fd, t_map *map, t_mlx *mlx);
uint8_t	c3d_read_map(int fd, t_map *map);
uint8_t	c3d_validate_map(t_map *map);

//Matrix utils
uint8_t	c3d_matrix_health_3(char **matrix);
uint8_t	c3d_clear_header(char **header);
void	c3d_cpynfill(char *dest, char *src, size_t full_l);
float	c3d_get_player_pos(char **map, size_t w, size_t h, float *player_pos);

#endif