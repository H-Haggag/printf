This a customized printf project done by Hossam Abo Elhagga and NohaZak

A function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
d
i
b
u
o
x
X
S
p
+
space
#
l
h
0
field width
presicion
-
r
R
