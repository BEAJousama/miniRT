/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shadow_ray_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:11:34 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 16:11:48 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool	check_sh_ray_sp(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_sphere(elem, index);
	t_hol = sphere_intersection_sh(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

bool	check_sh_ray_pl(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_plane(elem, index);
	t_hol = plane_intersection(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

bool	check_sh_ray_cy(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_cylinder(elem, index);
	t_hol = cylinder_intersection_sh(elem, sh_ray, index);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}

bool	check_sh_ray_cy_disk(t_elements *elem, t_cogo sh_ray, size_t index)
{
	double	t_hol;
	double	epsilon;

	epsilon = epsilon_cy_disk(elem, index);
	t_hol = disk_cy_inter(elem, sh_ray, index, -1);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	t_hol = disk_cy_inter(elem, sh_ray, index, 1);
	if (t_hol > epsilon && t_hol < 1)
		return (0);
	return (1);
}
