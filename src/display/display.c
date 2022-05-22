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

void	fill_info_obj(double t_hol, t_close_inter *info, int i, char obj)
{
	if ((t_hol < info->t && t_hol > 0) || (!info->t && t_hol > 0))
	{
		info->t = t_hol;
		info->index = i;
		info->object = obj;
	}
}

bool	check_sh_ray(t_elements *elem, t_cogo sh_ray)
{
	int	i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		if (sphere_inter(elem, sh_ray, (size_t)i) > 0)
			return (0);
	// while ((size_t)++i < elem->elem_nbr.sp_nbr)
	// 	if (plane_intersection(elem, sh_ray, (size_t)i))
	// 		return (0);
	return (1);
}

int	extract_color(t_close_inter *info, t_elements *elem)
{
	t_cogo	sh_ray;

	add_sub_vectors(&sh_ray, elem->l->pos, elem->origin, -1);
	if (info->object == 's')
	{
		if (check_sh_ray(elem, sh_ray))
			return (elem->sp[info->index].rgb);
		return (454544);
	}
	if (info->object == 'p')
		return (elem->pl[info->index].rgb);
	if (info->object == 'c')
		return (elem->cy[info->index].rgb);
	return (0);
}

int	check_intersection(t_elements *elem ,t_cogo ray)
{
	int				i;
	t_close_inter	info;

	i = -1;
	info = (t_close_inter){};
	elem->origin = elem->c->pos;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		fill_info_obj(sphere_intersection(elem, ray, (size_t)i), &info, i, 's');
	i = -1;
	// while ((size_t)++i < elem->elem_nbr.pl_nbr)
	// 	fill_info_obj(plane_intersection(elem, ray, (size_t)i), &info, i, 'p');
	elem->origin = ray;
	scaler_multiplication(&elem->origin, info.t);
	elem->origin.y *= 1.0001;
	elem->origin.x *= 1.0001;
	return (extract_color(&info, elem));
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
	ray.x = -tan((elem->c->fov / 2) * (M_PI / 180));
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
			color = check_intersection(elem, ray);
			mlx_pixel_put (gfx->mlx , gfx->win, x, y, color);
			x++;
		}
		ray.y = ray.y - pixel_step;
		y++;
	}
}