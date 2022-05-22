/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:09:19 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 10:05:51 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int sphere_intersection(t_elements *elem, t_cogo ray)
{
	double	delta;
	t_cogo	p_c;

	add_sub_vectors(&p_c, elem->c->pos, elem->sp->pos, -1);
	delta = pow(2 * dot(ray, p_c), 2) - (4 * dot(ray, ray)
			* (dot(p_c, p_c) - pow(elem->sp->diameter / 2, 2)));

	if (delta < 0)
		return (0);
	else if (delta == 0)
		return (-dot(ray, p_c) / (2 * dot(ray, ray)));
	else
		return ((-dot(ray, p_c) - sqrt(delta)) / (2 * dot(ray, ray)));
}