#include <unistd.h>



int is_space(char c)
{
    if(c == 9 || c == 32)
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    int i;
    char letter;
    int word;
    
    i = 0;
    word = 1;
    if (argc != 2 || !argv[1])
        write(1," ",1);
    else
    {
        while (is_space(argv[1][i]))         
                i++;
        while (!is_space(argv[1][i]) && argv[1][i])
            {
                letter = argv[1][i];
                write(1,&letter, 1);
                i++;
            }                
    }
    write(1,"\n",1);
    return (0);
}