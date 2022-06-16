/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:05 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 15:46:05 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_info(double t_hol, t_close *info, int i, char obj)
{
	if ((t_hol < info->t && t_hol > 0) || (!info->t && t_hol > 0))
	{
		info->t = t_hol;
		info->i = i;
		info->object = obj;
	}
}

t_rgb	extract_color(t_close *info, t_elements *elem, t_cogo o)
{
	t_cogo	sh_ray;

	sh_ray = (t_cogo){};
	if (elem->elem_nbr.l_nbr)
		add_sub_vectors(&sh_ray, elem->l->pos, o, -1);
	if (info->object == 's')
		return (sphere_shading(elem, info, sh_ray, o));
	if (info->object == 'p')
		return (plane_shading(elem, info, sh_ray, o));
	if (info->object == 'c')
		return (cylinder_shading(elem, info, sh_ray, o));
	if (info->object == 'd')
		return (disk_cy_shading(elem, info, sh_ray, o));
	return ((t_rgb){});
}

t_rgb	check_intersection(t_elements *elem, t_cogo ray)
{
	int				i;
	t_cogo			o;
	t_close	info;

	i = -1;
	info = (t_close){};
	o = elem->c->pos;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		fill_info(sphere_intersection(elem, ray, (size_t)i, o), &info, i, 's');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		fill_info(plane_intersection(elem, ray, (size_t)i, o), &info, i, 'p');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		fill_info(cylinder_intersection(elem, ray, (size_t)i), &info, i, 'c');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
	{
		fill_info(disk_cy_inter(elem, ray, (size_t)i, -1, o), &info, i, 'd');
		fill_info(disk_cy_inter(elem, ray, (size_t)i, 1, o), &info, i, 'd');
	}
	scaler_multiplication(&o, ray, info.t);
	return (extract_color(&info, elem, o));
}
