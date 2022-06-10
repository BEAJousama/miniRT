/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_cy_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:57:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/10 07:41:18 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	disk_cy_inter(t_elements *elem, t_cogo ray, size_t index, int signe)
{
	t_cogo	origin;
	t_cogo	disk1;
	t_cogo	c_p;
	double	t;

	disk1 = (t_cogo){};
	disk1.z = signe * elem->cy[index].height / 2;
	origin = elem->origin;
	update_orient_element(&ray, elem->cy[index].m_pos);
	update_cogo_element(&origin, elem->cy[index].m_pos);
	add_sub_vectors(&c_p, disk1, origin, -1);
	if (ray.z)
		t = c_p.z / ray.z;
	else
		return (-1);
	if (pow((t * ray.x) + origin.x, 2) + pow((t * ray.y) + origin.y, 2) \
			< pow(elem->cy[index].diameter / 2, 2))
		return (t);
	return (-1);
}
