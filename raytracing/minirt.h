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



typedef struct s_tuple
{
	float x;
	float y;
	float z;
}	t_tuple;

typedef struct s_ray
{
	t_tuple position;
	t_tuple direction;
}	t_ray;

typedef struct s_sphere
{
	t_tuple center;
	float radius;
} t_sphere;

t_tuple	scale_tuples(t_tuple t1, float value);
t_tuple	negate_tuples(t_tuple t1);
t_tuple	subtract_tuples(t_tuple t1, t_tuple t2);
t_tuple	adding_tuples(t_tuple t1, t_tuple t2);
t_tuple	create_tuple(float x, float y, float z);
void	print_tuple(t_tuple tuple);
t_tuple	normalize_vector(t_tuple vector);
t_tuple	divide_tuples(t_tuple t1, float value);
float	magnitude_vector(t_tuple t1);
t_ray create_ray(t_tuple position, t_tuple direction);
t_tuple ray_position(t_ray ray, float t);

#endif