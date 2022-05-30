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

double  epsilon_sphere(t_elements *elem, int index)
{
    t_cogo	c_c;
	t_cogo	l_c;

    add_sub_vectors(&c_c, elem->c->pos, elem->sp[index].pos, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->sp[index].pos, -1);
    if ((mag_vector(c_c) < (elem->sp[index].diameter / 2) && mag_vector(l_c) > (elem->sp[index].diameter / 2))
    || (mag_vector(c_c) > (elem->sp[index].diameter / 2) && mag_vector(l_c) < (elem->sp[index].diameter / 2)))
			return (-0.00001);
    return (0.00001);
}

double  epsilon_plane(t_elements *elem)
{
    t_cogo	c_c;
	t_cogo	l_c;

    add_sub_vectors(&c_c, elem->c->pos, elem->origin, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->origin, -1);
    if ((dot(c_c, elem->pl->orient) * dot(l_c, elem->pl->orient)) >= 0)
        return (0.00001);
    return (-0.00001);
}


bool	check_sh_ray(t_elements *elem, t_cogo sh_ray)
{
	int     i;
    double  t_hol;
    double	epsilon;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
    {
		epsilon = epsilon_sphere(elem, i);
        t_hol = sphere_inter(elem, sh_ray, (size_t)i);
        if (t_hol > epsilon && t_hol < 1)
            return (0);
    }
    i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
    {
		epsilon = epsilon_plane(elem);
		t_hol = plane_intersection(elem, sh_ray, (size_t)i);
        if (t_hol > epsilon && t_hol < 1)
            return (0);
    }
	return (1);
}

int sphere_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    t_cogo  p_c;
    int     rgb_hol;

    if (check_sh_ray(elem, sh_ray))
    {
        resize_vec(&sh_ray, sh_ray, 1);
        add_sub_vectors(&p_c, elem->origin, elem->sp[info->i].pos, -1);
        resize_vec(&p_c, p_c, 1);
        rgb_hol = calculate_rgb(elem->l->rgb, elem->sp[info->i].rgb , fabs(dot(sh_ray, p_c)));
        rgb_hol = add_rgb(calculate_rgb(elem->a->rgb, elem->sp[info->i].rgb, elem->a->ratio), rgb_hol);
        return (rgb_hol);
        // return (elem->sp[info->i].rgb);
    }
    return (calculate_rgb(elem->a->rgb, elem->sp[info->i].rgb , elem->a->ratio));
}

int plane_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    // t_cogo  p_c;
    int     rgb_hol;

    if (check_sh_ray(elem, sh_ray))
    {
        resize_vec(&sh_ray, sh_ray, 1);
        resize_vec(&elem->pl->orient, elem->pl->orient, 1);
        rgb_hol = calculate_rgb(elem->l->rgb, elem->pl[info->i].rgb , fabs(dot(sh_ray, elem->pl->orient)));
        rgb_hol = add_rgb(calculate_rgb(elem->a->rgb, elem->pl[info->i].rgb, elem->a->ratio), rgb_hol);
		return (rgb_hol);
    }
	return (calculate_rgb(elem->a->rgb, elem->pl[info->i].rgb , elem->a->ratio));
}

int cylinder_shading(t_elements *elem, t_close_inter *info, t_cogo sh_ray)
{
    if (check_sh_ray(elem, sh_ray))
		return (elem->cy[info->i].rgb);
	return (calculate_rgb(elem->cy[info->i].rgb, elem->a->rgb, elem->a->ratio));
}
