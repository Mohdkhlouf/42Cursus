#include <unistd.h>

void repeat_alpha(char c)
{
    int x;
    if (!(c >= 97 && c <= 122) && !(c >= 65 && c <= 90))
        write(1,&c,1);
    else
    {
        if (c >= 97 && c <= 122)
            x = c - 97 + 1;
        else if (c >= 65 && c <= 90)
            x = c - 65 + 1;
        while(x > 0)
        {
            write(1,&c,1);
            x--;
        }
    }
}
int main(int argc, char *argv[])
{
    char *s;
    unsigned int i;

    i = 0;
    if (argc == 2)
    {
        s = argv[1];
        while(s[i])
        {
            repeat_alpha(s[i]);
            i++;
        }
    }
    write(1,"\n",1);
return (0);
}