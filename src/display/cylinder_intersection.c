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


// double	cylinder_solution(t_elements *elem)
// {

// }

// double	cy_test(t_elements *elem, t_cogo ray, size_t index)
// {
// 	double	delta;
// 	double	t;

// 	t = 0;
//     update_orient_element(&ray, elem->cy[index].m_pos);
// 	delta = pow(2 * dot_2d(ray, elem->cy[index].o_c), 2) - (4 * dot_2d(ray, ray)
// 		* (dot_2d(elem->cy[index].o_c, elem->cy[index].o_c) - pow(elem->cy[index].diameter / 2, 2)));
// 	if (delta >= 0)
// 	{
// 		if (mag_vector_2d(elem->cy[index].o_c) >= (elem->cy[index].diameter / 2))
// 		{
// 			t = ((-2 * dot_2d(ray, elem->cy[index].o_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
// 			if (fabs((t * ray.z) + elem->cy[index].z_o) < (elem->cy[index].height / 2))
// 				return (t);
// 			return (0);
// 		}
// 		// t = ((-2 * dot_2d(ray, elem->cy[index].o_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
// 		// if (fabs((t * ray.z) + elem->cy[index].z_o) < (elem->cy[index].height / 2))
// 		// 	return (t);
// 	}
// 	return (0);
// }

// double	cy_test(t_elements *elem, t_cogo ray, size_t index)
// {
// 	double	delta;
// 	double	t1;
// 	double	t2;

// 	t1 = 0;
// 	t2 = 0;
// 	delta = 0;
//     update_orient_element(&ray, elem->cy[index].m_pos);
// 	delta = pow(2 * dot_2d(ray, elem->cy[index].o_c), 2) - (4 * dot_2d(ray, ray)
// 		* (dot_2d(elem->cy[index].o_c, elem->cy[index].o_c) - pow(elem->cy[index].diameter / 2, 2)));
// 	if (delta >= 0)
// 	{
// 		if (mag_vector_2d(elem->cy[index].o_c) >= (elem->cy[index].diameter / 2))
// 		{
// 			t1 = ((-2 * dot_2d(ray, elem->cy[index].o_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
// 			if (fabs((t1 * ray.z) + elem->cy[index].z_o) < (elem->cy[index].height / 2))
// 				return (t1);
// 			return (-1);
// 		}
// 		else
// 		{
// 			delta = (mag_vector(elem->cy[index].pos));
// 			// usleep(0);
// 			puts("ok\n");
// 		}
// 	}
// 	// if (fabs((t2 * ray.z) + elem->cy[index].z_o) < (elem->cy[index].height / 2))
// 	// 	return (t2);
// 	return (0);
// }

double	cy_test(t_elements *elem, t_cogo ray, size_t index)
{
    t_cogo	p;
    t_cogo  origin;
    t_cogo  null;
	double	delta;
	double	t1;
	// double	t2;

	t1 = 0;
	// t2 = 0;
    null = (t_cogo){};
    origin = elem->origin;
    update_orient_element(&ray, elem->cy[index].m_pos);
    update_cogo_element(&origin, elem->cy[index].m_pos);
	// add_sub_vectors_2d(&p_c, origin, null, -1);
	p = elem->cy[index].o_c;
	delta = pow(2 * dot_2d(ray, elem->cy[index].o_c), 2) - (4 * dot_2d(ray, ray)
		* (dot_2d(elem->cy[index].o_c, elem->cy[index].o_c) - pow(elem->cy[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		if (mag_vector_2d(elem->cy[index].o_c) >= (elem->cy[index].diameter / 2))
			t1 = ((-2 * dot_2d(ray, elem->cy[index].o_c)) - sqrt(delta)) / (2 * dot_2d(ray, ray));
		// else
		// 	t2 = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
	}
	if (fabs((t1 * ray.z) + origin.z) < (elem->cy[index].height / 2))
		return (t1);
	// if (t2 > 0.00001 && fabs((t1 * ray.z) + origin.z) < (elem->cy[index].height / 2))
	// 	return (t2);
	return (0);
}

double	cy_test_sh(t_elements *elem, t_cogo ray, size_t index)
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