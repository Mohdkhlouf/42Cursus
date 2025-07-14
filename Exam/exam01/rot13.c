#include <unistd.h>

void rot13(char c)
{
    int x;
    if (!(c >= 97 && c <= 122) && !(c >= 65 && c <= 90))
        write(1,&c,1);
    else
    {
        if (c >= 'A' && c <= 'M')
            c = c + 13;
        else if (c >= 'N' && c <= 'Z')
            c = c - 13;
        else if (c >= 'a' && c <= 'm')
            c = c + 13;
        else if (c >= 'n' && c <= 'z')
            c = c - 13;
        write(1,&c,1);
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
        while (s[i])
        {
            rot13(s[i]);
            i++;
        }
    }
    write(1,"\n",1);
return (0);
}