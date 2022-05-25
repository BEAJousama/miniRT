/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:19:30 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/23 18:19:32 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minirt.h"

double	cylinder_intersection(t_elements *elem, t_cogo ray, size_t index)
{
	t_cogo	p_c;
	double	delta;

	add_sub_vectors(&p_c, elem->origin, elem->sp[index].pos, -1);
	delta = pow(2 * dot(ray, p_c), 2) - (4 * dot(ray, ray)
		* (dot(p_c, p_c) - pow(elem->sp[index].diameter / 2, 2)));
	if (delta >= 0)
	{
		if (mag_vector(p_c) > (elem->sp[index].diameter / 2))
			return (((-2 * dot(ray, p_c)) - sqrt(delta)) / (2 * dot(ray, ray)));
		else 
			return (((-2 * dot(ray, p_c)) + sqrt(delta)) / (2 * dot(ray, ray)));
	}
	return (0);
}