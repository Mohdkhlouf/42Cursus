#ifndef minirt
# define minirt

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct s_tuple
{
	float x;
	float y;
	float z;
	float w;
}	t_tuple;

typedef struct s_projectile
{
	t_tuple position;
	t_tuple norm_vec;
}	t_projectile;



typedef struct s_environment
{
	t_tuple g_vec;
	t_tuple w_vec;
}	t_environment;



#endif