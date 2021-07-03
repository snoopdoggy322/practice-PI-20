#include <stdio.h>
#include <stdlib.h>
#include <time.h>

///Вариант 9 - Задание 4
///Даны два числа в двоичной записи в 500 знаков каждое. Необходимо выполнить операцию побитового И.

void binaryMultiplication(int n){

    char num1[n], num2[n], num3[n];
    unsigned x, y;
    srand(time(NULL));

    for (int i = 0; i < n; ++i) {
        x = rand() % 2;
        y = rand() % 2;
        num1[i] = '0' + x;
        num2[i] = '0' + y;
        num3[i] = '0' + (x & y);
    }

    num1[n - 1] = num2[n - 1] = num3[n - 1] = '\0';

    printf("%s\n%s\n%s", num1, num2, num3);
}

int main() {
    int n;
    printf("\nВведите жалаемое количество знаков для операнда: ");
    scanf("%d", &n);
    binaryMultiplication(n+1);
    return 0;
}
