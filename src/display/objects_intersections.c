/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:05 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/23 12:44:06 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	fill_info_obj(double t_hol, t_close_inter *info, int i, char obj)
{
	if ((t_hol < info->t && t_hol > 0) || (!info->t && t_hol > 0))
	{
		info->t = t_hol;
		info->i = i;
		info->object = obj;
	}
}

int	extract_color(t_close_inter *info, t_elements *elem, t_cogo ray)
{
	t_cogo	sh_ray;
	(void)ray;

	add_sub_vectors(&sh_ray, elem->l->pos, elem->origin, -1);
	if (info->object == 's')
        return (sphere_shading(elem, info, sh_ray));
	if (info->object == 'p')
        return (plane_shading(elem, info, sh_ray));
	if (info->object == 'c')
		return (cylinder_shading(elem, info, sh_ray));
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
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
		fill_info_obj(plane_intersection(elem, ray, (size_t)i), &info, i, 'p');
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
		fill_info_obj(cylinder_intersection(elem, ray, (size_t)i, 0), &info, i, 'p');
	scaler_multiplication(&elem->origin, ray, info.t);
	return (extract_color(&info, elem, ray));
}