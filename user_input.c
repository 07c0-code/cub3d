/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:35:07 by bvelasco          #+#    #+#             */
/*   Updated: 2024/12/17 17:01:31 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

static void	rotswitch(t_cub3d *c3d)
{
	{
		if (c3d->player.rotmod == 1)
		{
			c3d->player.rotmod = 0;
			c3d->player.rotate = 0;
			mlx_mouse_show(c3d->mlxgraph.mlx, c3d->mlxgraph.win);
		}
		else
		{
			c3d->player.rotmod = 1;
			c3d->player.rotate = 0;
			mlx_mouse_hide(c3d->mlxgraph.mlx, c3d->mlxgraph.win);
		}
	}
}

int	keyspressed(int keycode, void *param)
{
	t_cub3d	*c3d;

	c3d = param;
	if (keycode == 65361 && c3d->player.rotmod == 0)
		c3d->player.rotate = +1;
	if (keycode == 65363 && c3d->player.rotmod == 0)
		c3d->player.rotate = -1;
	if (keycode == 100)
		c3d->player.xmov = -1;
	if (keycode == 97)
		c3d->player.xmov = 1;
	if (keycode == 115)
		c3d->player.ymov = 1;
	if (keycode == 119)
		c3d->player.ymov = -1;
	if (keycode == 32)
		rotswitch(c3d);
	return (0);
}

int	unmove(int keycode, void *param)
{
	t_player	*player;

	player = param;
	if (keycode == 65361)
		player->rotate = 0;
	if (keycode == 65363)
		player->rotate = 0;
	if (keycode == 100)
		player->xmov = 0;
	if (keycode == 97)
		player->xmov = 0;
	if (keycode == 115)
		player->ymov = 0;
	if (keycode == 119 && player->ymov < 0)
		player->ymov = 0;
	return (0);
}

int	mouserot(int x, int y, void *param)
{
	t_player	*player;

	(void)y;
	player = param;
	if (player->rotmod == 0)
		return (1);
	if (x < WINW / 2)
		player->rotate = 1;
	else if (x == WINW / 2)
		player->rotate = 0;
	else
		player->rotate = -1;
	return (0);
}
