#include <unistd.h>

void put_number(int i)
{
    char c;
    int n;

    n = 0;
    if(i < 10)
    {
        c = i + '0';
        write(1, &c, 1);
    }
    else if( i < 100)
    {
        put_number(i / 10);
        put_number(i % 10);
    }
}
int main(void)
{
int i;
int n;

n = 0;
i = 1;
while (i <= 100)
{
    if ((i % 5 == 0) && (i % 3 == 0))
        write(1, "fizzbuzz", 8);
    else if (i % 3 == 0)
        write(1, "fizz", 4);
    else if (i % 5 == 0)
        write(1, "buzz", 4);
    else
        put_number(i);
    write(1, "\n", 1);
    i++;
}

}