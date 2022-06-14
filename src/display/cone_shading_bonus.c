/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_shading_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:34:41 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 14:33:54 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


double	epsilon_cone(t_elements *elem, size_t index)
{
	t_cogo	o_c;
	t_cogo	o;

	o = elem->co[index].orient;
    add_sub_vectors(&o_c, elem->c->pos, elem->co[index].pos, -1);
    resize_vec(&o_c, o_c, 1);
    resize_vec(&o, o, 1);
	if (dot(o_c, o) < cos(atan((elem->co[index].base / 2) / elem->co[index].hgt)))
		return (0.00001);
	return (-0.00001);
}

bool	check_sh_ray_co(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_cone(elem, index);
	t_hol = cone_intersection_sh(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

t_rgb	cone_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo	o;
	t_cogo	n;
	t_cogo	wo;
	t_cogo	p_c;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->co[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		add_sub_vectors(&p_c, elem->origin, elem->co[info->i].pos, -1);
		resize_vec(&p_c, p_c, 1);
		resize_vec(&o, elem->co[info->i].orient, 1);

		scaler_multiplication(&p_c, p_c, dot(o, p_c));
		add_sub_vectors(&n, p_c, o, -1);
		resize_vec(&n, n, 1);
		resize_vec(&sh_ray, sh_ray, 1);
		rgb_h = add_rgb(multi_rgb(elem->co[info->i].rgb, elem->l->rgb, \
					(fabs(dot(sh_ray, n))) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, elem->origin, -1);
		rgb_s = add_specular_light(elem, sh_ray, n, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	disk_co_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo	wo;
	t_rgb	rgb_h;
	t_rgb	rgb_s;

	rgb_h = (t_rgb){};
	if (elem->a && !elem->a->single)
		rgb_h = multi_rgb(elem->co[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		resize_vec(&sh_ray, sh_ray, 1);
		resize_vec(&elem->co[info->i].orient, elem->co[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->co[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_ray, elem->co[info->i].orient)) * elem->l->bright), rgb_h);
		add_sub_vectors(&wo, elem->c->pos, elem->origin, -1);
		rgb_s = add_specular_light(elem, sh_ray, elem->co[info->i].orient, wo);
		rgb_h = add_rgb(rgb_s, rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

double	epsilon_co_disk(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->origin, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->origin, -1);
	if ((dot(c_c, elem->co[index].orient) * \
				dot(l_c, elem->co[index].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}


bool	check_sh_ray_co_disk(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_co_disk(elem, index);
	t_hol = disk_co_inter(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}