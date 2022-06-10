/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_shading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:49 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 11:06:47 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_rgb	sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo	p_c;
	t_rgb	rgb_h;

	rgb_h = (t_rgb){};
	if (elem->a)
		rgb_h = multi_rgb(elem->sp[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		resize_vec(&sh_ray, sh_ray, 1);
		add_sub_vectors(&p_c, elem->origin, elem->sp[info->i].pos, -1);
		resize_vec(&p_c, p_c, 1);
		rgb_h = add_rgb(multi_rgb(elem->sp[info->i].rgb, elem->l->rgb, \
					fabs(dot(sh_ray, p_c) * elem->l->bright)), rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_rgb	rgb_h;

	rgb_h = (t_rgb){};
	if (elem->a)
		rgb_h = multi_rgb(elem->pl[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		resize_vec(&sh_ray, sh_ray, 1);
		resize_vec(&elem->pl[info->i].orient, elem->pl[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->pl[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_ray, elem->pl[info->i].orient)) * elem->l->bright), rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	cylinder_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo	p_c;
	t_rgb	rgb_h;
	t_cogo	origin;
	t_cogo	pos_cy;

	p_c = (t_cogo){};
	rgb_h = (t_rgb){};
	pos_cy = (t_cogo){};
	origin = elem->origin;
	if (elem->a)
		rgb_h = multi_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		update_cogo_element(&origin, elem->cy[info->i].m_pos);
		update_orient_element(&sh_ray, elem->cy[info->i].m_pos);
		add_sub_vectors_2d(&p_c, origin, pos_cy, -1);
		resize_vec_2d(&p_c, p_c, 1);
		resize_vec_2d(&sh_ray, sh_ray, 1);
		rgb_h = add_rgb(multi_rgb(elem->cy[info->i].rgb, elem->l->rgb, \
					(fabs(dot_2d(sh_ray, p_c))) * elem->l->bright), rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

t_rgb	disk_cy_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_rgb	rgb_h;

	rgb_h = (t_rgb){};
	if (elem->a)
		rgb_h = multi_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		resize_vec(&sh_ray, sh_ray, 1);
		resize_vec(&elem->cy[info->i].orient, elem->cy[info->i].orient, 1);
		rgb_h = add_rgb(multi_rgb(elem->cy[info->i].rgb, elem->l->rgb, \
		fabs(dot(sh_ray, elem->cy[info->i].orient)) * elem->l->bright), rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}
