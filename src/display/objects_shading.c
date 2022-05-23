/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_inters_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:44:49 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/23 12:44:50 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_sh_ray(t_elements *elem, t_cogo sh_ray)
{
	int     i;
    double  t_hol;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
    {
		t_hol = sphere_intersection(elem, sh_ray, (size_t)i);
        if (t_hol > 0.001 && t_hol < 1)
            return (0);
    }
    i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
    {
		t_hol = plane_intersection(elem, sh_ray, (size_t)i);
        if (t_hol > 0 && t_hol < 1)
            return (0);
    }
	return (1);
}

int sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    t_cogo  p_c;

    if (check_sh_ray(elem, sh_ray))
    {
		resize_vec(&sh_ray, sh_ray, 1);
        add_sub_vectors(&p_c, elem->origin, elem->sp[info->i].pos, -1);
        resize_vec(&p_c, p_c, 1);
        return (calculate_rgb(0, elem->sp[info->i].rgb , fabs(dot(sh_ray, p_c))));
        // return (elem->sp[info->i].rgb);
    }
    return (0);
}

int plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    // t_cogo  p_c;

    if (check_sh_ray(elem, sh_ray))
    {
        resize_vec(&sh_ray, sh_ray, 1);
        resize_vec(&elem->pl->orient, elem->pl->orient, 1);
		return (calculate_rgb(0, elem->pl[info->i].rgb , fabs(dot(sh_ray, elem->pl->orient))));
    }
	return (0);
}

int cylinder_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    if (check_sh_ray(elem, sh_ray))
		return (elem->cy[info->i].rgb);
	return (calculate_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio));
}
