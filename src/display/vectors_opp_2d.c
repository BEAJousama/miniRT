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
	return ((v_one.x * v_two.x) + (v_one.y * v_two.y));
}

void	add_sub_vectors_2d(t_cogo	*v_res, t_cogo v_one, t_cogo v_two, int signe)
{
	v_res->x = v_one.x + (signe * v_two.x);
	v_res->y = v_one.y + (signe * v_two.y);
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