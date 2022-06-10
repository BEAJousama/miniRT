/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:05 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/03 11:58:24 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_info(double t_hol, t_close_inter *info, int i, char obj)
{
	if ((t_hol < info->t && t_hol > 0) || (!info->t && t_hol > 0))
	{
		info->t = t_hol;
		info->i = i;
		info->object = obj;
	}
}

int	extract_color(t_close_inter *info, t_elements *elem)
{
	t_cogo	sh_ray;

	if (elem->elem_nbr.l_nbr)
		add_sub_vectors(&sh_ray, elem->l->pos, elem->origin, -1);
	if (info->object == 's')
		return (sphere_shading(elem, info, sh_ray));
	if (info->object == 'p')
		return (plane_shading(elem, info, sh_ray));
	if (info->object == 'c')
		return (cylinder_shading(elem, info, sh_ray));
	if (info->object == 'd')
		return (disk_cy_shading(elem, info, sh_ray));
	return (0);
}

int	check_intersection(t_elements *elem, t_cogo ray)
{
	int				i;
	t_close_inter	info;

	i = -1;
	info = (t_close_inter){};
	elem->origin = elem->c->pos;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
		fill_info(sphere_intersection(elem, ray, (size_t)i), &info, i, 's');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		fill_info(plane_intersection(elem, ray, (size_t)i), &info, i, 'p');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		fill_info(cylinder_intersection(elem, ray, (size_t)i), &info, i, 'c');
	i = -1;
	if (info.object != 'c')
	{
		while ((size_t)++i < elem->elem_nbr.cy_nbr)
		{
			fill_info(disk_cy_inter(elem, ray, (size_t)i, -1), &info, i, 'd');
			fill_info(disk_cy_inter(elem, ray, (size_t)i, 1), &info, i, 'd');
		}
	}
	scaler_multiplication(&elem->origin, ray, info.t);
	return (extract_color(&info, elem));
}
