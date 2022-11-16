
#ifndef CHAOS_SIM_H
# define CHAOS_SIM_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct s_dot;
{
    double  x;
    double  y;
    double  d;
}   t_dot;

typedef struct s_render {
	int			dot_num;
	t_dot			*dots;
	pthread_t	thread_id;

	int			h;
	int			w;
	void		*mlx;
	void		*mlx_win;

	void		*img;
	char		*addr;
	int			endian;
	int			line_length;
	int			bits_per_pixel;
}	t_render;
