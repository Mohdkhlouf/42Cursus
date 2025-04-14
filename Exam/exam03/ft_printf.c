#include <unistd.h>
#include <stdarg.h>



int ft_printf(const char *str, ... )
{
int counter;
int i;
va_list arguments;

i = 0;
va_start(arguments,str);
counter  = 0;
while (str[i] || str[i+1])

va_end(arguments);
return (counter);
}