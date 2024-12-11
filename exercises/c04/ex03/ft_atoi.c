#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *str)
{
    int result;
    int sign_flag;
    
    result = 0;
    sign_flag = 1;    
    while(*str == ' ' || *str >= '\t' && *str <= '\r')
            str++;
    while (*str == '-' || *str == '+')
        {
          if(*str == '-')
          {
            sign_flag = -1 * sign_flag;
            str++;
          }
          else
            str++;
        }

    while (*str >= '0' && *str <= '9')
        {
            result = result * 10 + (*str - '0');
            str++;
        }
    return(result * sign_flag);
}

int main(void)
{
    char str[]=" ---+--+1234ab567";
    printf("%d",ft_atoi(str));
    return (0);

}
