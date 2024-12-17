/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:28:43 by samartin          #+#    #+#             */
/*   Updated: 2024/12/11 16:26:51 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/graphics.h"

float	set_column_pixel(t_texture buffer, t_texture_column tcol, int *offsets,
	float vp)
{
	offsets[1] = (offsets[2] \
		+ (tcol.texture->wd * (int)(vp * (float)(tcol.texture->ht - 1))));
	*(buffer.addr + (offsets[0])) = *(int *)(tcol.texture->addr + (offsets[1]));
	return (1.0F / (float)offsets[3]);
}

/**
 * Renders a column from a texture onto a buffer with specified colors for
 * ceiling and floor.
 * 
 * @param buffer The screen buffer where the single-pixel-width column will be
 *  printed. It contains the width and height coinciding with the screen size,
 *  and address of the pixel map.
 * @param tcol A structure of type `t_texture_column` used to pass several
 *  variables related to the function operation as a single parameter. It
 *  includes the number of the ray (the horizontal position where to put the
 *  column in the screen buffer), the texture of the wall, the horizontal point
 *  of the wall where the ray hit, and the ceiling an floor colors.
 * @param size The height in pixels of the wall part for the column that is
 *  being rendered on the screen. It can be greater than the window height
 *  itself, so in that case, the texture part will be printed starting in a
 *  middle point instead from the upper top.
 * @var y: Vertical iterator.
 * @var offsets: An array of 4 pointer offsets. [0]: The buffer total offset
 *  where to write each pixel. [1]: The texture total offset to read a pixel
 *  from. [2]: the horizontal component of the previous one, to calculate it
 *  at the begining of the function and avoid having to do it for each pixel.
 *  [3]: the size param to be able to pass it to the auxiliar function.
 */
void	print_column(t_texture buffer, t_texture_column tcol, int size)
{
	int		y;
	int		offsets[4];
	float	vpoint;

	if (size > buffer.ht)
		vpoint = (1.0F - ((float)buffer.ht / (float)size)) * 0.5F;
	else
		vpoint = 0;
	offsets[2] = (int)(round(tcol.wall_point * (tcol.texture->wd)));
	offsets[3] = size;
	y = 0;
	while (y < buffer.ht)
	{
		offsets[0] = (tcol.ray) + (buffer.wd * y);
		if (y < ((buffer.ht - size) / 2))
			*(int *)(buffer.addr + offsets[0]) = tcol.ceil_color;
		else if (y > (size + ((buffer.ht - size) / 2)))
			*(int *)(buffer.addr + offsets[0]) = tcol.floor_color;
		else
			vpoint += set_column_pixel(buffer, tcol, offsets, vpoint);
		y++;
	}
}
