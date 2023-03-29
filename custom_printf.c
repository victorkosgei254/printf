#include <stdlib.h>
#include "main.h"
#include <stdarg.h>

int getArgCount(char *s)
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
int printf(char *s, ...)
{
    int arg_count;
    char *s_copy;
    va_list ap;

    arg_count = getArgCount(s);
    va_start(ap,arg_count);
    s_copy = s;
    while (*s_copy != '\0')
    {
        if (*s_copy == '%')
        {
            s_copy++;
           switch (*s_copy) {
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
                       printf("Invalid argument");
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
int main(void)
{
    printf("Hello there %s and %d plus %c","String is here",-98,'V');

    return (0);
}
