/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <eabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:41:06 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/13 17:11:07 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	cone_intersection(t_elements *elem, t_cogo ray, size_t i)
{
	t_cogo o_c;
	t_cogo o;
    // double d;
    double	delta;
	double	teta;
	double	a;
	double	b;
	double	c;
	double	t;

	t = 0;
    o = elem->co[i].orient;
    add_sub_vectors(&o_c, elem->origin, elem->co[i].pos, -1);
    teta = atan((elem->co[i].base / 2) / elem->co[i].height);

    
    a = pow(dot(ray, elem->co[i].orient), 2) - pow(cos(teta), 2);
    b = 2 * ((dot(ray, elem->co[i].orient) * dot(o_c, elem->co[i].orient)) - (dot(ray, o_c) * pow(cos(teta), 2)));
    c = pow(dot(o_c, elem->co[i].orient), 2) - (dot(o_c, o_c) * pow(cos(teta), 2));
    
    delta = pow(b, 2) - (4 * a * c);
	if (delta > 0)
	{
	
		t = (-b - sqrt(delta)) / (2 * a);
        // scaler_multiplication(&ray, ray, t);
        // add_sub_vectors(&ray, ray, elem->co[i].pos, -1);
        // resize_vec(&ray, ray, 1);
        // resize_vec(&o, o, 1);
        // d = dot(ray, o);
        // if (d > 0 && d < cos(teta))
		    return (t);
	}
	return (-1);
}

// double	cone_intersection_sh(t_elements *elem, t_cogo ray, size_t index)
// {
// 	t_cogo	origin;
// 	t_cogo	p_c;
// 	t_cogo	null;
// 	double	delta;
// 	double	t;

// 	t = 0;
// 	null = (t_cogo){};
// 	origin = elem->origin;
// 	update_orient_element(&ray, elem->cy[index].m_pos);
// 	update_cogo_element(&origin, elem->cy[index].m_pos);
// 	add_sub_vectors_2d(&p_c, origin, null, -1);
// 	delta = pow(2 * dot_2d(ray, p_c), 2) - (4 * dot_2d(ray, ray)
// 			* (dot_2d(p_c, p_c) - pow(elem->cy[index].diameter / 2, 2)));
// 	if (delta > 0)
// 	{
// 		t = ((-2 * dot_2d(ray, p_c)) + sqrt(delta)) / (2 * dot_2d(ray, ray));
// 		if (fabs((t * ray.z) + origin.z) < (elem->cy[index].height / 2))
// 			return (t);
// 	}
// 	return (-1);
// }
