/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_epsilon_inter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:05:26 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/05 19:05:27 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	epsilon_sphere(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->sp[index].pos, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->sp[index].pos, -1);
	if ((mag_vector(c_c) < (elem->sp[index].diameter / 2) \
				&& mag_vector(l_c) > (elem->sp[index].diameter / 2))
		|| (mag_vector(c_c) > (elem->sp[index].diameter / 2) \
				&& mag_vector(l_c) < (elem->sp[index].diameter / 2)))
		return (-0.00001);
	return (0.00001);
}

double	epsilon_plane(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->origin, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->origin, -1);
	if ((dot(c_c, elem->pl[index].orient) * \
				dot(l_c, elem->pl[index].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}

double	epsilon_cylinder(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->cy[index].pos, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->cy[index].pos, -1);
	update_orient_element(&c_c, elem->cy[index].m_pos);
	update_orient_element(&l_c, elem->cy[index].m_pos);
	if ((mag_vector_2d(c_c) < (elem->cy[index].diameter / 2) \
				&& mag_vector_2d(l_c) > (elem->cy[index].diameter / 2))
		|| (mag_vector_2d(c_c) > (elem->cy[index].diameter / 2) \
				&& mag_vector_2d(l_c) < (elem->cy[index].diameter / 2)))
		return (-0.00001);
	return (0.00001);
}

double	epsilon_cy_disk(t_elements *elem, size_t index)
{
	t_cogo	c_c;
	t_cogo	l_c;

	add_sub_vectors(&c_c, elem->c->pos, elem->origin, -1);
	add_sub_vectors(&l_c, elem->l->pos, elem->origin, -1);
	if ((dot(c_c, elem->cy[index].orient) * \
				dot(l_c, elem->cy[index].orient)) > 0)
		return (0.00001);
	return (-0.00001);
}
