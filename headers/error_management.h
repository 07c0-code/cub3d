/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samartin <samartin@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:28:10 by samartin          #+#    #+#             */
/*   Updated: 2024/11/20 15:35:27 by samartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

int8_t	c3d_errors(int8_t code);
void	c3d_fatal_errors(int8_t code);
void	c3d_close_n_exit(t_mlx *mlx, int8_t code);

#endif