/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:31:39 by bvelasco          #+#    #+#             */
/*   Updated: 2024/12/17 17:10:31 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

static void	move_player(t_player *player)
{
	if (!detect_colision((player->coords[1]
				+ player->xmov * VEL * cosf(player->aov + M_PI_2))
			, (player->coords[0] + player->xmov * VEL
				* sinf(player->aov + M_PI_2)), &player->map))
	{
		player->coords[0] += player->xmov * VEL * sinf(player->aov + M_PI_2);
		player->coords[1] += player->xmov * VEL * cosf(player->aov + M_PI_2);
	}
	if (!detect_colision((player->coords[1]
				+ player->ymov * VEL * cosf(player->aov + M_PI))
			, (player->coords[0] + player->ymov * VEL
				* sinf(player->aov + M_PI)), &player->map))
	{
		player->coords[0] += player->ymov * VEL * sinf(player->aov + M_PI);
		player->coords[1] += player->ymov * VEL * cosf(player->aov + M_PI);
	}
	player->aov += (player->rotate * (M_PI / 180)) * VEL * 20;
	return ;
}

void	drawline(void *c3d, int j, float k)
{
	const t_cub3d	*cub3d = c3d;
	float			h;
	int				i;
	int				l;
	int				h_2;

	i = 0;
	h = roundf(WINH / k);
	while (i < WINH / 2)
	{
		ft_image_pixel_put(cub3d->mlxgraph.scrnbuff, j, i, 0x87CEEB);
		i++;
	}
	while (i < WINH)
	{
		ft_image_pixel_put(cub3d->mlxgraph.scrnbuff, j, i, 0xA0522D);
		i++;
	}
	l = -h / 2;
	h_2 = h / 2;
	while (l < h_2)
	{
		ft_image_pixel_put(cub3d->mlxgraph.scrnbuff, j, WINH / 2 + l, 0x808080);
		l++;
	}
}

void	main_visualization(t_cub3d *c3d)
{
	if (c3d->player.rotmod == 1)
		mlx_mouse_move(c3d->mlxgraph.mlx, c3d->mlxgraph.win,
			WINW / 2, WINH / 2);
	mlx_put_image_to_window(c3d->mlxgraph.mlx, c3d->mlxgraph.win,
		c3d->mlxgraph.scrnbuff->img, 0, 0);
	mlx_put_image_to_window(c3d->mlxgraph.mlx, c3d->mlxgraph.win,
		c3d->mlxgraph.minimap->texture->img, 0, 0);
}

int	main_loop(void *c3d)
{
	t_cub3d		*cub3d;
	float		i;
	int			j;
	float		k;
	float		pixel_angle;

	cub3d = c3d;
	move_player(&cub3d->player);
	j = 0;
	i = -(FOV) / 2;
	pixel_angle = FOV / WINW;
	print_minimap(&cub3d->player.map, cub3d->mlxgraph.minimap);
	while (j < WINW)
	{
		k = launch_ray(&cub3d->player, cub3d->player.aov - (i * (M_PI / 180)),
				cub3d->mlxgraph.minimap);
		i += pixel_angle;
		drawline(c3d, j, k);
		j++;
	}
	main_visualization(cub3d);
	return (0);
}
