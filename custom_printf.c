#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

int getArgCount(const char *s)
{
    int arg_count;
    
    arg_count = 0;
    while (*s != '\0')
    {
        if (*s == '%')
        {
            arg_count++;
        }
        s++;
    }
    return (arg_count);
}
void printNum(int x)
{
    int newNum;
    
    if (x < 0)
    {
        x = x * -1;
        _putchar('-');
    }
    newNum = (x - x % 10) / 10;
    if (newNum!= 0)
    {
        printNum(newNum);
    }
        _putchar(x % 10 + '0');
}
int _printf(const char *format, ...)
{
    int arg_count;
    const char *s_copy;
    va_list ap;

    arg_count = getArgCount(format);
    va_start(ap,arg_count);
    s_copy = format;
    while (*s_copy != '\0')
    {
        if (*s_copy == '%')
        {
            s_copy++;
           switch (*s_copy) {
               case 'i':
               case 'd':
                   {
                       printNum(va_arg(ap, int));
                       s_copy++;
                       break;
                   }
               case 's':
                   {
                       const char *ar = va_arg(ap, const char *);
                       while (*ar != '\0')
                       {
                           _putchar(*ar);
                           ar++;
                       }
                       s_copy++;
                       break;
                   }
               case 'c':
                   {
                       _putchar(va_arg(ap, int));
                       s_copy++;
                       break;
                   }
                default:
                   {
                       _printf("Invalid argument");
                       exit(98);
                   }
           } 
        }
        else
        {
            _putchar(*s_copy);
            s_copy++;
        }
    }
    va_end(ap);
    _putchar('\n');
    return (0);
}
