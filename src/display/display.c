/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/11 09:38:50 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	display(t_elements *elem, t_mlx_ptr *gfx)
{
	int		x;
	int		y;
	t_cogo	ray;
	double	p_stp;
	double	x_ray_hol;

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
		ray.y -= p_stp;
	}
}
