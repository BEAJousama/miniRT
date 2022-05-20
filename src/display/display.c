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

void	update_cogo_element(t_cogo *pos, t_cogo camera_pos)
{
	pos->x -= camera_pos.x;
	pos->y -= camera_pos.y;
	pos->z -= camera_pos.z;
}

void	move_origin_to_camera(t_elements *elem)
{
	update_cogo_element(&(elem->l->pos), elem->c->pos);
	update_cogo_element(&(elem->sp->pos), elem->c->pos);
	// update_cogo_element(&(eem->pl->pos), elem->c->pos);
	// update_cogo_element(&(elem->cy->pos), elem->c->pos);
	elem->c->pos.x = 0;
	elem->c->pos.y = 0;
	elem->c->pos.z = 0;
}

double	dot(t_cogo	v_one, t_cogo v_two)
{
	return ((v_one.x * v_two.x) + (v_one.y * v_two.y) +(v_one.z * v_two.z));
}

void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, double signe)
{
	v_res->x = v_one.x + (signe * v_two.x);
	v_res->y = v_one.y + (signe * v_two.y);
	v_res->z = v_one.z + (signe * v_two.z);
}

bool	sphere_intersection(t_elements *elem, t_cogo ray)
{
	double	delta;
	t_cogo	p_c;

	add_sub_vectors(&p_c, elem->c->pos, elem->sp->pos, -1);
	delta = pow(dot(ray, p_c), 2) - (4 * dot(ray, ray) * (dot(p_c, p_c) - pow(elem->sp->diameter / 2, 2)));

	if (delta < 0)
		return (0);
	else
		return (1);
}

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