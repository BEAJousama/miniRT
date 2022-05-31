/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_opp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:05:47 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/30 15:02:20 by obeaj            ###   ########.fr       */
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

void	scaler_multiplication(t_cogo *vec, t_cogo v,double scaler)
{
	vec->x = scaler * v.x;
	vec->y = scaler * v.y;
	vec->z = scaler * v.z;
}

t_cogo	cross_product(t_cogo v1, t_cogo v2)
{
	t_cogo	v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v2.x * v1.z - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
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

void	resize_vec(t_cogo *vec, t_cogo v, double len)
{
	double	hol_mag;

	hol_mag = mag_vector(v);
	vec->x = (len / hol_mag) * v.x;
	vec->y = (len / hol_mag) * v.y;
	vec->z = (len / hol_mag) * v.z;
}