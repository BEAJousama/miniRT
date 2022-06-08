/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_shading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:49 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/03 11:57:28 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo  p_c;
	int     rgb_h;

	rgb_h = 0;
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

int plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	int     rgb_h;

	rgb_h = 0;
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

int cylinder_shadingg(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	t_cogo  p_c;
	t_cogo  origin;
	t_cogo  pos_cy;
	int     rgb_h;

	rgb_h = 0;
	origin = elem->origin;
	pos_cy = (t_cogo){};
	if (elem->a)
		rgb_h = multi_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio);
	if (elem->elem_nbr.l_nbr && check_shadow_ray(elem, sh_ray))
	{
		update_orient_element(&sh_ray, elem->cy[info->i].m_pos);
		p_c = elem->cy[info->i].o_c;
		resize_vec(&p_c, p_c, 1);
		resize_vec(&sh_ray, sh_ray, 1);
		rgb_h = add_rgb(multi_rgb(elem->cy[info->i].rgb, elem->l->rgb, \
		(fabs(dot(sh_ray, p_c))) * elem->l->bright), rgb_h);
		return (rgb_h);
	}
	return (rgb_h);
}

int disk_cy_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
	int     rgb_h;

	rgb_h = 0;
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

