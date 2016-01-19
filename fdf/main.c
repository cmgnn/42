#include "fdf.h"
#define PI 3.14159265359
typedef __builtin_va_list v_list;

t_point	*print_point(t_point *p)
{
	printf("(%d , %d , %d)\n", p->x, p->y, p->z);
	return (p);
}

void	draw_fdf(t_env *e, t_point **p, int len, int coul, int nl)
{
	int i, dx = 0, dy = 0;
	//printf("n = %d\n", n);
	i = 0;
	while (i + 1 < len)
	{
		if ((i + 1) % (nl) != 0)
		draw_line(e, p[i], p[i + 1], coul);
		if (i + nl < len)
			draw_line(e, p[i], p[i + nl], coul);
		i++;
	}
}

int	readpts(int const fd, t_point **p, int *n)
{
	char line[1024];
	char	*ptr = line;
	int i = 0, j = 0, d = 0;

	while (get_next_line(fd, &ptr) > 0)
	{
		printf("%s\n", ptr);
		j = 0;
		while (*ptr)
		{
			while (*ptr && !ft_isdigit(*ptr) && *ptr != '-')
				ptr++;
			p[d] = new_point(i, j, ft_atoi(ptr));
			print_point(p[d]);
			j++;
			while (*ptr && (ft_isdigit(*ptr) || *ptr == '-'))
					ptr++;
			d++;
		}
		i++;
	}
	*n = j;
	return (d);
}

void	recadrer(t_env *e, t_matrix *mat, int value)
{
	int dx = e->l / 2;
	int dy = e->h / 2;
	t_point	p;

	set_point(&p, 20, 20, value);
//	foreach_matrix(mat, &homothesie, &value);
	foreach_matrix(mat, &scale, &p);
}

int main()
{

	t_env	*e;
	t_point p1, p2, p3, p4;
	//t_point delt;
	//t_point s1, s2, s3, s4;
	t_point	*(axe[]) = {&p1, &p2, &p3, &p4};
	//t_point	*(sq[]) = {&s1, &s2, &s3, &s4};
	t_matrix	mat, dat;
	t_rotation	r;
	int n = 0;
	//set_point(&delt, , );
	t_point **tab = (t_point**)malloc(sizeof(t_point*) * 10000000);
	int fd = open("test/elem.fdf", O_RDONLY);
	int len = readpts(fd, tab, &n);
	close(fd);
	//int h = 2;
	set_matrix(&mat, axe, 4);
	set_matrix(&dat, tab, len);
	
	set_point(&p1, 1, 1, 1);
	set_point(&p2, 10, 10, 1);
	set_point(&p3, 200, 200, 1);
	set_point(&p4, 200, 200, 1);

/*	set_point(&s1, 400, 400, 1);
	set_point(&s2, 200, 400, 1);
	set_point(&s3, 200, 200, 1);
	set_point(&s4, 400, 200, 1);
*/
	if ( (e = new_env(600, 600, 300, 300, 1)) )
	{
//		recadrer(e, &dat, 1);
		set_rotation(&r, e->origin, 3, 1);
		printf("draw\n");
		foreach_matrix(&dat, &scale, &p2);

		foreach_matrix(&dat, &translate, e->origin);
		draw_fdf(e, dat.mat, dat.len, 0xffffff, n);
		printf("draw\n");
		foreach_matrix(&dat, &rotate_point, &r);
		sleep(2);
		mlx_clear_window(e->mlx, e->screen);
		draw_fdf(e, dat.mat, dat.len, 0xffffff, n);

		sleep(2);
		free_env(e);
	}
	while (len >= 0)
	{
		free(tab[len]);
		len--;
	}
	free(tab);
	return (0);
}
