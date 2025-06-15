#include "minirt.h"

t_tuple ray_position(t_ray ray, float t)
{
	t_tuple point;

	point = adding_tuples(ray.position, scale_tuples(ray.direction,t));
	return (point);
}
t_ray create_ray(t_tuple position, t_tuple direction)
{
	t_ray ray;
	ray.position = position;
	ray.direction = direction;
	return (ray);
}

float	magnitude_vector(t_tuple t1)
{
	float	result;

	result = 0;
	result = pow(t1.x, 2) + pow(t1.y, 2) + pow(t1.z, 2);
	result = sqrt(result);
	return (result);
}

t_tuple	divide_tuples(t_tuple t1, float value)
{
	t_tuple	result;

	result.x = t1.x / value;
	result.y = t1.y / value;
	result.z = t1.z / value;
	return (result);
}

t_tuple	scale_tuples(t_tuple t1, float value)
{
	t_tuple	result;

	result.x = t1.x * value;
	result.y = t1.y * value;
	result.z = t1.z * value;
	return (result);
}

t_tuple	negate_tuples(t_tuple t1)
{
	t_tuple	result;

	result.x = t1.x * -1;
	result.y = t1.y * -1;
	result.z = t1.z * -1;
	return (result);
}

t_tuple	subtract_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	return (result);
}

t_tuple	adding_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	result;

	result.x = t1.x + t2.x;
	result.y = t1.y + t2.y;
	result.z = t1.z + t2.z;
	return (result);
}

t_tuple	create_tuple(float x, float y, float z)
{
	t_tuple	temp;

	temp.x = x;
	temp.y = y;
	temp.z = z;
	return (temp);
}

void	print_tuple(t_tuple tuple)
{
	printf("x:%f\ny:%f\nz:%f\n", tuple.x, tuple.y, tuple.z);
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

// t_projectile	tick(t_environment *env, t_projectile *proj)
// {
// 	t_projectile	result;
// 	t_tuple			velocity;

// 	result.position = adding_tuples(proj->position, proj->norm_vec);
// 	velocity = adding_tuples(proj->norm_vec, env->g_vec);
// 	velocity = adding_tuples(velocity, env->w_vec);
// 	result.norm_vec = velocity;
// 	return (result);
// }

// int	main(void)
// {

// 	return (0);
// }


t_sphere create_sphere()
{	
	return (t_sphere){create_tuple(0,0,0), 1.0f};
}
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
t_tuple position;
t_tuple point;
t_tuple direction;
t_sphere sphere;
t_ray ray;
position = create_tuple(0, 0, -5);

direction = create_tuple(0, 0, 1);
ray = create_ray(position, direction);

mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Minirt", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t *img = mlx_new_image(mlx, 1500, 550);

	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	point = ray_position(ray,2.5);
	print_tuple(point);
	sphere = create_sphere();
	print_tuple(sphere.center);
	




	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
