#include <stdio.h>
typedef struct fraction {
    int a;
    int b;
} fraction;
int func(int a, int b) {
    if (!b) return a;
    return func(b, a % b);
}
fraction simplify(fraction f) {
    int nod = func(f.a, f.b);
    f.a /= nod;
    f.b /= nod;
    return f;
}
fraction mulf(fraction f1, fraction f2) {
    fraction f;
    f.a = f1.a * f2.a, f.b = f1.b * f2.b;
    return simplify(f);
}
fraction divf(fraction f1, fraction f2) {
    fraction f;
    f.a = f1.a * f2.b, f.b = f1.b * f2.a;
    return simplify(f);
}
int main() {
    fraction f1 = { 4, 5 }, f2 = { 3, 2 }, f3, f4;
    f3 = mulf(f1, f2);
    f4 = divf(f1, f2);
    printf("mul: %d/%d\ndiv: %d/%d", f3.a, f3.b, f4.a, f4.b);
    return 0;
}