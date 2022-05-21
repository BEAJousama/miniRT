/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obeaj <obeaj@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:42:35 by obeaj             #+#    #+#             */
/*   Updated: 2022/05/20 16:17:37 by obeaj            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

double	magnitude(t_vector *v)
{
	return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
}

t_vector	*normalize(t_vector *v)
{
	return (elong(v, 1 / (magnitude(v))));
}

void	translation(t_point *p, t_vector *v)
{
	p->x += v->x;
	p->y += v->y;
	p->z += v->z;
}

t_vector	*negate(t_vector *v)
{
	t_vector	*v1;

	v1->x = -v->x;
	v1->y = -v->y;
	v1->z = -v->z;
	return (v1);
}
