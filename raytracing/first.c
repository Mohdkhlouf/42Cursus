#include "minirt.h"

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
	result.w = abs(t1.w - t2.w);
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
	printf("x:%f\ny:%f\nz:%f\nw:%d\n", tuple.x, tuple.y, tuple.z, tuple.w);
}

int	main(void)
{
	t_tuple	point;
	t_tuple	vector;
	t_tuple	result;
	t_tuple	result2;

	point = create_tuple(3, 2, 1, 1);
	vector = create_tuple(5, 6, 7, 0);
	result = adding_tuples(point, vector);
	print_tuple(result);
	result2 = subtract_tuples(point, vector);
	print_tuple(result2);
	return (0);
}
