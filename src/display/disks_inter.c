/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disks_inter.c               		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:57:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/14 14:35:51 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	disk_solution(t_cogo disk, t_cogo ray, t_cogo o, double d)
{
	double	t;
	t_cogo	c_p;

	add_sub_vectors(&c_p, disk, o, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + o.x, 2) + pow((t * ray.y) + o.y, 2) \
			< pow(d, 2))
		return (t);
	return (-2);
}

double	disk_cy_inter(t_elements *elem, t_cogo ray, int i, t_cogo o)
{
	t_cogo	disk;
	t_cogo	ref;
	double	t;
	double	t2;

	t = -1;
	disk = (t_cogo){};
	ref = elem->cy[i].orient;
	update_orient_element(&ref, elem->cy[i].m_pos);
	update_orient_element(&ray, elem->cy[i].m_pos);
	update_cogo_element(&o, elem->cy[i].m_pos);
	disk.z = -elem->cy[i].height / 2;
	t = disk_solution(disk, ray, o, elem->cy[i].diameter / 2);
	disk.z = elem->cy[i].height / 2;
	t2 = disk_solution(disk, ray, o, elem->cy[i].diameter / 2);
	if ((t2 < t && dot((t_cogo){0,0,1}, ref) <= 0) \
	|| (t2 > t && dot((t_cogo){0,0,1}, ref) >= 0))
		t = t2;
	return (t);
}

double	disk_cy_sh_inter(t_elements *elem, t_cogo ray, int i, t_cogo o)
{
	t_cogo	disk1;
	t_cogo	disk2;
	double	t;

	t = -1;
	disk2 = (t_cogo){0, 0, elem->cy[i].height / 2};
	disk1 = (t_cogo){0, 0, -elem->cy[i].height / 2};
	update_orient_element(&ray, elem->cy[i].m_pos);
	update_cogo_element(&o, elem->cy[i].m_pos);
	if (o.z >= disk1.z)
	{
		t = disk_solution(disk1, ray, o, elem->cy[i].diameter / 2);
		if (t < disk_solution(disk2, ray, o, elem->cy[i].diameter / 2))
			t = disk_solution(disk2, ray, o, elem->cy[i].diameter / 2);
	}
	if (o.z < disk2.z)
	{
		t = disk_solution(disk2, ray, o, elem->cy[i].diameter / 2);
		if (t < disk_solution(disk1, ray, o, elem->cy[i].diameter / 2))
			t = disk_solution(disk1, ray, o, elem->cy[i].diameter / 2);
	}
	return (t);
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
