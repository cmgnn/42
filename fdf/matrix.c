#include "fdf.h"

t_point	*translate(t_point	*p, t_point *vect)
{
	p->x += vect->x;
	p->y += vect->y;
	p->z += vect->z;
	return (p);
}

t_point	*homothesie(t_point	*p, int *del)
{
	p->x *= *del;
	p->y *= *del;
	p->z *= *del;
	return (p);
}

t_point	*scale(t_point	*p, t_point *rep)
{
	p->x *= rep->x;
	p->y *= rep->y;
	p->z *= rep->z;
	return (p);
}


static t_point **init_rot(float theta, t_point *axe)
{
	t_point	**rot = (t_point**)malloc(sizeof(t_point*) * 3);
	float c = cos(theta), s = sin(theta);
	rot[0] = new_point((axe->x * axe->x) * (1 - c) + c, (axe->x * axe->y) * (1 - c) - (axe->z * s), (axe->x * axe->z) * (1 - c) + (axe->y * s));
	rot[1] = new_point((axe->y * axe->x) * (1 - c) + (axe->z * s), (axe->y * axe->y) * (1 - c) + c, (axe->y * axe->z) * (1 - c) - (axe->x * s));
	rot[2] = new_point((axe->z * axe->x) * (1 - c) - (axe->y * s), (axe->z * axe->y) * (1 - c) + (axe->x * s), (axe->z * axe->z) * (1 - c) + c);
	return (rot);
}

t_point	*rotate_axe(t_point *p, t_rotation *r)
{
	int x = p->x, y = p->y, z = p->z;
	t_point	**rot = init_rot(r->theta, r->center);

	p->x = (x * rot[0]->x) + (0 * rot[0]->y) + (0 * rot[0]->z);
	p->y = (0 * rot[1]->x) + (y * rot[1]->y) + (0 * rot[1]->z);
	p->z = (0 * rot[2]->x) + (0 * rot[2]->y) + (z * rot[2]->z);
	free(rot[0]);
	free(rot[1]);
	free(rot[2]);
	free(rot);
	return (p);
}

t_point	*rotate_point(t_point *p, t_rotation *r)
{
	int x = p->x;
	p->x = ((x - r->center->x) * cos(r->theta) - (p->y - r->center->y) * sin(r->theta)) + r->center->x;
	p->y = ((x - r->center->x) * sin(r->theta) + (p->y - r->center->y) * cos(r->theta)) + r->center->y;
	return (p);
}

void	foreach_matrix(t_matrix *mat, t_point *(*fct)(), void *arg)
{
	size_t i;

	i = 0;
	while (i < mat->len)
	{
		mat->mat[i] = (arg) ? (*fct)(mat->mat[i], arg) : (*fct)(mat->mat[i]);
		i++;
	}
}

