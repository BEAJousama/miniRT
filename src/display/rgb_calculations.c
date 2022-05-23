/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:01:56 by eabdelha          #+#    #+#             */
/*   Updated: 2022/05/23 10:01:57 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"


int calculate_rgb(int rgb_obj, int rgb_light, double ratio)
{
    unsigned char   b = rgb_obj >> 16;
    unsigned char   g = rgb_obj >> 8;
    unsigned char   r = rgb_obj;
    unsigned char   b_l = rgb_light >> 16;
    unsigned char   g_l = rgb_light >> 8;
    unsigned char   r_l = rgb_light;

    return ((int)(r + (r_l * ratio)) | (int)(g + (g_l * ratio)) << 8 | (int)(b + (b_l * ratio)) << 16);
}


// double  diffuse_coefficient(t_cogo ray, t_cogo sh_ray)
// {

// }