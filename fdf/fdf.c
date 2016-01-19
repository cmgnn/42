#include "fdf.h"

void	set_point(t_point *pt, int x, int y, int z)
{
	if (!pt)
		pt = new_point(x, y, z);
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

t_point	*new_point(int x, int y, int z)
{
	t_point *pt;
	
	if ((pt = (t_point*)malloc(sizeof(t_point))))
		set_point(pt, x, y, z);
	else
		ft_putstr_fd("<point.c> malloc error", 2);
	return (pt); 
}

t_env	*new_env(int h, int l, int xo, int yo, int zo)
{
	t_env *e;
	
	if ((e = (t_env*)malloc(sizeof(t_env))) && ((e->mlx = mlx_init())))
	{
		e->h = h;
		e->l = l;
		e->origin = (t_point*)new_point(xo, yo, zo);
		e->screen = mlx_new_window(e->mlx, h, l, "win");
	}
	else
		ft_putstr_fd("<env.c> malloc error\n", 2);
	return (e);
}

void	set_rotation(t_rotation *r, t_point	*p, float th, int ro)
{
	r->center = p;
	r->theta = th;
	r->ro = ro;
}

void	set_matrix(t_matrix *mat, t_point	**pts, size_t len)
{
	mat->mat = pts;
	mat->len = len;
}

void	free_env(t_env *e)
{
	if (e)
	{
		mlx_destroy_window(e->mlx, e->screen);
		ft_memdel((void**)&e->origin);
		ft_memdel((void**)&e->mlx);
		ft_memdel((void**)&e);
	}
}

static void	_draw_line_(t_env *e, t_point *p1, t_point *p2, int coul)
{
	int		x, y = 0;

	if (p1->y < p2->y)
	{
		//ft_putstr_fd("1\n", 1);
		ft_swap(&p1->x, &p2->x);
		ft_swap(&p1->y, &p2->y);
	}
	y = p1->y;
	if ((p2->x - p1->x) > (p2->y - p1->y))
	{
		while (y > p2->y)
		{
			mlx_pixel_put(e->mlx,e->screen, p1->x + ((p2->x - p1->x) * (y - p1->y))
			/ (p2->y - p1->y), y, coul);
			--y;
		}
	}
	if (p1->x > p2->x)
	{
		//ft_putstr_fd("2\n", 1);
		ft_swap(&p2->x, &p1->x);
		ft_swap(&p2->y, &p1->y);
	}
	x = p1->x;
	while (x < p2->x)
	{
		mlx_pixel_put(e->mlx,e->screen, x, p1->y + ((p2->y - p1->y) * (x - p1->x))
		/ (p2->x - p1->x), coul);
		++x;
	}
}

void	draw_line(t_env *e, t_point *p1, t_point *p2, int coul)
{
	t_point d1, d2;

	set_point(&d1, p1->x, p1->y, 0);
	set_point(&d2, p2->x, p2->y, 0);
	_draw_line_(e, &d1, &d2, coul);
}

void	draw_vline(t_env *e, int x, int len, int coul)
{
	int y = 0;
	while (y < len)
	{
		mlx_pixel_put(e->mlx, e->screen, x, y, coul);
		y++;
	}
}

void	draw_hline(t_env *e, int y, int len, int coul)
{
	int x = 0;
	while (x < len)
	{
		mlx_pixel_put(e->mlx, e->screen, x, y, coul);
		x++;
	}
}


void	draw_rect(t_env *e, t_point *center, int len, int h, int coul)
{
	int x, y;

	x = 0;
	while (x < len / 2)
	{
		y = 0;
		while (y < h / 2)
		{
			mlx_pixel_put(e->mlx, e->screen, center->x + x, center->y + y, coul);
			y++;
		}
		x++;
	}
}

void	draw_polygon(t_env *e, t_point **mat, size_t len, int coul)
{
	size_t i;

	i = 0;
	while (i + 1 < len)
	{
		draw_line(e, mat[i], mat[i + 1], coul);
		i++;
	}
	draw_line(e, mat[i], mat[0], coul);
}

