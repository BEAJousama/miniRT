/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_opp_2d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:56:12 by eabdelha          #+#    #+#             */
/*   Updated: 2022/06/05 18:56:14 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double	dot_2d(t_cogo	v_one, t_cogo v_two)
{
	double r;

	r = (v_one.x * v_two.x) + (v_one.y * v_two.y);
	return (r);
}

t_cogo	add_sub_vectors_2d(t_cogo v_one, t_cogo v_two, int signe)
{
	t_cogo	v_res;

	v_res.x = v_one.x + ((double)signe * v_two.x);
	v_res.y = v_one.y + ((double)signe * v_two.y);
	return (v_res);
}

double	mag_vector_2d(t_cogo vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2)));
}

void	resize_vec_2d(t_cogo *vec, t_cogo v, double len)
{
	double	hol_mag;

	hol_mag = mag_vector_2d(v);
	vec->x = (len / hol_mag) * v.x;
	vec->y = (len / hol_mag) * v.y;
}