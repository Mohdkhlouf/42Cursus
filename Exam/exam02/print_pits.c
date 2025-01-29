#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{

if(argc == 2)
{
    int i;
    char d;
    unsigned char bit;

    i = 8;
    bit = 0;
    while (i > 0)
    {
        d = argv[1][0];
        bit = (d >> i & 1) + 48 ;
        printf("%c",bit);
        i--;
    }
    

    
}
return (0);
}