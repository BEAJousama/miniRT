/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:19:30 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/03 11:48:42 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


double	cylinder_intersection(t_elements *elem, t_cogo ray, size_t i)
{
	double	delta;
	double	t;

	t = 0;
    update_orient_element(&ray, elem->cy[i].m_pos);
	delta = pow(2 * dot_2d(ray, elem->cy[i].o_c), 2) - (4 * dot_2d(ray, ray)
		* (dot_2d(elem->cy[i].o_c, elem->cy[i].o_c) - \
		pow(elem->cy[i].diameter / 2, 2)));
	if (delta >= 0)
	{
		if (mag_vector_2d(elem->cy[i].o_c) >= (elem->cy[i].diameter / 2))
		{
			// printf("%.5f\n", dot_2d(ray, ray));
			t = ((-2 * dot_2d(ray, elem->cy[i].o_c)) - sqrt(delta)) / \
			(2 * dot_2d(ray, ray));
			if (fabs((t * ray.z) + elem->cy[i].z_o) < (elem->cy[i].height / 2))
				return (t);
			return (-1);
		}
		t = ((-2 * dot_2d(ray, elem->cy[i].o_c)) + sqrt(delta)) / \
		(2 * dot_2d(ray, ray));
		if (fabs((t * ray.z) + elem->cy[i].z_o) < (elem->cy[i].height / 2))
			return (t);
	}
	return (-1);
}



double	cylinder_intersection_sh(t_elements *elem, t_cogo ray, size_t index)
{
    t_cogo  origin;
    t_cogo	p_c;
    t_cogo  null;
	double	delta;
	double	t;

	t = 0;
    null = (t_cogo){};
    origin = elem->origin;
    update_orient_element(&ray, elem->cy[index].m_pos);
    update_cogo_element(&origin, elem->cy[index].m_pos);
	add_sub_vectors_2d(&p_c, origin, null, -1);
	delta = pow(2 * dot_2d(ray, p_c), 2) - (4 * dot_2d(ray, ray)
		* (dot_2d(p_c, p_c) - pow(elem->cy[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		t = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
        if (fabs((t * ray.z) + origin.z) < (elem->cy[index].height / 2))
            return (t);
	}
	return (-1);
}