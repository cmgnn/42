#ifndef LS_H
# define LS_H
# if defined WIN32 || defined WIN64
#  define PATH_SEPARATOR "\\"
# else
#  define PATH_SEPARATOR "/"
# endif
# define READ 2
# define WRITE 4
# define EXEC 8

# define READ_WRITE (READ | WRITE)
# define ALL_PERM (READ | WRITE | EXEC)

# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef	struct		s_perm
{
	char		*id;
	unsigned int	mask;
}					t_perm;

typedef struct		s_file
{
	char		*name;
	struct stat	dat;
	struct s_file	*next;
	struct s_file	*dir;
}			t_file;

enum
{
	RECURSIF	= 1,
	LIST		= 2,
	ALL			= 4;
}

enum
{
	ALPHA	= 1,
	MTIME		= 2,
	CTIME			= 4;
}


typedef struct		s_args
{
	int				sort;
	int				mask;
	int				deep;
	char			*folder;
}					t_args;
typedef struct	dirent t_dir;
# define R_OPT	2
# define L_OPT	4

#endif
