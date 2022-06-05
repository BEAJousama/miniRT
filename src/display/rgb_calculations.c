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


int multi_rgb(int rgb1, int rgb2, double ratio)
{
    unsigned int    b;
    unsigned int    g;
    unsigned int    r;

    b = ((unsigned char)(rgb1 >> 16) * (unsigned char)(rgb2 >> 16) / 255);
    g = ((unsigned char)(rgb1 >> 8) * (unsigned char)(rgb2 >> 8) / 255);
    r = ((unsigned char)rgb1 * (unsigned char)rgb2 / 255);
    b = b > 255 ? 255 : b;
    g = g > 255 ? 255 : g;
    r = r > 255 ? 255 : r;
    return ((int)(r * ratio) | (int)(g * ratio) << 8 \
    | (int)(b * ratio) << 16);
}


int add_rgb(int rgb1, int rgb2)
{
    unsigned int    b;
    unsigned int    g;
    unsigned int    r;
    
    b = (unsigned char)(rgb1 >> 16) + (unsigned char)(rgb2 >> 16);
    g = (unsigned char)(rgb1 >> 8) + (unsigned char)(rgb2 >> 8);
    r = (unsigned char)rgb1 + (unsigned char)rgb2;
    b = b > 255 ? 255 : b;
    g = g > 255 ? 255 : g;
    r = r > 255 ? 255 : r;
    return ((int)(r) | (int)(g) << 8 | (int)(b) << 16);
}

int mean_rgb(int rgb1, int rgb2)
{
    unsigned int    b;
    unsigned int    g;
    unsigned int    r;

    b = ((unsigned char)(rgb1 >> 16) + (unsigned char)(rgb2 >> 16)) / 2;
    g = ((unsigned char)(rgb1 >> 8) + (unsigned char)(rgb2 >> 8)) / 2;
    r = ((unsigned char)rgb1 + (unsigned char)rgb2) / 2;
    return ((int)(r) | (int)(g) << 8 | (int)(b) << 16);
}