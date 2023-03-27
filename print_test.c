 #include <stdarg.h>
 /**
  * _printf - returns number of charaters printed
  * @format: is a character string
  * Return: count
  */


int my_printf(const char *format, ...)
{
    int count = 0, i = 0;
    va_list args;
    va_start(args, format);

    while (*format || format[i] != '\0')
    {
        if (*format == '%') //checking if format is a format specifier
        {
            ++format; //move past format
            switch (*format)
            {
                case 's' :
                    {
                        char *str = va_arg(args, char*);
                        while (*str != '\0')
                        {
                            putchar(*str);
                            str++;
                            ++count;
                        }
                        break;
                    }
                case 'c' :
                    {
                        char val = (char) va_arg(args, int); //gets turned to an int
                        putchar(val);
                        ++count;
                    }
                    break;
                case 'd':
            {
               int num = va_arg(args, int);
               if (num < 0) {
               putchar('-');
               num = -num;
                }
                if (num == 0)
                {
                    putchar('0');
                }
                else {
                    int digits[10];
                    int index = 0;
                    while (num > 0)
                    {
                        digits[index++] = num % 10;
                        num /= 10;
                    }
                    while (index-- > 0)
                    {
                        putchar(digits[index] + '0');
                        ++count;
                    }
                }
                break;
                    }
                }
        }
        else
        {
            putchar(*format);
            ++count;
        }
        ++format;
    }
    va_end(args);

    return (count);
}
