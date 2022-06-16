/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_cy_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:57:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 14:35:51 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	disk_cy_inter(t_elements *elem, t_cogo ray, size_t index, int signe, t_cogo o)
{
	t_cogo	disk;
	t_cogo	c_p;
	double	t;

	disk = (t_cogo){};
	disk.z = signe * elem->cy[index].height / 2;
	update_orient_element(&ray, elem->cy[index].m_pos);
	update_cogo_element(&o, elem->cy[index].m_pos);
	add_sub_vectors(&c_p, disk, o, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + o.x, 2) + pow((t * ray.y) + o.y, 2) \
			< pow(elem->cy[index].diameter / 2, 2))
		return (t);
	return (-1);
}

double	disk_co_inter(t_elements *elem, t_cogo ray, size_t index, t_cogo o)
{
	t_cogo	disk;
	t_cogo	c_p;
	double	t;

	disk = (t_cogo){};
	disk.z = elem->co[index].hgt;
	update_orient_element(&ray, elem->co[index].m_pos);
	update_cogo_element(&o, elem->co[index].m_pos);
	add_sub_vectors(&c_p, disk, o, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + o.x, 2) + pow((t * ray.y) + o.y, 2) \
			< pow(elem->co[index].base / 2, 2))
		return (t);
	return (-1);
}
