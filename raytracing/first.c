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



t_tuple projectile(t_tuple env, t_tuple proj)
{
	
}

int	main(void)
{
	t_tuple	point;
	t_tuple	vector;
	t_tuple	result;
	t_tuple	result2;
	float mag1;
	mag1 = 0;

	
	point = create_tuple(3, 2, 1, 1);
	vector = create_tuple(-1,-2,-3,0);
	result = adding_tuples(point, vector);
	print_tuple(result);
	result2 = subtract_tuples(point, vector);
	print_tuple(result2);

	mag1 = magnitude_vector(vector);
	printf("magnitude for mag1:%f\n", mag1);





	function tick(env, proj)
position ← proj.position + proj.velocity
velocity ← proj.velocity + env.gravity + env.wind
return projectile(position, velocity)
end function


	return (0);
}
