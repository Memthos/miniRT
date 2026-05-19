#ifndef COLORS_H
# define COLORS_H

# include "types.h"

typedef struct s_rgb
{
	t_uint8	r;
	t_uint8	g;
	t_uint8	b;
}	t_rgb;

typedef struct s_rgba
{
	t_uint8	r;
	t_uint8	g;
	t_uint8	b;
	t_uint8	a;
}	t_rgba;

#endif