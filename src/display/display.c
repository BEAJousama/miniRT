/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 14:45:58 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_color_buffer(t_mlx_ptr *gfx, int color, int x, int y)
{
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i0] = (color);
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i1] = (color >> 8);
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i2] = (color >> 16);
	gfx->buf[(y * gfx->l_bytes) + (x * 4) + gfx->i.i3] = (color >> 24);
}

void	display(t_elements *elem, t_mlx_ptr *gfx)
{
	int		x;
	int		y;
	t_cogo	ray;
	double	x_ray_hol;
	double	p_stp;

	y = -1;
	init_ray(elem, &ray);
	fill_position_matrix(elem);
	fill_t_buf_i(&gfx->i, gfx->endn);
	p_stp = fabs(ray.x * 2) / 1000;
	x_ray_hol = ray.x;
	while (++y < 1000)
	{
		x = -1;
		ray.x = x_ray_hol;
		while (++x < 1000)
		{
			ray.x += p_stp;
			fill_color_buffer(gfx, get_pixel_color(elem, ray, p_stp, 1), x, y);
		}
		ray.y = ray.y - p_stp;
	}
}
