/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:15:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 10:28:17 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	check_intersection(t_elements *elem ,t_cogo ray, int i)
{
	if (sphere_intersection(elem, ray))
		return (elem->sp->rgb);
	if(plane_intersection(elem, ray) && i >= 500)
		return (elem->pl->rgb);
	return ((176 << 16) | (224 << 8) | 230);
}

void	display(t_elements *elem, t_mlx_ptr *gfx)
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
	ray.x = -tan((elem->c->fov / 2) * (3.14 / 180)) ;
	ray.y = -ray.x;
	ray.z = 1;
	pixel_step = fabs(ray.x * 2) / 1000;
	x_ray_hol = ray.x;
	while (y < 1000)
	{
		x = 0;
		ray.x = x_ray_hol;
		while (x < 1000)
		{
			ray.x += pixel_step;
			color = check_intersection(elem, ray, y);
			mlx_pixel_put (gfx->mlx , gfx->win, x, y, color);
			x++;
		}
		ray.y -= pixel_step;
		y++;
	}
}
