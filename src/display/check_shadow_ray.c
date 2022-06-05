/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:12:22 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/05 19:12:24 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_sh_ray_sp(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double  t_hol;
	double	epsilon;

    epsilon = epsilon_sphere(elem, index);
	t_hol = sphere_inter(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
    return (1);
}

bool	check_sh_ray_pl(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double  t_hol;
	double	epsilon;

    epsilon = epsilon_plane(elem, index);
	t_hol = plane_intersection(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
    return (1);
}

bool	check_sh_ray_cy(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double  t_hol;
	double	epsilon;

    epsilon = epsilon_cylinder(elem, index);
	t_hol = cy_test_sh(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

bool	check_shadow_ray(t_elements *elem, t_cogo sh_ray)
{
	int i;

	i = -1;
	while ((size_t)++i < elem->elem_nbr.sp_nbr)
        if (!check_sh_ray_sp(elem, sh_ray, (size_t)i))
            return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.pl_nbr)
        if (!check_sh_ray_pl(elem, sh_ray, (size_t)i))
            return (0);
	i = -1;
	while ((size_t)++i < elem->elem_nbr.cy_nbr)
        if (!check_sh_ray_cy(elem, sh_ray, (size_t)i))
            return (0);
	return (1);
}

