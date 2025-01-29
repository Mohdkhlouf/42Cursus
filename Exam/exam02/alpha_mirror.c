#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s;
    unsigned int i;

    i = 0;
    if (argc == 2)
    {
        s = argv[1];
        while (s[i])
        {
            rot13(s[i]);
            i++;
        }
    }
    write(1,"\n",1);
return (0);
}