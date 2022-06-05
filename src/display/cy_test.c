/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:57:13 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/04 10:57:14 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


double	cy_test(t_elements *elem, t_cogo ray, size_t index)
{
    t_cogo	p_c;
    t_cogo  origin;
    t_cogo  null;
	double	delta;
	double	t1;
	double	t2;

	t1 = 0;
	t2 = 0;
    null = (t_cogo){};
    origin = elem->origin;
    update_orient_element(&ray, elem->cy[index].m_pos);
    update_cogo_element(&origin, elem->cy[index].m_pos);
	add_sub_vectors_2d(&p_c, origin, null, -1);
	delta = pow(2 * dot_2d(ray, p_c), 2) - (4 * dot_2d(ray, ray)
		* (dot_2d(p_c, p_c) - pow(elem->cy[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		if (mag_vector_2d(p_c) >= (elem->cy[index].diameter / 2))
			t1 = ((-2 * dot_2d(ray, p_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
		else 
			t2 = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
	}
	if (t1 > 0.00001 && fabs((t1 * ray.z) + origin.z) < (elem->cy[index].height / 2))
		return (t1);
	if (t2 > 0.00001 && fabs((t1 * ray.z) + origin.z)< (elem->cy[index].height / 2))
		return (t2);
	return (0);
}

double	cy_test_sh(t_elements *elem, t_cogo ray, size_t index)
{
    t_cogo	p_c;
    t_cogo  origin;
    t_cogo  null;
	double	delta;
	double	t1;
	double	t2;

	t1 = 0;
	t2 = 0;
    null = (t_cogo){};
    origin = elem->origin;
    update_orient_element(&ray, elem->cy[index].m_pos);
    update_cogo_element(&origin, elem->cy[index].m_pos);
	add_sub_vectors_2d(&p_c, origin, null, -1);
	delta = pow(2 * dot_2d(ray, p_c), 2) - (4 * dot_2d(ray, ray)
		* (dot_2d(p_c, p_c) - pow(elem->cy[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		t2 = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
        if (t2 > -0.00001 && t2 < 1  && fabs((t2 * ray.z) + origin.z) < (elem->cy[index].height / 2))
            return (t2);
		t1 = ((-2 * dot_2d(ray, p_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
		if (t1 > -0.00001 && t1 < 1  && fabs((t1 * ray.z) + origin.z) < (elem->cy[index].height / 2))
			return (t1);
	}
	return (-1);
}