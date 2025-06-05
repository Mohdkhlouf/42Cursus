#include "minirt.h"


t_tuple create_tuple(float x, float y, float z, int type)
{
    t_tuple temp;

    temp.x = x;
    temp.y = y;
    temp.z = z;
    temp.type = type;

    return (temp);
}
int main() {
    t_tuple point;
    t_tuple vector;

    point = create_tuple(4,-4,3,1);
    vector = create_tuple(4,4,3,0);

    return (0);
}
