#include "minirt.h"

float	magnitude_vector(t_tuple t1)
{
	float	result;

	result = 0;
	result = pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2) + pow(t1.w, 2);
	result = sqrt(result);
	return (result);
}

t_tuple	divide_tuples(t_tuple t1, float value)
{
	t_tuple	result;

	result.x = t1.x / value;
	result.y = t1.y / value;
	result.z = t1.z / value;
	result.w = t1.w / value;
	return (result);
}

t_tuple	scale_tuples(t_tuple t1, float value)
{
	t_tuple	result;

	result.x = t1.x * value;
	result.y = t1.y * value;
	result.z = t1.z * value;
	result.w = t1.w * value;
	return (result);
}

t_tuple	negate_tuples(t_tuple t1)
{
	t_tuple	result;

	result.x = t1.x * -1;
	result.y = t1.y * -1;
	result.z = t1.z * -1;
	result.w = t1.w * -1;
	return (result);
}

t_tuple	subtract_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	result.w = fabs(t1.w - t2.w);
	return (result);
}

t_tuple	adding_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x + t2.x;
	result.y = t1.y + t2.y;
	result.z = t1.z + t2.z;
	if (t1.w == 1 && t2.w == 1)
		result.w = 1;
	else
		result.w = t1.w + t2.w;
	return (result);
}

t_tuple	create_tuple(float x, float y, float z, int w)
{
	t_tuple	temp;

	temp.x = x;
	temp.y = y;
	temp.z = z;
	temp.w = w;
	return (temp);
}

void	print_tuple(t_tuple tuple)
{
	printf("x:%f\ny:%f\nz:%f\nw:%f\n", tuple.x, tuple.y, tuple.z, tuple.w);
}

t_tuple	normalize_vector(t_tuple vector)
{
	float	mag;
	t_tuple	normalized_vec;

	mag = magnitude_vector(vector);
	normalized_vec.x = vector.y / mag;
	normalized_vec.y = vector.y / mag;
	normalized_vec.z = vector.z / mag;
	return (normalized_vec);
}

t_projectile	tick(t_environment *env, t_projectile *proj)
{
	t_projectile	result;
	t_tuple			velocity;

	result.position = adding_tuples(proj->position, proj->norm_vec);
	velocity = adding_tuples(proj->norm_vec, env->g_vec);
	velocity = adding_tuples(velocity, env->w_vec);
	result.norm_vec = velocity;
	return (result);
}

int	main(void)
{
	t_tuple			position;
	t_tuple			velocity;
	t_tuple			gravity;
	t_tuple			wind;
	t_projectile	proj;
	t_environment	env;
	int				tik_counter;

	tik_counter = 0;
	position = create_tuple(0, 1, 0, 0);
	velocity = create_tuple(1, 1, 0, 1);
	gravity = create_tuple(0, -0.1, 0, 1);
	wind = create_tuple(-0.01, 0, 0, 1);
	proj.position = position;
	proj.norm_vec = velocity;
	env.g_vec = gravity;
	env.w_vec = wind;

	while (proj.position.y > 0)
	{
		proj = tick(&env, &proj);
		tik_counter++;
		printf("projectile position is (%f,%f,%f)\n", proj.position.x,  proj.position.y,  proj.position.z);
		printf("# of ticks is: %d\n", tik_counter);

	}
		return (0);
}
