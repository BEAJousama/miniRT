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

int	get_pixel_color(t_elements *elem, t_cogo ray, double pixel_step, bool depth)
{
	int	color=0;
	// int	color_h;

	// ray.x -= (pixel_step) / 4;
	// ray.y += (pixel_step) / 4;
	if (depth)
	// 	color = get_pixel_color(elem, ray, pixel_step / 2, 0);
	// else
		color = check_intersection(elem, ray);
	ray.x += (pixel_step) / 2;
	// if (depth)
	// 	color_h = get_pixel_color(elem, ray, pixel_step, 0);
	// else
	// 	color_h = check_intersection(elem, ray);
	// color = mean_rgb(color, color_h);
	// ray.x -= (pixel_step) / 2;
	// ray.y -= (pixel_step) / 2;
	// if (depth)
	// 	color_h = get_pixel_color(elem, ray, pixel_step / 2, 0);
	// else
	// 	color_h = check_intersection(elem, ray);
	// color = mean_rgb(color, color_h);
	// ray.x += (pixel_step) / 2;
	// if (depth)
	// 	color_h = get_pixel_color(elem, ray, pixel_step, 0);
	// else
	// 	color_h = check_intersection(elem, ray);
	// color = mean_rgb(color, color_h);
	return (color);
}

void	fill_position_matrix(t_elements *elem)
{
	int	i;

	i = -1;
	t_cogo  o;
	t_cogo  null;
	null = (t_cogo){};
	elem->m_pos = get_transf_matrix(elem->c->orient, elem->c->pos);
    update_cogo(elem, elem->m_pos);
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
	{
		o = (t_cogo){};
		elem->cy[i].m_pos = get_transf_matrix(elem->cy[i].orient,\
		elem->cy[i].pos);
		update_cogo_element(&o, elem->cy[i].m_pos);
		add_sub_vectors_2d(&elem->cy[i].o_c, o, null, -1);
		elem->cy[i].z_o = o.z;
	}
}

void	init_ray(t_elements *elem, t_cogo *ray)
{
	ray->x = -tan((elem->c->fov / 2) * (M_PI / 180));
	ray->y = -ray->x;
	ray->z = 1;
}
void	fill_t_buf_i(t_buf_i *i, int endian)
{
	if (!endian)
	{
		i->i0 = 0;
		i->i1 = 1;
		i->i2 = 2;
		i->i3 = 3;
	}
	else
	{
		i->i0 = 3;
		i->i1 = 2;
		i->i2 = 1;
		i->i3 = 0;
	}
}

void	display(t_elements *elem, t_mlx_ptr *gfx)
{
    int		x; 
    int		y;
	int		color;
	t_cogo	ray;
	double	x_ray_hol;
	double	pixel_step;
	t_buf_i i;
	
    y = 0;
	i = (t_buf_i){};
	init_ray(elem, &ray);
	fill_position_matrix(elem);
	pixel_step = fabs(ray.x * 2) / 1000;
	x_ray_hol = ray.x;
	fill_t_buf_i(&i, gfx->endian);
	while (y++ < 1000)
	{
		x = 0;
		ray.x = x_ray_hol;
		while (x++ < 1000)
		{
			ray.x += pixel_step;
			color = get_pixel_color(elem, ray, pixel_step, 1);
 			gfx->buf[(y * gfx->l_bytes) + (x * 4) + i.i0] = (color) ;
 			gfx->buf[(y * gfx->l_bytes) + (x * 4) + i.i1] = (color >> 8);
 			gfx->buf[(y * gfx->l_bytes) + (x * 4) + i.i2] = (color >> 16);
 			gfx->buf[(y * gfx->l_bytes) + (x * 4) + i.i3] = (color >> 24);
		}
		ray.y = ray.y - pixel_step;
	}
	mlx_put_image_to_window(gfx->mlx, gfx->win, gfx->img, 0, 0);
}
