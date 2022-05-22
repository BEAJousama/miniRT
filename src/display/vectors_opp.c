/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:05:47 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/22 14:42:59 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	dot(t_cogo	v_one, t_cogo v_two)
{
	return ((v_one.x * v_two.x) + (v_one.y * v_two.y) +(v_one.z * v_two.z));
}

void	add_sub_vectors(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe)
{
	v_res->x = v_one.x + (signe * v_two.x);
	v_res->y = v_one.y + (signe * v_two.y);
	v_res->z = v_one.z + (signe * v_two.z);
}

double	mag_vector(t_cogo vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

void	scaler_multiplication(t_cogo *vec, double scaler)
{
	vec->x = scaler * vec->x;
	vec->y = scaler * vec->y;
	vec->z = scaler * vec->z;
}

t_cogo	cross_product(t_cogo *v1, t_cogo *v2)
{
	t_cogo	v;

	v.x = v1->y * v2->z - v1->z * v2->y;
	v.y = v2->x * v1->z - v1->x * v2->z;
	v.z = v1->x * v2->y - v1->y * v2->x;
	return (v);
}

t_cogo	vec_create(t_cogo a, t_cogo b)
{
	t_cogo	v;

	v.x = b.x - a.x;
	v.y = b.y - a.y;
	v.z = b.z - a.z;
	return (v);
}
