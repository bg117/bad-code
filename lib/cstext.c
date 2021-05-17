#include <cstext.h>
#include <stdarg.h>
#include <stdio.h>

Function(NoReturn, __Out, NoChange String fmt, ...)
    va_list arg;
    va_start(arg, fmt);

    vfprintf(stdout, fmt, arg);

    va_end(arg);
EndFunction

Function(NoReturn, __OutErr, NoChange String fmt, ...) 
    va_list arg;
    va_start(arg, fmt);

    vfprintf(stderr, fmt, arg);

    va_end(arg);
EndFunction

Function(NoReturn, __In, NoChange String fmt, ...)
    va_list arg;
    va_start(arg, fmt);

    vfscanf(stdin, fmt, arg);

    va_end(arg);
EndFunction