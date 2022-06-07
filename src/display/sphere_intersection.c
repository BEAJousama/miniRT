/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:09:19 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 14:23:43 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	sphere_intersection(t_elements *elem, t_cogo ray, size_t index)
{
	t_cogo	p_c;
	double	delta;
	double	t;

	t = 0;
	add_sub_vectors(&p_c, elem->origin, elem->sp[index].pos, -1);
	delta = pow(2 * dot(ray, p_c), 2) - (4 * dot(ray, ray)
		* (dot(p_c, p_c) - pow(elem->sp[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		if (mag_vector(p_c) >= (elem->sp[index].diameter / 2))
		{
			t = ((-2 * dot(ray, p_c)) - sqrt(delta)) / (2 * dot(ray, ray));
			return (t);
		}
		else 
		{
			t = ((-2 * dot(ray, p_c)) + sqrt(delta)) / (2 * dot(ray, ray));
			return (t);
		}
	}
	return (-1);
}

double	sphere_intersection_sh(t_elements *elem, t_cogo ray, size_t index)
{
	t_cogo	p_cs;
	double	delta;
	double	t;

	t = -1;
	add_sub_vectors(&p_cs, elem->origin, elem->sp[index].pos, -1);
	delta = pow(2 * dot(ray, p_cs), 2) - (4 * dot(ray, ray)
		* (dot(p_cs, p_cs) - pow(elem->sp[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		t = ((-2 * dot(ray, p_cs)) + sqrt(delta)) / (2 * dot(ray, ray));
		if (t < 1)
			return (t);
	}
	return (-1);
}

