#include <stdio.h>

struct Decimal
{
int a;
int b;
};

int cmp (struct Decimal d1, struct Decimal d2)
{
d1.a *= d2.b;
d2.a *= d1.b;

if (d1.a > d2.a)
return 1;
if (d1.a < d2.a)
return -1;

return 0;
}

int main ()
{
struct Decimal d1, d2;

scanf ("%d/%d", &d1.a, &d1.b);
scanf ("%d/%d", &d2.a, &d2.b);

int result = cmp (d1, d2);

printf ("%d\n", result);

return 0;
}
