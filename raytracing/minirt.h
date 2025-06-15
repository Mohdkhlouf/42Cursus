#ifndef minirt
# define minirt

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "MLX42/include/MLX42/MLX42.h"

#define WIDTH 1500
#define HEIGHT 550
#define BPP sizeof(int32_t)

typedef struct s_2dpoint 
{
	float x;
	float y;
}	t_2dpoint;


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