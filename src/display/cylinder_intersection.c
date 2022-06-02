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

double	disk_inter(t_disk disk, t_cogo ray, t_elements *elem)
{
	t_cogo	tn;
	t_cogo	c_p;
	t_cogo	v;
	double	scaler;

	if (disk.orient.x == 0 && disk.orient.y == 0
		&& disk.orient.z == 0)
		return (0);
	else
	{
		add_sub_vectors(&c_p, disk.pos, elem->origin, -1);
		scaler = dot(c_p, disk.orient) / dot(ray,
				disk.orient);
		scaler_multiplication(&tn, ray, scaler);
		v = vec_create(tn, disk.pos);
		if (mag_vector(v) <= disk.rayon)
			return (scaler);
	}
	return (0);
}

double	disk_create(t_elements *elem, t_cogo ray, int index, t_cogo p_c)
{
	t_disk	plan1;
	t_disk	plan2;
	double	t;
	
	(void)p_c;	
	plan1.orient = elem->cy[index].orient;
	plan2.orient = elem->cy[index].orient;
	plan1.rgb = elem->cy[index].rgb;
	plan2.rgb = elem->cy[index].rgb;
	plan1.pos.y = elem->cy[index].pos.y + elem->cy[index].height / 2;
	plan2.pos.y = elem->cy[index].pos.y - elem->cy[index].height / 2;
	plan1.pos.x = elem->cy[index].pos.x;
	plan2.pos.x = elem->cy[index].pos.x;
	plan1.pos.z = elem->cy[index].pos.z;
	plan2.pos.z = elem->cy[index].pos.z;
	plan1.rayon = elem->cy[index].diameter / 2;
	plan2.rayon = elem->cy[index].diameter / 2;
	t = disk_inter(plan1, ray, elem);
	if (t < disk_inter(plan2, ray, elem))
		t = disk_inter(plan2, ray, elem);
	return (t);
}

double	cylinder_intersection(t_elements *elem, t_cogo ray, int index, int isshadow)
{
	// return (0);
	double	t;
	double	a,b,c,delta;
	t_cogo	p_c;
	t_cogo	tn;
	t_cogo	p_c_cross;
	t_cogo ray_cross;

	isshadow = 0;
	add_sub_vectors(&p_c, elem->c->pos, elem->cy[index].pos, -1);
	p_c_cross = cross_product(p_c, elem->cy[index].orient);
	ray_cross = cross_product(ray, elem->cy[index].orient);
	a = pow(mag_vector(ray), 2) * pow(mag_vector(elem->cy[index].orient), 2)
		- pow(dot(ray, elem->cy[index].orient), 2);
	b = 2 * (dot(p_c_cross, ray_cross));
	c = pow(mag_vector(p_c), 2) * pow(mag_vector(elem->cy[index].orient), 2)
		- pow(dot(p_c, elem->cy[index].orient), 2)
		- pow(elem->cy[index].diameter / 2, 2)
		* dot(elem->cy[index].orient, elem->cy[index].orient);
	delta = pow(b, 2) - 4 * a * c ;
	if (delta >= 0)
	{
		if (mag_vector(p_c) >= elem->cy[index].diameter / 2)
			t = (-b - sqrt(delta)) / (2 * a);
		else
			t = (-b + sqrt(delta)) / (2 * a);
		scaler_multiplication(&tn,ray, t);
		if (tn.y < (elem->cy[index].pos.y + elem->cy[index].height / 2)
			&& tn.y > (elem->cy[index].pos.y - elem->cy[index].height / 2))
		{
			return (t);
		}
	}
	return (disk_create(elem, ray, index, p_c));
	return (0);
}
