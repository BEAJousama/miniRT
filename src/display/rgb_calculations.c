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


int multi_rgb(int rgb_o, int rgb_l, double ratio)
{
    unsigned int    b_r;
    unsigned int    g_r;
    unsigned int    r_r;

    b_r = ((unsigned char)(rgb_o >> 16) * (unsigned char)(rgb_l >> 16) / 255);
    g_r = ((unsigned char)(rgb_o >> 8) * (unsigned char)(rgb_l >> 8) / 255);
    r_r = ((unsigned char)rgb_o * (unsigned char)rgb_l / 255);
    b_r = b_r > 255 ? 255 : b_r;
    g_r = g_r > 255 ? 255 : g_r;
    r_r = r_r > 255 ? 255 : r_r;
    return ((int)(r_r * ratio) | (int)(g_r * ratio) << 8 \
    | (int)(b_r * ratio) << 16);
}


int add_rgb(int rgb_o, int rgb_l)
{
    unsigned int    b_r;
    unsigned int    g_r;
    unsigned int    r_r;
    
    b_r = (unsigned char)(rgb_o >> 16) + (unsigned char)(rgb_l >> 16);
    g_r = (unsigned char)(rgb_o >> 8) + (unsigned char)(rgb_l >> 8);
    r_r = (unsigned char)rgb_o + (unsigned char)rgb_l;
    b_r = b_r > 255 ? 255 : b_r;
    g_r = g_r > 255 ? 255 : g_r;
    r_r = r_r > 255 ? 255 : r_r;
    return ((int)(r_r) | (int)(g_r) << 8 | (int)(b_r) << 16);
}
