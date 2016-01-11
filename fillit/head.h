#ifndef TETRINOID
# define TETRINOID
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# define MAX_TETRINOID 26
# define MAX 10000000
typedef struct		s_tetrinoid
{
	unsigned int	mat[MAX_TETRINOID];
	char		c;
}			t_tetrinoid;

typedef struct		s_solution
{
	char		buffer[MAX];
	unsigned int	size;
}			t_solution;

typedef	struct s_solverstate
{
	t_solution *s;
	unsigned int ref[MAX];

}				t_solverstate;

//int		v4(t_tetrinoid **mat, int bool, unsigned int *ref, t_solution *s);

t_solution	*init_solution(unsigned int size);
t_tetrinoid	*init_tetrinoid(unsigned int *mat, char c);
void		free_tetrinoid(t_tetrinoid *t);
unsigned int	*init_item(unsigned int *buffer, unsigned int size);
void		build_solution(unsigned int size, t_solution *s, t_tetrinoid *item);
void		leave_solution(unsigned int size, t_solution *s, t_tetrinoid *item);

unsigned int	*move_left(unsigned int *item, unsigned int size);
unsigned int	*move_down(unsigned int *ref, unsigned int *item, unsigned int size);
int		move_item(unsigned int *ref, unsigned int size, unsigned int *tmp, int bool);
unsigned int	*reset_item(unsigned int size, unsigned int *item, int flag);

unsigned int	bits_fort(unsigned int value, unsigned int n);
int             solution(unsigned int size, unsigned int *ref, t_solution **s);
unsigned int	*concat(unsigned int *ref, unsigned int *item, unsigned int size);
unsigned int	*reset(unsigned int *ref, unsigned int *item, unsigned int size);
int		verification(unsigned int *ref, unsigned int *item, unsigned int size);
int		v3(t_tetrinoid **mat, int bool, unsigned int *ref, t_solution *s);

void		print_tab(unsigned int *tab, unsigned int size, char c);

void		print(const char *str, ...);
int		v3(t_tetrinoid **mat, int bool, unsigned int *ref, t_solution *s);
int		v4(t_tetrinoid **mat, unsigned int *item, unsigned int *ref, t_solution *s);
#endif
