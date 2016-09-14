#ifndef DEFS_H
#define DEFS_H

#define PRINT1(x) printf("%d\n", x);

#define PRINT2(x,y) printf("%d %d\n", x, y);

#define MAX2(x,y) (x > y ? x : y)

#define MAX3(x,y,z) (z >MAX2(x,y)) ? z : MAX2(x,y)

#endif
