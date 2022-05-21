/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/17 15:15:21 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_intersection(t_elements *elem ,t_cogo ray)
{
	if (sphere_intersection(elem, ray))
		return (elem->sp->rgb);
	return (0);
}

void    display(t_elements *elem, t_mlx_ptr *gfx)
{
    int x = 0;
    int y = 0;
	int	color;
	t_cogo	ray;
	double	x_ray_hol;
	double	pixel_step;

    (void)elem;
    gfx->mlx = mlx_init();
	gfx->win = mlx_new_window(gfx->mlx, 1000, 1000, NAME_W);
	move_origin_to_camera(elem);
	ray.x = -tan((elem->c->fov / 2) * (3.14 / 180));
	ray.y = -ray.x;
	ray.z = 1;
	pixel_step = fabs(ray.x * 2) / 500;
	x_ray_hol = ray.x;
	while (y < 1000)
	{
		x = 0;
		ray.x = x_ray_hol;
		while (x < 1000)
		{
			ray.x += pixel_step;
			color = check_intersection(elem, ray);
			mlx_pixel_put (gfx->mlx , gfx->win, x, y, color);
			x++;
		}
		ray.y -= pixel_step;
		y++;
	}
}