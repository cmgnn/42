#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/implemt.h"
# undef BUFF_SIZE
# define BUFF_SIZE 1000
typedef void *t_scn;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_env
{
	int			h;
	int			l;

	t_point		*origin;
	void		*mlx;
	t_scn		*screen;
}				t_env;

typedef	struct	s_rotation
{
	int			ro;
	float			theta;
	t_point		*center;
}				t_rotation;

typedef	struct	s_matrix
{
	t_point		**mat;
	size_t		len;
}				t_matrix;

void	draw_rect(t_env *e, t_point *center, int len, int h, int coul);
void	free_env(t_env *e);
void	draw_line(t_env *e, t_point *p1, t_point *p2, int coul);
t_env	*new_env(int h, int l, int xo, int yo, int zo);
t_point	*new_point(int x, int y, int z);
void	set_point(t_point *pt, int x, int y, int z);
void	draw_hline(t_env *e, int x, int len, int coul);
void	draw_vline(t_env *e, int y, int len, int coul);
void	draw_matrix(t_env *e, t_point *(mat[]), size_t len, int coul);
t_point	*translate(t_point	*p, t_point *vect);
void	foreach_matrix(t_matrix *mat, t_point *(*fct)(), void *arg);
void	set_matrix(t_matrix *mat, t_point	**pts, size_t len);
void	draw_polygon(t_env *e, t_point **mat, size_t len, int coul);
void	set_rotation(t_rotation *r, t_point	*p, float th, int ro);
t_point	*rotate_point(t_point *p, t_rotation *r);
t_point	*homothesie(t_point	*p, int *del);
t_point	*rotate_axe(t_point *p, t_rotation *r);
t_point	*scale(t_point	*p, t_point *rep);

#endif
